//
// Created by Andrew Fulkerson on 8/6/18.
//

#include "Box.h"
#include "Coord.h"
#include "Agent.h"

Box::Box(){}
Box::Box(Coord p1, Coord p2){
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

    nw = Coord(north, west);
    ne = Coord(north, east);
    se = Coord(south, east);
    sw = Coord(south, west);
    
    n= Coord(north, (west+(west-east)/2));
    s=Coord(south, (west+(west-east)/2));
    e=Coord(north+(north-south)/2, east);
    w=Coord(north+(north-south)/2, west);
    
}
Box::Box(double north, double south, double east, double west) : north(north), south(south), east(east), west(west){
    nw = Coord(north, west);
    ne = Coord(north, east);
    se = Coord(south, east);
    sw = Coord(south, west);
    
    n= Coord(north, (west+(west-east)/2));
    s=Coord(south, (west+(west-east)/2));
    e=Coord(south+(north-south)/2, east);
    w=Coord(south+(north-south)/2, west);

}
Box::Box(const Box &other){}
Box::~Box(){
    delete nw;
    delete ne;
    delete se;
    delete sw;
}

/**
 *
 * @param a agent object for drone in search
 * @return Distance to box
 */
double Box::getDist(Agent::Agent a){
    double d=0;
    if(a.lat>=north){
        if(a.lon<west){//nw corner
            d=a.loc.distanceTo(nw);
        } else if (a.lon>east){//ne corner
            d=a.loc.distanceTo(ne);
        } else {//north
            d=a.loc.distanceTo(Coord::Coord(north, a.lon));;
        }
        
    } else {
        if(a.lat<=south){
            if(a.lon<west){//sw corner
                d=a.loc.distanceTo(sw);
            } else if (a.lon>east){//se corner
                d=a.loc.distanceTo(se);
            } else {//south
                d=a.loc.distanceTo(Coord::Coord(south, a.lon));
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

    return d;
}


double Box::getN(){return north;}
double Box::getS(){return south;}
double Box::getE(){return east;}
double Box::getW(){return west;}
double getDist(){return dist;}

Coord Box::getNW(){return nw;}
Coord Box::getNE(){return ne;}
Coord Box::getSE(){return se;}
Coord Box::getSW(){return sw;}

/**
 *
 * @param d distance from drone to boundary
 */
void setDist(double d){
    dist = d;
}