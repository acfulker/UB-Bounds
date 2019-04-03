//
// Created by Andrew Fulkerson on 10/11/18.
//

#ifndef BOUNDARIES_WORLD_H
#define BOUNDARIES_WORLD_H


#include <queue>
#include "Zone.h"
#include "Agent.h"

class World {
private:
    const double THRESHOLD = 0.5;

public:

    std::vector<Zone> sectorList;
    std::vector<std::vector<Zone>> worldList;
    World(std::vector<std::vector<Zone>> &world, std::vector<Zone> &sectList) : worldList(world), sectorList(sectList) {};
    World(const World &other);
    ~World();

    bool canFly(Agent &a);
    Coord nearBound(Agent &a); //similar to canFly
    Coord makeNew(Agent &a, Coord nearest);
    double angleBetween(double b1, double b2);

    double cosDeg(double deg);
    //double sinDeg(double deg);
};



#endif //BOUNDARIES_WORLD_H
