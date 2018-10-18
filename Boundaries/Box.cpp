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
 * @param a agent object for drone in search
 * @return true if a is within DISTANCE_OF_IRRELEVANCE.
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

/**
 *
 * @param loc
 * @param bearing
 * @return
 */
QGeoCoordinate Box::reflect(QGeoCoordinate loc, double bearing){

}
/**
 *
 * @param a
 * @return
 */
QGeoCoordinate Box::reflect(Agent a){

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

/**
 *
 * @param d distance from drone to boundary
 */
void setDist(double d){
    dist = d;
}