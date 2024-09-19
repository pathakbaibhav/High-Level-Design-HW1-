#include "clkgen.h"

ClkGen::ClkGen(bool &clkWire, Simulator &simulator) : myClk(clkWire), sim(simulator)
{
    // Initialize the clock signal to false
    myClk = false;
}

void ClkGen::cycle()
{
    // Toggle the clock signal on each cycle
    myClk = !myClk;
}
