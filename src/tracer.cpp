#include <bitset>
#include "tracer.h"
#include <filesystem>
#include <iostream>  // For debugging

using namespace vcd;

Tracer::Tracer(bool &clkWire, Simulator &simulator)
    : myClk(clkWire), writer(nullptr), sim(simulator)
{
    // Create the VCD header
    HeadPtr head = makeVCDHeader(TimeScale::ONE, TimeScaleUnit::ns, utils::now());

    // Initialize the VCD writer to create the .vcd file in the results directory
    writer = std::make_unique<VCDWriter>("/Users/baibhavpathak/Documents/Development/hw1-pathakbaibhav/results/trace_dump.vcd", head);

    // Register the clock signal in the VCD writer
    counter_var = writer->register_var("Tracer", "wire", VariableType::wire, 1);
}

void Tracer::cycle()
{
    // Write the current clock value to the VCD file at the current simulation time
    writer->change(counter_var, sim.time_get(), std::bitset<1>(myClk).to_string());
}

void Tracer::finalize()
{
    if (writer) {
        writer->close();  // Ensure the VCDWriter file is closed
    }
}

Tracer::~Tracer()
{
    finalize();  // Call finalize on destruction
}
