//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "World.h"

World::World(const World &other){}
World::~World(){}

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
bool World::takeAction(Agent &a){
    int j = -1;
    for (int i=0; i < sectorList.size(); i++){
        if (sectorList[i].inZone(a)){
            j=i;
            break;
        }//if
    }//for
    if (j==-1){
        return false;
    }//if

    Coord nearest;
    double shortest = 1000000;
    for (int i=0; i < worldList[j].size(); i++){
        for (int m=0; m < worldList[j][i].polyCorners-1; m++){
            Coord n = a.nearestPoint2Line(worldList[j][i].edges[m]);
            double ndist = a.loc.distanceTo(n);
            if (ndist < shortest){
                shortest = ndist;
                nearest = n;
            }//end if
        }//end for m
    }//end for i
    if (shortest <= THRESHOLD) {
        return true;
    }
    return false;

}