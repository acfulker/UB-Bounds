//
// Created by Andrew Fulkerson on 10/22/18.
//

#include "Coord.h"
#include <math.h>

/**
 *
 * @param other
 * @return ~ distance in feet
 */
double distanceTo(Coord &other){
    double tempx, tempy, c, dist=0;
    
    tempx=abs(lon-other.lon);
    tempy=abs(lat-other.lat);
    
    c=sqrt(tempx*tempx + tempy*tempy);
    
    dist = c(100/.0003);
    return dist;
}