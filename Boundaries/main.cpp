#include <iostream>
#include "Agent.h"
#include "Box.h"
#include "World.h"

void setup();

int main() {
    
    World::World w = World::World();
    Agent::Agent a = Agent::Agent(Coord::Coord(42.9991, 78.7775));
    
    setup();
    
    return 0;
}
/**
 * Sets up the world
 */
void setup(){
    Box::Box stadium = Box::Box(43.000184, 42.997998, -78.776333, -78.778680);
    w.add(stadium);
    w.add(Box::Box(Coord::Coord(42.999431, -78.782041),Coord::Coord(43.000888, -78.780360)));
    
    
}