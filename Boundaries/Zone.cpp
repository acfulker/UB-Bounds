//
// Created by Andrew Fulkerson on 11/5/18.
//

#include "Zone.h"
#include "Line.h"

Zone::Zone(std::vector<double> lat, std::vector<double> lon, int points) : polyCorners(points) {
    lats = lat;
    lons = lon;
    constant.resize(polyCorners);
    multiple.resize(polyCorners);
    int   i, j=polyCorners-1 ;
    
    for(i=0; i<polyCorners; i++) {
        if(lats[j]==lats[i]) {
            constant[i]=lons[i];
            multiple[i]=0; 
        }
        else {
            constant[i]=lons[i]-(lats[i]*lons[j])/(lats[j]-lats[i])+(lats[i]*lons[i])/(lats[j]-lats[i]);
            multiple[i]=(lons[j]-lons[i])/(lats[j]-lats[i]); 
        }
        j=i; 
    }//end for
}

Zone::~Zone() {
    //delete [] lats, lons, constant, multiple;
}
/**
 * inPolygon function
 * @param lat
 * @param lon
 * @return true if coordinates within zone
 */

bool Zone::inZone(Agent &a) {
    double lat = a.lat;
    double lon = a.lon;
    int   i, j=polyCorners-1;
    bool  oddNodes=false;
    
    for (i=0; i<polyCorners; i++) {
        if (((lats[i]< lat && lats[j]>=lat)
             ||   (lats[j]< lat && lats[i]>=lat))) {
            oddNodes^=(lat*multiple[i]+constant[i]<lon); }
        j=i; }
    
    return oddNodes; 
}

/**
 * edges function
 * @return vector of lines representing edges of zone
 */
void Zone::edgeList(){
    for (int i=0; i < polyCorners-1; i++){
        edges.emplace_back(Line(Coord(lats[i],lons[i]), Coord(lats[i+1],lons[i+1])));
    }
    edges.emplace_back(Line(Coord(lats[0],lons[0]), Coord(lats[polyCorners-1],lons[polyCorners-1])));

}