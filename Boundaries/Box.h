//
// Created by Andrew Fulkerson on 8/6/18.
//

#ifndef BOUNDARIES_BOX_H
#define BOUNDARIES_BOX_H

#define DISTANCE_OF_IRRELEVANCE = 50;

class Box {
private:
    //These should be the same data
    double north, south, east, west;//Boundaries in latitude and longitude
    QGeoCoordinate nw, ne, se, sw;//Boundary corners as QGC
    double borderDistance;
    double threshold;
    
    void determineThreshold();
    
public:
    Box();
    Box(QGeoCoordinate p1, QGeoCoordinate p2);
    Box(double north, double south, double east, double west);
    Box(const Box &other);
    ~Box();
    
    double comDist(QGeoCoordinate loc);//Returns sum of distances to each corner
    bool isNear(QgeoCoordinate loc);//Returns true if loc is within approx. DISTANCE_OF_IRRELEVANCE from the bounding box
    
    
    QGeoCoordinate reflect(QGeoCoordinate loc, double bearing);//Returns a coordinate in the direction of reflection
    QGeoCoordinate reflect(Vehicle mav);
    
    bool Box::setCorner(QGeoCoordinate point);
    
    double getN();
    double getS();
    double getE();
    double getW();
    
    QGeoCoordinate getNW();
    QGeoCoordinate getNE();
    QGeoCoordinate getSE();
    QGeoCoordinate getSW();
    
    
    //Returns true if the value was set
    bool setN(double n);
    bool setS(double s);
    bool setE(double e);
    bool setW(double w);
    
    bool setNW(QGeoCoordinate point);
    bool setNE(QGeoCoordinate point);
    bool setSE(QGeoCoordinate point);
    bool setSW(QGeoCoordinate point);

};


#endif //BOUNDARIES_BOX_H
