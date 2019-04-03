#include <iostream>
#include "Agent.h"
#include "World.h"
#include "Zone.h"
#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector>
#include <stdio.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
//#include <unistd.h>
//#include <arpa/inet.h>

World* setupDB();
//int setupSOCKET();
Coord packetRec(World* w);
#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

using namespace tinyxml2;
using namespace std;

//World *w;

World* setupDB() {
    XMLDocument doc;
    doc.LoadFile("testing.xml");
    
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
//
//int setupSOCKET(){
//    int sock = socket(AF_INET, SOCK_STREAM, 0); //AF_INET for IPv4, SOCK_STREAM for TCP, 0 for any protocol
//    sockaddr_in serverAddr;
//    serverAddr.sin_family = AF_INET;
//    serverAddr.sin_port = SERVER_PORT;
//    serverAddr.sin_addr.s_addr = INADDR_ANY;
//    /**
//     * bind socket to port and address
//     */
//
//    bind(sock, (struct sockaddr*)&serverAddr, size(struct sockaddr));
//}

Coord packetRec(World* w){
    Coord c = Coord(-.75,-3);
    Agent a = Agent(c, 135);
    bool fly = w->canFly(a);
    std::cout << "Can fly?: " << fly << std::endl;

    if (fly) {
        Coord react = w->nearBound(a);
        Coord destination;
        std::cout << "Continue?: " << react.null << std::endl;
        if (!react.null) {
            destination = w->makeNew(a, react);
            Agent checkA = Agent(destination, a.loc.bearingTo(destination));
            if (w->canFly(checkA)) {
                Coord react2 = w->nearBound(checkA);
                if (!react2.null) {
                    destination = w->makeNew(checkA, react2);
                    checkA = Agent(destination, checkA.loc.bearingTo(destination));
                    if (!w->canFly(checkA)) {
                        destination = a.loc;
                    } //if no fly zone, send to original location
                    else {
                        react2 = w->nearBound(checkA);
                        if (!react2.null) {
                            destination = a.loc;
                        } // if still near bound, send original location
                    } //check 2nd poss. destination
                } // check possible destination near bound
            } // check possible location can fly
            else {
                destination = a.loc;
            } //check if poss. location no fly
            std:
            cout << "Location: " << destination.latitude << "  " << destination.longitude << std::endl;
        }

        return destination;
    }
    return false;
}

int main(){
    World* w = setupDB();
    packetRec(w);
//    setupSOCKET();
//    while(true) {
//        int buffer, sock;//
//        bzero(buffer, 1);//what is this
//        sockaddr_in clientAddr;
//        socklen_t sin_size = size(
//        struct sockaddr_in);
//        int clientSock = accept(sock, (struct sockaddr *) &clientAddr, &sin_size);
//        while (true) {
//            //receive packet
//            int n = read(clientSock, buffer, 500) //why 500?
//            cout << n << endl << buffer << endl;
//        }
//    }

    return 0;
}