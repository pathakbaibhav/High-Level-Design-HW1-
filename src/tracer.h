#pragma once
#include "simengine.h"
#include "vcd_writer.h"
#include <memory>

class Tracer : public MyModule 
{
public:
    // Constructor that takes a reference to the clock signal, counter, and simulator
    Tracer(bool &clkWire, unsigned int &cnt, Simulator &simulator);

    // Override the cycle function
    void cycle() override;

    // Finalize function to close the VCD file
    void finalize();

    ~Tracer();                                  // Destructor

private:
    bool &myClk;                                // Reference to the clock signal
    unsigned int &myCount;                      // Reference to the counter
    std::unique_ptr<vcd::VCDWriter> writer;     // VCD writer for tracing
    vcd::VarPtr vcdVarClk;                      // Variable for clock in VCD
    vcd::VarPtr vcdVarCnt;                      // Variable for counter in VCD
    Simulator &sim;                             // Reference to the simulator, which will be initialized in the constructor
};
