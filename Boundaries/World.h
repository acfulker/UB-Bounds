//
// Created by Andrew Fulkerson on 10/11/18.
//

#ifndef BOUNDARIES_WORLD_H
#define BOUNDARIES_WORLD_H


#include <queue>
#include "Box.h"
#include "Agent.h"

class World {
private:
    list boxes;
public:
    World();
    World(list boxes);
    World(const World &other);
    ~World();
    
    std::priority_queue<Box::Box> Near(Agent a);
    bool add(Box::Box b);
    
};



#endif //BOUNDARIES_WORLD_H
