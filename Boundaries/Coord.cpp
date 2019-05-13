//
// Created by Andrew Fulkerson on 10/22/18.
//

#include "Coord.h"
#include <math.h>
#define PI 3.14159265358979

double Coord::cosDeg(double deg){
    return cos(deg*(PI/180));
}
double Coord::sinDeg(double deg){
    return sin(deg*(PI/180));
}

/**
 *
 * @param other
 * @return ~ distance, in feet
 */
double Coord::distanceTo(Coord &other) {
    double m1 = 111132.92;        // latitude calculation term 1
    double m2 = -559.82;        // latitude calculation term 2
    double m3 = 1.175;            // latitude calculation term 3
    double m4 = -0.0023;        // latitude calculation term 4
    double p1 = 111412.84;        // longitude calculation term 1
    double p2 = -93.5;            // longitude calculation term 2
    double p3 = 0.118;            // longitude calculation term 3

    double latlen = m1 + (m2 * cosDeg(latitude)) + (m3 * cosDeg(4 * latitude)) + (m4 * cosDeg(6 * latitude)); //to feet
    double longlen = (p1 * cosDeg(latitude)) + (p2 * cosDeg(3 * latitude)) + (p3 * cosDeg(5 * latitude));//to feet
    
    double tempx = abs(longitude - other.longitude) * longlen;
    double tempy = abs(latitude - other.latitude) * latlen;

    return sqrt(tempx * tempx + tempy * tempy);
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
 * @return bearing to coordinate with respect to north
 * Used in makeNew function
 */
double Coord::bearingTo(Coord &other){
    double x = other.longitude-longitude;
    double y = other.latitude-latitude;
    double phi = atan(y/x)*(180/PI);
    if (y<0){
        phi+=180;
    }

    return normalizeB(phi);
}
/**
 *
 * @param dist
 * @param bearing
 * @return point at bearing and distance
 */
Coord Coord::pointAt(double dist, double bearing){
    //dist = dist*(.0003/100);
    double ref = fmod(bearing, 90.0);
    Coord p(*this);
    //dist to degrees units
    bearing = normalizeB(bearing);
    if (bearing>=0&&bearing<90) {
       p.latitude+=dist*cosDeg(ref);
       p.longitude+=dist*sinDeg(ref);
    } else if(bearing>=90&&bearing<180){
        p.latitude-=dist*sinDeg(ref);
        p.longitude+=dist*cosDeg(ref);
    } else if (bearing>=180&&bearing<270){
        p.latitude-=dist*cosDeg(ref);
        p.longitude-=dist*sinDeg(ref);
    } else {
        p.latitude+=dist*sinDeg(ref);
        p.longitude-=dist*cosDeg(ref);
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