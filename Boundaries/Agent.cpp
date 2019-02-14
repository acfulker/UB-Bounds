//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "Agent.h"

Agent::Agent(){
    auto loc = Coord();
    lat = 0;
    lon = 0;
}
Agent::Agent(Coord &coord) {
    lat = coord.latitude;
    lon = coord.longitude;
}

/**
 *
 * @param ep1, ep2
 * @return the closest point on a line to the drone (loc)
**/
Coord Agent::nearestPoint2Line(Coord ep1,Coord ep2){
    double threshold;
    Coord p1 = ep1, p2 = ep2;
    double d1 = loc.distanceTo(p1), d2 = loc.distanceTo(p2);
    double diff = abs(d1-d2); //make sure abs function works
    while(diff>threshold){
        if(d1>d2){
            p1 = p1.midpoint(p2); 
            d1 = loc.distanceTo(p1);
        }
        else{
            p2 = p2.midpoint(p1);
            d2 = loc.distanceTo(p2);
        }
        diff = abs(d1-d2);
    }
    return p1.midpoint(p2);
}

