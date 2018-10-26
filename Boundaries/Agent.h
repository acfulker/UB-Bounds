//
// Created by Andrew Fulkerson on 10/11/18.
//

#ifndef BOUNDARIES_AGENT_H
#define BOUNDARIES_AGENT_H

#include "Coord.h"


class Agent {
private:

public:
    Coord loc;
    double lat, lon;
    
    Agent();
    explicit Agent(Coord &coord) : loc(coord) {};
    
};


#endif //BOUNDARIES_AGENT_H
