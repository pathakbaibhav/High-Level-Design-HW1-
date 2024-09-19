#pragma once

#include "simengine.h"

class Counter : public MyModule {
public:
    Counter(bool &clk, unsigned int &cnt, Simulator &sim);

    void cycle() override;

    unsigned int get_count() const;

private:
    bool &myClk;   // Reference to the clock signal
    unsigned int &myCount;  // Counter variable
    bool prevClk = false;  // To track the previous clock state
    Simulator &sim;  // Reference to the simulator, which will be initialized in the constructor
};
