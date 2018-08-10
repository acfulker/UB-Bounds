//
// Created by Andrew Fulkerson on 8/6/18.
//

#include "Box.h"
#include "QGeoCoordinate.h"

Box::Box(){}
Box::Box(QGeoCoordinate p1, QGeoCoordinate p2){
    if(p1.latitude()>p2.latitude()){
        north=p1.latitude();
        south=p2.latitude();
    } else {
        north=p2.latitude();
        south=p1.latitude();
    }
    
    if(p1.longitude()>p2.lonitude()){
        east=p1.longitude();
        west=p2.longitude();
    } else {
        east=p2.longitude();
        west=p1.longitude();
    }

    nw = QGeoCoordinate(north, west);
    ne = QGeoCoordinate(north, east);
    se = QGeoCoordinate(south, east);
    sw = QGeoCoordinate(south, west);
    
}
Box::Box(double north, double south, double east, double west) : north(north), south(south), east(east), west(west){
    nw = QGeoCoordinate(north, west);
    ne = QGeoCoordinate(north, east);
    se = QGeoCoordinate(south, east);
    sw = QGeoCoordinate(south, west);

}
Box::Box(const Box &other){

}
Box::~Box(){
    delete nw;
    delete ne;
    delete se;
    delete sw;
}

void Box::determineThreshold() {
    threshold = nw.distanceTo(sw) + nw.distanceTo(se) + nw.distanceTo(ne);
}

double Box::comDist(QGeoCoordinate loc){
    return loc.distanceTo(nw) + loc.distanceTo(ne) + loc.distanceTo(se) + loc.distanceTo(sw);

}

bool Box::isNear(QgeoCoordinate loc){


}

QGeoCoordinate Box::reflect(QGeoCoordinate loc, double bearing){

}
QGeoCoordinate Box::reflect(Vehicle mav){

}

bool Box::setCorner(QGeoCoordinate point){

}

double Box::getN(){return north;}
double Box::getS(){return south;}
double Box::getE(){return east;}
double Box::getW(){return west;}

QGeoCoordinate Box::getNW(){return nw;}
QGeoCoordinate Box::getNE(){return ne;}
QGeoCoordinate Box::getSE(){return se;}
QGeoCoordinate Box::getSW(){return sw;}

bool Box::setN(double n){
    north = n;
    nw.setLatitude(n);
    ne.setLatitude(n);
    return true;

}
bool Box::setS(double s){
    south = s;
    se.setLatitude(s);
    sw.setLatitude(s);
    return true;

}
bool Box::setE(double e){
    east = e;
    ne.setLongitude(e);
    se.setLongitude(e);
    return true;

}
bool Box::setW(double w){
    west = w;
    nw.setLongitude(w);
    sw.setLongitude(w);
    return true;

}

bool Box::setNW(QGeoCoordinate point){
    nw = point;
    north = point.latitude();
    west = point.longitude();
    sw.setLongitude(west);
    ne.setLongitude(north);
    return true;

}
bool Box::setNE(QGeoCoordinate point){
    ne = point;
    north = point.latitude();
    east = point.longitude();
    nw.setLatitude(north);
    se.setLongitude(east);
    return true;

}
bool Box::setSE(QGeoCoordinate point){
    se = point;
    south = point.latitude();
    east = point.longitude();
    sw.setLatitude(south);
    ne.setLongitude(east);
    return true;

}
bool Box::setSW(QGeoCoordinate point){
    sw = point;
    south = point.latitude();
    west = point.longitude();
    se.setLatitude(south);
    nw.setLongitude(west);
    return true;

}