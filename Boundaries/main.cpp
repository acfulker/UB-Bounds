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
    while(sect != nullptr){//sector
        std::vector<Zone> sectV;
        while(zone != nullptr){//zone
            int points=zone->IntAttribute("size");
            std::vector<float> latitudes(points), longitudes(points);
            int i=0;
            while(point != nullptr){//point
                latitudes[i]=point->FloatAttribute("lat");
                longitudes[i]=point->FloatAttribute("long");
                std::cout << latitudes[i] << ", " << longitudes[i] << std::endl;
                i++;
                point=point->NextSiblingElement("point");
            }
            Zone *z = new Zone(latitudes, longitudes, points);
            sectV.push_back(*z);
            zone=zone->NextSiblingElement();
            if(zone == nullptr) break;
            point = zone->FirstChildElement("point");
            if (point == nullptr) return XML_ERROR_PARSING_ELEMENT;
            
        }
        wV.push_back(sectV);
        sect=sect->NextSiblingElement("sector");
        if(sect == nullptr) break;
        zone = sect->FirstChildElement("zone");
        if (zone == nullptr) return XML_ERROR_PARSING_ELEMENT;
    }
    
    //w = new World(wV);
    doc.Print();
    return 0;
}

int main(){
    return setup();
}