//
// Created by Andrew Fulkerson on 10/11/18.
//

#ifndef BOUNDARIES_AGENT_H
#define BOUNDARIES_AGENT_H

#include "Coord.h"
#include "Line.h"


class Agent {
private:

public:
    Coord loc;
    double lat, lon;
    double bear;
    
    Agent();
    Agent(Coord &coord, int bearing);
    Coord nearestPoint2Line(Line l);
    
};


#endif //BOUNDARIES_AGENT_H
