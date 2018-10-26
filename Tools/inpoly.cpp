//  Globals which should be set before calling these functions:
//
//  int    polyCorners  =  how many corners the polygon has (no repeats)
//  float  polyX[]      =  horizontal coordinates of corners
//  float  polyY[]      =  vertical coordinates of corners
//  float  x, y         =  point to be tested
//
//  The following global arrays should be allocated before calling these functions:
//
//  float  constant[] = storage for precalculated constants (same size as polyX)
//  float  multiple[] = storage for precalculated multipliers (same size as polyX)
//
//  (Globals are used in this example for purposes of speed.  Change as
//  desired.)
//
//  USAGE:
//  Call precalc_values() to initialize the constant[] and multiple[] arrays,
//  then call pointInPolygon(x, y) to determine if the point is in the polygon.
//
//  The function will return YES if the point x,y is inside the polygon, or
//  NO if it is not.  If the point is exactly on the edge of the polygon,
//  then the function may return YES or NO.
//
//  Note that division by zero is avoided because the division is protected
//  by the "if" clause which surrounds it.
#include <iostream>
int polyCorners = 4;
float polyX[] = {1, -1, -1, 1};
float polyY[] = {1, 1, -1, -1};
float x = 0;
float y = 0;

float constant[] = {0,0,0,0};
float multiple[] = {0,0,0,0};

void precalc_values() {

  int   i, j=polyCorners-1 ;

  for(i=0; i<polyCorners; i++) {
    if(polyY[j]==polyY[i]) {
      constant[i]=polyX[i];
      multiple[i]=0; }
    else {
      constant[i]=polyX[i]-(polyY[i]*polyX[j])/(polyY[j]-polyY[i])+(polyY[i]*polyX[i])/(polyY[j]-polyY[i]);
      multiple[i]=(polyX[j]-polyX[i])/(polyY[j]-polyY[i]); }
    j=i; }}

bool pointInPolygon() {

  int   i, j=polyCorners-1 ;
  bool  oddNodes=false      ;

  for (i=0; i<polyCorners; i++) {
    if ((polyY[i]< y && polyY[j]>=y
    ||   polyY[j]< y && polyY[i]>=y)) {
      oddNodes^=(y*multiple[i]+constant[i]<x); }
    j=i; }

  return oddNodes; }


int main() {
    precalc_values();
	std::cout << pointInPolygon() << std::endl;
	x = 2;
	std::cout << pointInPolygon() << std::endl;
    x = 0.5;
    y = -0.5;
	std::cout << pointInPolygon() << std::endl;
    return 0;
}




