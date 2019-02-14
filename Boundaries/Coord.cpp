//
// Created by Andrew Fulkerson on 10/22/18.
//

#include "Coord.h"

/**
 *
 * @param other
 * @return ~ distance in feet
 */
double Coord::distanceTo(Coord &other){
    double tempx, tempy, c, dist=0;

    
    tempx=abs(longitude-other.longitude);
    tempy=abs(latitude-other.latitude);
    
    c=sqrt(tempx*tempx + tempy*tempy);
    
    dist = c*(100/.0003);
    return dist;
}

/**
 *
 * @param other
 * @return midpoint between other and this
 */
Coord Coord::midpoint(Coord &other){
    double x = (other.longitude - longitude)/2;
    double y = (other.latitude   - latitude)/2;
    return Coord(latitude+y, longitude+x);
}