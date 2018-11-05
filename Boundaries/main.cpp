#include <iostream>
#include "Agent.h"
#include "Box.h"
#include "World.h"

int setup();
#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>


#include <sys/stat.h>
#include <sys/types.h>


using namespace tinyxml2;
using namespace std;

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
    
    while(sect != nullptr){
        while(zone != nullptr){
            while(point != nullptr){
            
            }
        }
    }
    
    
    doc.Print();
    
}

int main(){
    setup();
}