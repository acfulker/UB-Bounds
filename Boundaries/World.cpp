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

std::vector<Zone> World::Near(Agent &a) {

};