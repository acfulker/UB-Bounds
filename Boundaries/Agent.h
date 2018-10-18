//
// Created by Andrew Fulkerson on 10/11/18.
//

#ifndef BOUNDARIES_AGENT_H
#define BOUNDARIES_AGENT_H

#include "QGeoCoordinate.h"
#include "Box.h"
#include "World.h"

class Agent {
private:

public:
    QGeoCoordinate loc;
    double lat, lon;
    
    Agent();
    ~Agent();
    Agent(QGeoCoordinate coord) : loc(coord) {};
    
    
    
};


#endif //BOUNDARIES_AGENT_H
