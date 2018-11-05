//
// Created by Andrew Fulkerson on 11/5/18.
//

#include "Zone.h"

Zone::Zone(float *lat, float *lon, int points) : polyCorners(points) {
    lats = new float[polyCorners];
    lons = new float[polyCorners];
    constant = new float[polyCorners];
    multiple = new float[polyCorners];
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
    }
}

Zone::~Zone() {
    delete [] lats, lons, constant, multiple;
}

bool Zone::inZone(double lat, double lon) {
    int   i, j=polyCorners-1 ;
    bool  oddNodes=false      ;
    
    for (i=0; i<polyCorners; i++) {
        if (((lats[i]< lat && lats[j]>=lat)
             ||   (lats[j]< lat && lats[i]>=lat))) {
            oddNodes^=(lat*multiple[i]+constant[i]<lon); }
        j=i; }
    
    return oddNodes; 
}
