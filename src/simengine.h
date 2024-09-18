#ifndef SIMENGINE_H  // Start of include guard
#define SIMENGINE_H

#include <bitset>

/** max number of modules in simulation */
#define MODULE_MAX 10


/** base class that all modules have to inherit from 
 *  in order to be called in the simulator cycle */
class MyModule {
    public: 
        /// @brief called by the sim engine on every cycle
        virtual void cycle() = 0; 
};


/** Simple digital logic simulation engine that keeps track of  
 *  simulation time and calls all registered modules each time 
 *  the sim time increases */
class Simulator {
    unsigned int simTime; /// simulation time 
    unsigned int simTimeMax; /// until when to run simulation 
    MyModule *modules[MODULE_MAX]; /// array of registered modules 
    unsigned int modules_nr = 0;  /// current number of registered modules

    public: 
        /** run simulation (and all registered modules ) until reaching max time */
        unsigned int run(void);

        /** when should simulation stop ? */
        void time_max_set(unsigned int maxTimeIn) {
            simTimeMax = maxTimeIn;
        }

        /* return current simulation time */
        unsigned int time_get(void) {   
            return simTime;
        }

        /** register a module to be called on every clock sycle 
         *  Modules will be called in order of registration. User  
         *  is responsible to register modules in dependency order. 
         *  That means a module that produces a signal has to be 
         *  registered before a module that uses that signal. 
         **/
        unsigned int module_register(MyModule *pModule);
};

#endif // SIMENGINE_H  // End of include guard
