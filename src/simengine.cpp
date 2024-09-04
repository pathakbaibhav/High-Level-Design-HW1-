#include "./simengine.h"

unsigned int Simulator::module_register(MyModule *pModule) {
    if (modules_nr >= MODULE_MAX) {
        // max number of modules exceeded 
        return 1;
    } else {
        modules[modules_nr] = pModule;
        modules_nr++;
        return 0;
    }
}

unsigned int Simulator::run() {
    // iterate through time
    for(simTime=0;simTime<=simTimeMax;simTime++){
        // call each registered module
        for (unsigned int i =0; i<modules_nr; i++) {
            modules[i]->cycle();
        }
    }
    // return time when simulation terminated. 
    return simTime;
}
