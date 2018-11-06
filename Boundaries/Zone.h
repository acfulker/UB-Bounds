//
// Created by Andrew Fulkerson on 11/5/18.
//

#ifndef BOUNDARIES_ZONE_H
#define BOUNDARIES_ZONE_H

#include <vector>

class Zone {
private:

public:
    
    int polyCorners;
    std::vector<float> lats, lons, multiple, constant;
    Zone(std::vector<float> lat, std::vector<float> lon, int points);
    
    ~Zone();
    
    bool inZone(double lat, double lon);

};


#endif //BOUNDARIES_ZONE_H
