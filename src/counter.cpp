#include "counter.h"

Counter::Counter(bool &clk, unsigned int &cnt, Simulator &sim) 
    : MyModule(), myClk(clk), myCount(cnt), prevClk(false), sim(sim) {  // Correct base class call and sim initialization
    // Initialize the counter
    myCount = 0;
}

void Counter::cycle() {
    if (myClk && !prevClk) {  // Rising edge detection
        myCount++;
    }
    prevClk = myClk;
}

// Getter function to return the value of the counter
unsigned int Counter::get_count() const {
    return myCount;
}
