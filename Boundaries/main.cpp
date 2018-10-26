#include <iostream>
#include "Agent.h"
#include "Box.h"
#include "World.h"

void setup();

int main() {
    
    World w = World();
    Agent a = Agent(Coord(42.9991, 78.7775));
    
    setup();
    
    return 0;
}
/**
 * Sets up the world
 */
void setup(){
    
}