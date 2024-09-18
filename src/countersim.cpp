#include "simengine.h"
#include "clkgen.h"
#include "tracer.h"

Simulator sim;

int main() {
    bool clkWire = false;  // Clock signal for the simulation

    // Create the clock generator and tracer modules, passing clkWire by reference
    ClkGen clkGen(clkWire, sim);   // Pass the reference of clkWire
    Tracer tracer(clkWire, sim);   // Pass the reference of clkWire

    // Register both modules with the simulator
    sim.module_register(&clkGen);
    sim.module_register(&tracer);

    // Run the simulation for 100 cycles
    sim.time_max_set(100);
    sim.run();

    // Finalize and close the VCD file
    tracer.finalize();

    return 0;
}
