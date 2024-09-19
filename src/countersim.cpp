#include "simengine.h"
#include "clkgen.h"
#include "clkdiv.h"
#include "tracer.h"
#include "counter.h"
#include <iostream>

Simulator sim;

int main() 
{
    bool clkWire = false;                       // Main Clock signal for the simulation
    bool myClkDiv = false;                      // Divided Clock signal, ensure it's defined
    unsigned int count = 0;                     // Counter Variable

    // Create the clock generator, clock divider, counter, and tracer modules, passing references
    ClkGen clkGen(clkWire, sim);                // Clock generator
    ClkDiv clkDiv(clkWire, myClkDiv, sim);      // Clock divider, takes clkWire and produces myClkDiv
    Counter counter(clkWire, myClkDiv, count, sim); // Counter uses both clkWire and myClkDiv

    // Tracers with different file types
    Tracer tracerClkGen(clkWire, myClkDiv, count, sim, "clkGen");           // Traces only the clk in clkGen.vcd
    Tracer tracerCounter(clkWire, myClkDiv, count, sim, "counter");         // Traces clk and myCnt in counter.vcd
    Tracer tracerClkDiv(clkWire, myClkDiv, count, sim, "clkDiv");           // Traces only myClkDiv in clkDiv.vcd
    Tracer tracerClkDivCounter(clkWire, myClkDiv, count, sim, "clkDivCounter");  // Traces clk, myClkDiv, and myCnt in clkDivCounter.vcd

    // Register the modules with the simulator
    sim.module_register(&clkGen);               // Register the clock generator
    sim.module_register(&clkDiv);               // Register the clock divider
    sim.module_register(&counter);              // Register the counter module
    sim.module_register(&tracerClkGen);
    sim.module_register(&tracerCounter);
    sim.module_register(&tracerClkDiv);
    sim.module_register(&tracerClkDivCounter);
    // Run the simulation for 100 cycles
    sim.time_max_set(100);
    sim.run();

    // Retrieve and print the final value of the counter
    std::cout << "Final counter value: " << counter.get_count() << std::endl;

    // Finalize and close the VCD files
    tracerClkGen.finalize();
    tracerCounter.finalize();
    tracerClkDiv.finalize();
    tracerClkDivCounter.finalize();

    return 0;
}
