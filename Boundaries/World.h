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
    double range;
    std::vector<Zone> sectorList;
    World(std::vector<std::vector<Zone>> &world);
    World(const World &other);
    ~World();
    
    std::queue<Zone> Near(Agent &a);//needs work
    
};



#endif //BOUNDARIES_WORLD_H
