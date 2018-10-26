//
// Created by Andrew Fulkerson on 8/6/18.
//

#ifndef BOUNDARIES_BOX_H
#define BOUNDARIES_BOX_H

#define DISTANCE_OF_IRRELEVANCE = 50;
#include "Coord.h"
#include "Agent.h"

class Box {
private:
    //These should be the same data
    double north, south, east, west;//Boundaries in latitude and longitude
    Coord nw, ne, se, sw;//Boundary corners as QGC
    
public:
    Box();
    Box(Coord p1, Coord p2);
    Box(double north, double south, double east, double west);
    Box(const Box &other);
    ~Box();

    double getDist(Agent& a);//Returns distance to box
    
    double getN();
    double getS();
    double getE();
    double getW();
    
    Coord getNW();
    Coord getNE();
    Coord getSE();
    Coord getSW();
};


#endif //BOUNDARIES_BOX_H
