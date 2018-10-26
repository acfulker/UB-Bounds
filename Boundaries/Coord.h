//
// Created by Andrew Fulkerson on 10/22/18.
//

#ifndef BOUNDARIES_COORD_H
#define BOUNDARIES_COORD_H

#include <math.h>

class Coord {
private:

public:
    double latitude, longitude;
    Coord(){};
    Coord(double lat, double lon) : latitude(lat), longitude(lon) {};

    
    double distanceTo(Coord &other);
    
    
};


#endif //BOUNDARIES_COORD_H