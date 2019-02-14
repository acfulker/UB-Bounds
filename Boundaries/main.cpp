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

int setup();
Coord nearestPoin2Line(Coord drone,Coord ep1,Coord ep2);
#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

using namespace tinyxml2;
using namespace std;

World *w;

int setup() {
    XMLDocument doc;
    doc.LoadFile( "boxes.xml" );
    
    XMLNode * region = doc.FirstChild();
    if (region == nullptr) return XML_ERROR_FILE_READ_ERROR;
    XMLElement * sect = region->FirstChildElement("sector");
    if (sect == nullptr) return XML_ERROR_PARSING_ELEMENT;
    XMLElement * zone = sect->FirstChildElement("zone");
    if (zone == nullptr) return XML_ERROR_PARSING_ELEMENT;
    XMLElement * point = zone->FirstChildElement("point");
    if (point == nullptr) return XML_ERROR_PARSING_ELEMENT;
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
            zoneList.push_back(*z);
            zone=zone->NextSiblingElement();
            if(zone == nullptr) break;//check if last zone
            point = zone->FirstChildElement("point");
            if (point == nullptr) return XML_ERROR_PARSING_ELEMENT;
            
        }
        wV.push_back(zoneList);
        sect=sect->NextSiblingElement("sector");
        if(sect == nullptr) break;//check if last sector
        zone = sect->FirstChildElement("zone");
        if (zone == nullptr) return XML_ERROR_PARSING_ELEMENT;
    }
    
    w = new World(wV, sectList);
    //doc.Print();
    return 0;
}

/**
 *
 * @param drone, ep1, ep2
 * @return the closest point on a line to the drone
**/
Coord nearestPoint2Line(Coord drone,Coord ep1,Coord ep2){
    double threshold;
    Coord p1 = ep1, p2 = ep2;
    double d1 = drone.distanceTo(p1), d2 = drone.distanceTo(p2);
    double diff = abs(d1-d2); //make sure abs function works
    while(diff>threshold){
        if(d1>d2){
            p1 = p1.midpoint(p2); //create function
            d1 = drone.distanceTo(p1);
        }
        else{
            p2 = p2.midpoint(p1);
            d2 = drone.distanceTo(p2);
        }
        diff = abs(d1-d2);
    }
    return p1.midpoint(p2);
}


int main(){
    setup();
    Coord c = Coord(41.003, -78.781);
    Agent a = Agent(c);
    bool fly = w->canFly(a);
    std::cout << fly << std::endl;
    return 0;
}