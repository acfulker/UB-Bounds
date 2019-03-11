//
// Created by Andrew Fulkerson on 10/11/18.
//

#include "Agent.h"

Agent::Agent(){
    auto loc = Coord();
    lat = 0;
    lon = 0;
    bear = 0;
}
Agent::Agent(Coord &coord, int bearing) {
    lat = coord.latitude;
    lon = coord.longitude;
    loc = coord;
    bear = bearing;
}

/**
 *
 * @param ep1, ep2
 * @return the closest point on a line to the drone (loc)
**/
Coord Agent::nearestPoint2Line(Line l){
    double threshold = 10;
    Coord p1 = l.p1, p2 = l.p2;
    double d1 = loc.distanceTo(p1), d2 = loc.distanceTo(p2);
    double diff = abs(d1-d2);
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

