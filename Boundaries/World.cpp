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
std::queue<Box::Box> World::Near(Agent a){
    double d;
    std::queue<Box::Box> *near = new std::queue;
    for(Box::Box i : boxes){
        d=i.getDist(a);
        if(d==0){//in no fly zone
        
        }
        else if(d<=range){//Within range of zone
            near->push(i);
        }
    }
}
