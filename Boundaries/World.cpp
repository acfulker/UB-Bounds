//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "World.h"
#include "Coord.h"
#include <math.h>
World::World(const World &other){}
World::~World(){}

#define PI 3.14159265358979

double World::cosDeg(double deg){
    return cos(deg*(PI/180));
}
//double World::sinDeg(double deg){
//    return sin(deg*(PI/180));
//}
/**
 *
 * @param a
 * @return false if within no fly zone
 */
bool World::canFly(Agent &a) {
    int j = -1;
    for (int i=0; i < sectorList.size(); i++){
        if (sectorList[i].inZone(a)){
            j=i;
            break;
        }//if
    }//for
    if (j == -1) {
        return true;
    }//if
    for (int i=0; i < worldList[j].size(); i++){
        if (worldList[j][i].inZone(a)){
           return false;
        }//if
    }//for

    return true;
};


/**
 *
 * @param a
 * @return false for continue (no boundary nearby)
 */
Coord World::nearBound(Agent &a){
    int j = -1;
    for (int i=0; i < sectorList.size(); i++){
        if (sectorList[i].inZone(a)){
            j=i;
            break;
        }//if
    }//for
    if (j==-1){
        return Coord(true);
    }//if

    Coord nearest;
    double shortest = 1000000;
    for (int i=0; i < worldList[j].size(); i++){
        for (int m=0; m < worldList[j][i].polyCorners; m++){
            Coord n = a.nearestPoint2Line(worldList[j][i].edges[m]);
            double ndist = a.loc.distanceTo(n);
            if (ndist < shortest){
                shortest = ndist;
                nearest = n;
            }//end if
        }//end for m
    }//end for i
    if (shortest <= THRESHOLD) {
        return nearest;
    }
    return Coord(true);

}
/**
 *
 * @param a agent object
 * @param nearest coordinate of nearest point on nearest bound
 * @return new coordinate to travel to
 */
Coord World::makeNew(Agent &a, Coord nearest){
    double dist = a.loc.distanceTo(nearest);
    double bearingToBound = a.loc.bearingTo(nearest);
    double leftRight = angleBetween(bearingToBound,a.bear);
    if (leftRight==0) {
        return a.loc;
    }
    double theta = abs(leftRight);
    double dPath = dist/cosDeg(theta);
    double dToNew = cosDeg(90-theta)*dPath;
    double bToNew;
    if (leftRight>0) {
        bToNew = bearingToBound+90;
    } else {
        bToNew = bearingToBound-90;
    }
    bToNew = nearest.normalizeB(bToNew);

    return a.loc.pointAt(dToNew, bToNew);
}



/**
 *
 * @param b1
 * @param b2
 * @return relative angle from b1 to b2
 */
double World::angleBetween(double b1, double b2){
    Coord c;
    b1 = c.normalizeB(b1);
    b2 = c.normalizeB(b2);
    double a1 = b2-b1;
    if (abs(a1)<=180){
        return a1;
    } else {
        return 360-a1;
    }
}
