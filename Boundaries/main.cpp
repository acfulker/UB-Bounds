/*
 *  Andrew Fulkerson and Anna Sholk
 *  May 2019
 */



#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Agent.h"
#include "World.h"
#include "Zone.h"
#include "json.hpp"
#include "tinyxml2.h"
#include "tinyxml2.cpp"

World* setupDB();
int setupSock();
Coord packetRec(World* w, Agent* a);
Agent depacketize(std::string pdu);
double toDouble(std::string str);
std::string packetize(double latitude, double longitude);

#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

using json = nlohmann::json;
using namespace tinyxml2;
using namespace std;

World *w;

World* setupDB() {
    XMLDocument doc;
    doc.LoadFile("boxes.xml");

    XMLNode * region = doc.FirstChild();
    if (region == nullptr) throw XML_ERROR_FILE_READ_ERROR;
    XMLElement * sect = region->FirstChildElement("sector");
    if (sect == nullptr) throw XML_ERROR_PARSING_ELEMENT;
    XMLElement * zone = sect->FirstChildElement("zone");
    if (zone == nullptr) throw XML_ERROR_PARSING_ELEMENT;
    XMLElement * point = zone->FirstChildElement("point");
    if (point == nullptr) throw XML_ERROR_PARSING_ELEMENT;
    std::vector<std::vector<Zone>> wV;
    std::vector<Zone> sectList;//list of sectors as Zone objects
    while(sect != nullptr){//sector
        std::vector<Zone> zoneList;//list of zone objects in this sector

        //build this sector's Zone
        std::vector<double> sLatitudes(4), sLongitudes(4);
        double n, s, e, w;
        n=sect->DoubleAttribute("north");
        s=sect->DoubleAttribute("south");
        e=sect->DoubleAttribute("east");
        w=sect->DoubleAttribute("west");
        sLatitudes[0]=n;
        sLatitudes[1]=n;
        sLatitudes[2]=s;
        sLatitudes[3]=s;
        sLongitudes[0]=w;
        sLongitudes[1]=e;
        sLongitudes[2]=e;
        sLongitudes[3]=w;
        Zone *z = new Zone(sLatitudes, sLongitudes, 4);
        sectList.push_back(*z);


        while(zone != nullptr){//zone
            int points=zone->IntAttribute("size");
            std::vector<double> latitudes(points), longitudes(points);
            int i=0;
            while(point != nullptr){//point
                latitudes[i]=point->DoubleAttribute("lat");//add point lat
                longitudes[i]=point->DoubleAttribute("long");//add point lon
                //std::cout << latitudes[i] << ", " << longitudes[i] << std::endl;//print for testing
                i++;
                point=point->NextSiblingElement("point");
            }

            Zone *z = new Zone(latitudes, longitudes, points);
            z->edgeList();
            zoneList.push_back(*z);
            zone=zone->NextSiblingElement();
            if(zone == nullptr) break;//check if last zone
            point = zone->FirstChildElement("point");
            if (point == nullptr) throw XML_ERROR_PARSING_ELEMENT;

        }
        wV.push_back(zoneList);
        sect=sect->NextSiblingElement("sector");
        if(sect == nullptr) break;//check if last sector
        zone = sect->FirstChildElement("zone");
        if (zone == nullptr) throw XML_ERROR_PARSING_ELEMENT;
    }

    World* w = new World(wV, sectList);
    //doc.Print();
    return w;
}

int setupSock(){
    int sock = socket(AF_INET, SOCK_STREAM, 0); //domain IPv4, type, protocol
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(2662);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //bind socket to port and address
    bind(sock,(struct sockaddr*)&serverAddr, sizeof(struct sockaddr));
    std::cout << serverAddr.sin_addr.s_addr << std::endl;
    return sock;
}

Coord packetRec(World* w, Agent* a){
    bool fly = w->canFly(*a);
    std::cout << "Can fly?: " << fly << std::endl;

    if (fly) {
        Coord react = w->nearBound(*a);
        Coord destination;
        std::cout << "Continue?: " << react.null << std::endl;
        if (!react.null) {
            destination = w->makeNew(*a, react);
            Agent checkA = Agent(destination, a->loc.bearingTo(destination));
            if (w->canFly(checkA)) {
                Coord react2 = w->nearBound(checkA);
                if (!react2.null) {
                    destination = w->makeNew(checkA, react2);
                    checkA = Agent(destination, checkA.loc.bearingTo(destination));
                    if (!w->canFly(checkA)) {
                        destination = a->loc;
                    } //if no fly zone, send to original location
                    else {
                        react2 = w->nearBound(checkA);
                        if (!react2.null) {
                            destination = a->loc;
                        } // if still near bound, send original location
                    } //check 2nd poss. destination
                } // check possible destination near bound
            } // check possible location can fly
            else {
                destination = a->loc;
            } //check if poss. location no fly
            std::cout << "Location: " << destination.latitude << "  " << destination.longitude << std::endl;
        }
        else {
            return react;
        }

        return destination;
    }
    return Coord(true);
}

Agent depacketize(std::string pdu){
    std::string inlat = pdu.substr(0,18); //set input latitude to first 10 payload values
    std::string inlon = pdu.substr(18,18); //set input longitude to second set from payload
    std::string inbear = pdu.substr(36,6); //set input bearing to last payload values
    Coord loc = Coord(toDouble(inlat), toDouble(inlon));
    Agent a = Agent(loc, toDouble(inbear));
    return a;
}

string packetize(double latitude, double longitude){
    string lat = to_string(latitude);
    if(lat[0] != '-'){
        lat = '0'+lat;
    }
    lat+="0000000000";
    lat=lat.substr(0, 9);

    string lon = to_string(longitude);
    if(lon[0] != '-'){
        lon = '0'+lon;
    }
    lon+="0000000000";
    lon=lon.substr(0, 9);

    string outstr = "01"+lon+lat;
    return outstr;
}

double toDouble(std::string str){
    int len = str.length();
    std::string newString;
    for(int i=0; i< len; i+=2)
    {
        string byte = str.substr(i,2);
        char chr = (char) (int)strtol(byte.c_str(), nullptr, 16);
        newString.push_back(chr);
    }
    double d = 0.0;
    ::sscanf(newString.c_str(), "%lA", &d);
    return d;
}

int main(){
    int clientSock, n;
    Agent a;
    Coord dest;
    string output;
    World* w = setupDB();
    int sock = setupSock();
    listen(sock,10); //socket,backlog
    char buffer[256];
    bzero(buffer,256);
    sockaddr_in clientAddr;
    socklen_t sin_size = sizeof(struct sockaddr_in);
    while(true) {
        clientSock = accept(sock,(struct sockaddr*)&clientAddr, &sin_size);
        n = read(clientSock, buffer, 500);
//        cout << n << endl << buffer << endl;
        auto packet = json::parse(buffer);
        cout << packet["pdu"] << endl;
        a = depacketize(packet["pdu"].get<std::string>());
        cout << a.lat << endl << a.lon << endl;
        dest = packetRec(w, &a);
        if(!w->canFly(a)){
            output = "0000000000000000000000";
        }
        else{
            output = packetize(dest.latitude, dest.longitude);
        }

        int w = write(clientSock,output.c_str(),strlen(output.c_str())+1);
        bzero(buffer,256);
    }
    return 0;

}
