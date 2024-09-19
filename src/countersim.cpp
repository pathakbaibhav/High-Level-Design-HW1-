#include "simengine.h"
#include "clkgen.h"
#include "tracer.h"
#include "counter.h"
#include <iostream>

Simulator sim;

int main() 
{
    bool clkWire = false;                       // Clock signal for the simulation
    unsigned int count = 0;                     // Counter Variable

    // Create the clock generator, counter, and tracer modules, passing references
    ClkGen clkGen(clkWire, sim);
    Counter counter(clkWire, count, sim);
    Tracer tracer(clkWire, count, sim);         // Pass clkWire, count, and sim

    // Register the modules with the simulator
    sim.module_register(&clkGen);
    sim.module_register(&counter);              // Register the counter module
    sim.module_register(&tracer);

    // Run the simulation for 100 cycles
    sim.time_max_set(100);
    sim.run();

    // Retrieve and print the final value of the counter
    std::cout << "Final counter value: " << counter.get_count() << std::endl;

    // Finalize and close the VCD file or any other resources if needed
    tracer.finalize();

    return 0;
}
