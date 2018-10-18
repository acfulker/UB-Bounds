//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "World.h"


World::World::World(){}
World::World(list boxes){}
World::World(const World &other){}
World::~World(){}
/**
 *
 * @param a
 * @return prioritized list of all bounds within DISTANCE_OF_IRRELEVANCE;
 */
std::priority_queue<Box::Box> World::Near(Agent a){
    std::priority_queue<Box::Box> near = new Std::priority_queue;
    for(Box::Box i : boxes){
        if(i.isNear(a)){
            near.push(i);
        }
    }
}
