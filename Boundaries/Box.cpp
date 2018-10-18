//
// Created by Andrew Fulkerson on 8/6/18.
//

#include "Box.h"
#include "QGeoCoordinate.h"
#include "Agent.h"

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
    
    n= QGeoCoordinate(north, (west+(west-east)/2));
    s=QGeoCoordinate(south, (west+(west-east)/2));
    e=QGeoCoordinate(north+(north-south)/2, east);
    w=QGeoCoordinate(north+(north-south)/2, west);
    
}
Box::Box(double north, double south, double east, double west) : north(north), south(south), east(east), west(west){
    nw = QGeoCoordinate(north, west);
    ne = QGeoCoordinate(north, east);
    se = QGeoCoordinate(south, east);
    sw = QGeoCoordinate(south, west);
    
    n= QGeoCoordinate(north, (west+(west-east)/2));
    s=QGeoCoordinate(south, (west+(west-east)/2));
    e=QGeoCoordinate(south+(north-south)/2, east);
    w=QGeoCoordinate(south+(north-south)/2, west);

}
Box::Box(const Box &other){}
Box::~Box(){
    delete nw;
    delete ne;
    delete se;
    delete sw;
}
/**
 *Less than operator for comparisons in priority queue
 * @param other
 * @return if this is closer to agent than other
 */
bool operator<(Box &other){
    return getDist()<other.getDist();
    
}

/**
 *
 */
void Box::determineThreshold() {
    threshold = nw.distanceTo(sw) + nw.distanceTo(se) + nw.distanceTo(ne);
}
/**
 *
 * @param loc
 * @return
 */
double Box::comDist(QGeoCoordinate loc){
    return loc.distanceTo(nw) + loc.distanceTo(ne) + loc.distanceTo(se) + loc.distanceTo(sw);

}
/**
 *
 * @param a agent object for drone in search
 * @return true if
 */
bool Box::isNear(Agent::Agent a){
    double d=0;
    if(a.lat>=north){
        if(a.lon<west){//nw corner
            d=a.loc.distanceTo(nw);
        } else if (a.lon>east){//ne corner
            d=a.loc.distanceTo(ne);
        } else {//north
            d=a.loc.distanceTo(QGeoCoordinate::QGeoCoordinate(north, a.lon));;
        }
        
    } else {
        if(a.lat<=south){
            if(a.lon<west){//sw corner
                d=a.loc.distanceTo(sw);
            } else if (a.lon>east){//se corner
                d=a.loc.distanceTo(se);
            } else {//south
                d=a.loc.distanceTo(QGeoCoordinate::QGeoCoordinate(south, a.lon));
            }
        if(a.lon<=west){//west
            d=west-a.lon;
        } else if(a.lon>=east){//east
                d=a.lon-east;
            } else {//inside
                d=0;
            }
        }
    }
    
    setDist(d);
    
    if (d<=DISTANCE_OF_IRRELEVANCE){
        return true;
    }
    
    return false;
}

QGeoCoordinate Box::reflect(QGeoCoordinate loc, double bearing){

}
QGeoCoordinate Box::reflect(Agent a){

}

bool Box::setCorner(QGeoCoordinate point){

}

double Box::getN(){return north;}
double Box::getS(){return south;}
double Box::getE(){return east;}
double Box::getW(){return west;}
double getDist(){return dist;}

QGeoCoordinate Box::getNW(){return nw;}
QGeoCoordinate Box::getNE(){return ne;}
QGeoCoordinate Box::getSE(){return se;}
QGeoCoordinate Box::getSW(){return sw;}

bool Box::setN(double x){
    north = x;
    nw.setLatitude(x);
    ne.setLatitude(x);
    n= QGeoCoordinate(north, (west+(west-east)/2));
    e=QGeoCoordinate(south+(north-south)/2, east);
    w=QGeoCoordinate(south+(north-south)/2, west);
    return true;

}
bool Box::setS(double x){
    south = x;
    se.setLatitude(x);
    sw.setLatitude(x);
    s=QGeoCoordinate(south, (west+(west-east)/2));
    e=QGeoCoordinate(south+(north-south)/2, east);
    w=QGeoCoordinate(south+(north-south)/2, west);
    return true;

}
bool Box::setE(double x){
    east = x;
    ne.setLongitude(x);
    se.setLongitude(x);
    n= QGeoCoordinate(north, (west+(west-east)/2));
    s=QGeoCoordinate(south, (west+(west-east)/2));
    e=QGeoCoordinate(south+(north-south)/2, east);
    return true;

}
bool Box::setW(double x){
    west = x;
    nw.setLongitude(x);
    sw.setLongitude(x);
    n= QGeoCoordinate(north, (west+(west-east)/2));
    s=QGeoCoordinate(south, (west+(west-east)/2));
    w=QGeoCoordinate(south+(north-south)/2, west);
    return true;

}

bool setDist(double d){
    dist = d;
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