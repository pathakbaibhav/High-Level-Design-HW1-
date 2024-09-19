#pragma once
#include "simengine.h"

class ClkDiv : public MyModule  // Ensure ClkDiv inherits from MyModule
{
public:
    // Constructor that takes clkWire, clkDiv, and Simulator as inputs
    ClkDiv(bool &clkWire, bool &clkDiv, Simulator &sim);

    void cycle() override;

private:
    bool &clkWire;  // Reference to the original clock signal
    bool &clkDiv;   // Reference to the divided clock signal
    int edgeCount;  // To track the number of clock edges
};
