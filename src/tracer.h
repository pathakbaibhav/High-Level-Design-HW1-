#pragma once
#include "simengine.h"
#include "vcd_writer.h"
#include <memory>

class Tracer : public MyModule 
{
public:
    // Constructor with parameters for the clk, clkDiv, count, and file type
    Tracer(bool &clkWire, bool &clkDivWire, unsigned int &cnt, Simulator &sim, const std::string &fileType);

    void cycle() override;

    void finalize(); // Close the VCD file when the simulation finishes

    ~Tracer(); // Destructor

private:
    bool &myClk;               // Reference to the clock signal
    bool &myClkDiv;            // Reference to the divided clock signal
    unsigned int &myCount;     // Counter variable
    std::unique_ptr<vcd::VCDWriter> writer;  // VCD writer for tracing
    vcd::VarPtr vcdVarClk;     // Variable for clock in VCD
    vcd::VarPtr vcdVarClkDiv;  // Variable for divided clock in VCD
    vcd::VarPtr vcdVarCnt;     // Variable for counter in VCD
    std::string fileType;      // Determines which VCD file to write to
    Simulator &sim;            // Reference to the simulator
};
