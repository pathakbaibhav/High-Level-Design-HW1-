#include "tracer.h"
#include <bitset>

Tracer::Tracer(bool &clk, unsigned int &cnt, Simulator &sim) : MyModule(), myClk(clk), myCount(cnt), sim(sim) 
{
    // Create a dummy or default HeadPtr (you can customize this if more details are needed)
    vcd::HeadPtr header = nullptr;

    // Initialize the VCD writer with a filename and the default header
    writer = std::make_unique<vcd::VCDWriter>("results/counter.vcd", header);

    // Register the clock and counter variables in the VCD file
    vcdVarClk = writer->register_var("Main", "clk", vcd::VariableType::wire, 1);
    vcdVarCnt = writer->register_var("Main", "myCnt", vcd::VariableType::wire, 8);
}

void Tracer::cycle() 
{
    // Use sim.time_get() to get the current simulation time
    writer->change(vcdVarClk, sim.time_get(), myClk ? "1" : "0");

    // Trace the counter value in the VCD file
    writer->change(vcdVarCnt, sim.time_get(), std::bitset<8>(myCount).to_string());
}

void Tracer::finalize() 
{
    // Finalize the VCD tracing and close the file
    writer->close();
}

Tracer::~Tracer() 
{
    // Destructor for clean-up (if necessary)
}
