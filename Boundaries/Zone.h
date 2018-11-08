//
// Created by Andrew Fulkerson on 11/5/18.
//

#ifndef BOUNDARIES_ZONE_H
#define BOUNDARIES_ZONE_H

#include <vector>
#include "Agent.h"

class Zone {
private:

public:
    
    int polyCorners;
    std::vector<double> lats, lons, multiple, constant;
    Zone(std::vector<double> lat, std::vector<double> lon, int points);
    
    ~Zone();
    
    bool inZone(Agent &a);

};


#endif //BOUNDARIES_ZONE_H
