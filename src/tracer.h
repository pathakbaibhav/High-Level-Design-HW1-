#pragma once
#include "simengine.h"
#include "vcd_writer.h"
#include <memory>

class Tracer : public MyModule {
public:
    // Constructor that takes a reference to the clock signal and simulator
    Tracer(bool &clkWire, Simulator &simulator);

    // Override the cycle function
    void cycle() override;

    // Finalize function to close the VCD file
    void finalize();

    ~Tracer();  // Destructor

private:
    bool &myClk;  // Reference to the clock signal
    std::unique_ptr<vcd::VCDWriter> writer;  // VCD writer
    vcd::VarPtr counter_var;  // Variable for clock in VCD
    Simulator &sim;  // Reference to the simulator
};
