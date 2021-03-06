//
// Created by Andrew Fulkerson and Anna Sholk on 10/22/18.
//

#ifndef BOUNDARIES_COORD_H
#define BOUNDARIES_COORD_H

#include <math.h>

class Coord {
private:

public:
    double latitude, longitude;
    bool null;
    Coord(){};
    Coord(double lat, double lon) : latitude(lat), longitude(lon), null(false) {};
    Coord(bool null) : null(null){};

    
    double distanceTo(Coord &other);
    Coord midpoint(Coord &other);
    double bearingTo(Coord &other);
    Coord pointAt(double dist, double bearing);

    double normalizeB(double bearing);
    double cosDeg(double deg);
    double sinDeg(double deg);
    
};


#endif //BOUNDARIES_COORD_H
