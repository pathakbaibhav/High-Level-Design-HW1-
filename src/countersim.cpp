#include <iostream>
#include "simengine.h"
#include "clkgen.h"

using namespace std;

//Global Instance of the Simulator Class
Simulator sim;

// Main Function
int main()
{
    //Intial state of the clock signal
    bool myClk = false;
    unsigned int run_time;

    // Create a clock generator and pass the clock signal (myClk)
    ClkGen clkgen(myClk);

    //Register the clock generator with the simulator
    sim.module_register(&clkgen);

    //Maximum Simulation Time
    sim.time_max_set(100);

    run_time = sim.run();
    
    cout << "Simulation finished at time: " << run_time - 1 << endl;
    cout << "Final State of clock: " << myClk << endl;

    return 0;
}