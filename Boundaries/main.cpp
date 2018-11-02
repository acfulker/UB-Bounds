#include <iostream>
#include "Agent.h"
#include "Box.h"
#include "World.h"

void setup();
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
int gPass = 0;
int gFail = 0;


bool XMLTest (const char* testString, const char* expected, const char* found, bool echo=true, bool extraNL=false )
{
    bool pass;
    if ( !expected && !found )
        pass = true;
    else if ( !expected || !found )
        pass = false;
    else
        pass = !strcmp( expected, found );
    if ( pass )
        printf ("[pass]");
    else
        printf ("[fail]");
    
    if ( !echo ) {
        printf (" %s\n", testString);
    }
    else {
        if ( extraNL ) {
            printf( " %s\n", testString );
            printf( "%s\n", expected );
            printf( "%s\n", found );
        }
        else {
            printf (" %s [%s][%s]\n", testString, expected, found);
        }
    }
    
    if ( pass )
        ++gPass;
    else
        ++gFail;
    return pass;
}

bool XMLTest(const char* testString, XMLError expected, XMLError found, bool echo = true, bool extraNL = false)
{
    return XMLTest(testString, XMLDocument::ErrorIDToName(expected), XMLDocument::ErrorIDToName(found), echo, extraNL);
}

bool XMLTest(const char* testString, bool expected, bool found, bool echo = true, bool extraNL = false)
{
    return XMLTest(testString, expected ? "true" : "false", found ? "true" : "false", echo, extraNL);
}

template< class T > bool XMLTest( const char* testString, T expected, T found, bool echo=true )
{
    bool pass = ( expected == found );
    if ( pass )
        printf ("[pass]");
    else
        printf ("[fail]");
    
    if ( !echo )
        printf (" %s\n", testString);
    else
        printf (" %s [%d][%d]\n", testString, static_cast<int>(expected), static_cast<int>(found) );
    
    if ( pass )
        ++gPass;
    else
        ++gFail;
    return pass;
}


void NullLineEndings( char* p )
{
    while( p && *p ) {
        if ( *p == '\n' || *p == '\r' ) {
            *p = 0;
            return;
        }
        ++p;
    }
}

void setup() {
    XMLDocument doc;
    doc.LoadFile( "boxes.xml" );
    
    doc.Print();
    
}

int main(){

}