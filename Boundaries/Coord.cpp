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

/**
 *
 * @param other
 * @return bearing to coordinate
 * Used in makeNew function
 */
double Coord::bearingTo(Coord &other){
    double x = other.longitude-longitude;
    double y = other.latitude-latitude;
    return atan(x/y);
}
/**
 *
 * @param dist
 * @param bearing
 * @return point at bearing and distance
 */
Coord Coord::pointAt(double dist, double bearing){
    double ref = fmod(bearing, 90.0);
    Coord p(*this);
    //dist to degrees units
    bearing = normalizeB(bearing);
    if (bearing>=0&&bearing<90) {
       p.latitude+=dist*cos(ref);
       p.longitude+=dist*sin(ref);
    } else if(bearing>=90&&bearing<180){
        p.latitude-=dist*sin(ref);
        p.longitude+=dist*cos(ref);
    } else if (bearing>=180&&bearing<270){
        p.latitude-=dist*cos(ref);
        p.longitude-=dist*sin(ref);
    } else {
        p.latitude+=dist*sin(ref);
        p.longitude-=dist*cos(ref);
    }
    return p;
}
/**
 *
 * @param bearing
 * @return bearing in range (0,360]
 */
double Coord::normalizeB(double bearing){
    if (bearing>360){
        return bearing-360;
    } else if (bearing<=0){
        return bearing+360;
    }
    return bearing;
}