#pragma once
#include "simengine.h"

class ClkGen : public MyModule {
public:
    // Constructor takes a reference to the clock wire and the simulator
    ClkGen(bool &clkWire, Simulator &simulator);

    // Override the cycle function
    void cycle() override;

private:
    bool &myClk;  // Reference to the clock signal
    Simulator &sim;  // Reference to the simulator
};
