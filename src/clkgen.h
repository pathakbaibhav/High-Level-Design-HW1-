#ifndef CLKGEN_H
#define CLKGEN_H

#include "simengine.h"  // Include the simulation engine header

class ClkGen : public MyModule 
{
    bool &myClk;  // Reference to the wire (bool) that will be toggled

public:
    // Constructor that initializes ClkGen with a reference to a bool (the "wire")
    ClkGen(bool &clkWire);

    // The cycle method will be called on each clock cycle by the Simulator
    void cycle() override;
};

#endif // CLKGEN_H
