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
    XMLElement * zone = region->FirstChildElement("zone");
    if (zone == nullptr) return XML_ERROR_PARSING_ELEMENT;
    XMLElement * point = region->FirstChildElement("point");
    if (point == nullptr) return XML_ERROR_PARSING_ELEMENT;
    std::vector<std::vector<Zone>> wV = new std::vector;
    while(sect != nullptr){//sector
        std::vector<Zone> sectV = new std::vector;
        while(zone != nullptr){//zone
            int points=zone->IntAttribute("size");
            float *latitudes = new float[points];
            float *longitudes = new float[points];
            int i=0;
            while(point != nullptr){//point
                latitudes[i]=point->FloatAttribute("latitude");
                longitudes[i]=point->FloatAttribute("longitude");
                if(i==points)//error
                i++;
                point=point->NextSiblingElement("point");
            }
            Zone *z = new Zone(latitudes, longitudes, points)
            sectV.push_back(z);
            zone=zone->NextSiblingElement("zone");
        }
        sect=sect->NextSiblingElement("sector");
        wV.push_back(sectV);
    }
    
    w = new World(wV);
    doc.Print();
    
}

int main(){
    setup();
}