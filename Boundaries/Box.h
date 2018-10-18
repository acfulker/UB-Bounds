//
// Created by Andrew Fulkerson on 8/6/18.
//

#ifndef BOUNDARIES_BOX_H
#define BOUNDARIES_BOX_H

#include "QGeoCoordinate.h"
#define DISTANCE_OF_IRRELEVANCE = 50;

class Box {
private:
    //These should be the same data
    double north, south, east, west;//Boundaries in latitude and longitude
    QGeoCoordinate nw, ne, se, sw, n, s, e ,w;//Boundary corners as QGC
    double borderDistance;
    double threshold;
    double dist;
    
public:
    Box();
    Box(QGeoCoordinate p1, QGeoCoordinate p2);
    Box(double north, double south, double east, double west);
    Box(const Box &other);
    ~Box();
    
    bool operator<(Box &other);
    bool isNear(Agent a);//Returns true if a is within approx. DISTANCE_OF_IRRELEVANCE from the bounding box
    
    
    QGeoCoordinate reflect(QGeoCoordinate loc, double bearing);//Returns a coordinate in the direction of reflection
    QGeoCoordinate reflect(Vehicle mav);
    
    bool Box::setCorner(QGeoCoordinate point);
    
    
    
    double getN();
    double getS();
    double getE();
    double getW();
    
    double getDist();
    
    QGeoCoordinate getNW();
    QGeoCoordinate getNE();
    QGeoCoordinate getSE();
    QGeoCoordinate getSW();
    
    void setDist(double d);
};


#endif //BOUNDARIES_BOX_H
