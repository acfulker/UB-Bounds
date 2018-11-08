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

public:

    std::vector<Zone> sectorList;
    std::vector<std::vector<Zone>> worldList;
    World(std::vector<std::vector<Zone>> &world, std::vector<Zone> &sectList) : worldList(world), sectorList(sectList) {};
    World(const World &other);
    ~World();

    bool canFly(Agent &a);
    std::vector<Zone> Near(Agent &a);//needs work
    
};



#endif //BOUNDARIES_WORLD_H
