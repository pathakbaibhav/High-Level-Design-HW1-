#include "clkgen.h"

// Constructor for the ClkGen class
ClkGen::ClkGen(bool &clkWire) : myClk(clkWire) 
{
    myClk = false;  // Initialize clock signal to low
}

// The cycle method toggles the clock signal on each cycle
void ClkGen::cycle() 
{
    myClk = !myClk;  // Toggle the clock signal
}
