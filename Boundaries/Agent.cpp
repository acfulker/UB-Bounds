//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "Agent.h"

Agent::Agent(){
    loc = Coord::Coord();
    lat = 0;
    lon = 0;
}

Agent::Agent(Coord coord) {
    lat = coord.latitude();
    lon = coord.longitude();
}

Agent::~Agent() {
    delete loc;
}

