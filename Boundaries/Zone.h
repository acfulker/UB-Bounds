//
// Created by Andrew Fulkerson on 11/5/18.
//

#ifndef BOUNDARIES_ZONE_H
#define BOUNDARIES_ZONE_H


class Zone {
private:

public:
    float *lats, *lons, *constant, *multiple;
    int polyCorners;
    
    Zone(float *lat, float *lon, int points);
    
    ~Zone();
    
    bool inZone(double lat, double lon);

};


#endif //BOUNDARIES_ZONE_H
