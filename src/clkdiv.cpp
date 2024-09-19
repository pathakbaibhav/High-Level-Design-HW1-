#include "clkdiv.h"

// Constructor initializes clkWire, clkDiv, and the simulator
ClkDiv::ClkDiv(bool &clkWire, bool &clkDiv, Simulator &sim) 
    : MyModule(), clkWire(clkWire), clkDiv(clkDiv), edgeCount(0) 
{
}

void ClkDiv::cycle() 
{
    // Increment edge count on each clock edge (rising or falling)
    edgeCount++;

    // After 4 edges, toggle the divided clock signal
    if (edgeCount >= 4) {
        clkDiv = !clkDiv;
        edgeCount = 0;  // Reset edge count after toggling clkDiv
    }
}
