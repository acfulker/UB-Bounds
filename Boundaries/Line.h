//
// Created by Anna Sholk and Andrew Fulkerson on 2/18/19.
//

#ifndef TINYXML2_LINE_H
#define TINYXML2_LINE_H

#include "Coord.h"

class Line {
private:

public:
    Coord p1, p2;
    Line(Coord point1, Coord point2) : p1(point1), p2(point2){};

};


#endif //TINYXML2_LINE_H
