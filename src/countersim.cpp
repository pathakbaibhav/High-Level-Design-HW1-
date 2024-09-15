#include <iostream>
#include "simengine.h"

using namespace std;

// Global Instance of the Simulator Class
Simulator sim;

int main()
{
    unsigned int run_time;

    sim.time_max_set(100);
    run_time = sim.run();
    
    cout << "Simulation finished at time: " << run_time - 1 << endl;

    return 0;
}