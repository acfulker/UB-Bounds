//
// Created by Andrew Fulkerson and Anna Sholk on 11/5/18.
//

#ifndef BOUNDARIES_ZONE_H
#define BOUNDARIES_ZONE_H

#include <vector>
#include "Agent.h"
#include "Line.h"

class Zone {
private:

public:
    
    int polyCorners;
    std::vector<double> lats, lons, multiple, constant;
    std::vector<Line> edges;
    Zone(std::vector<double> lat, std::vector<double> lon, int points);
    
    ~Zone();
    
    bool inZone(Agent &a);
    void edgeList();

};


#endif //BOUNDARIES_ZONE_H
