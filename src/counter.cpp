#include "counter.h"

Counter::Counter(bool &clk, bool &clkDiv, unsigned int &cnt, Simulator &sim) : MyModule(), myClk(clk), myClkDiv(clkDiv), myCount(cnt), prevClk(false), sim(sim) 
{
    // Initialize the counter
    myCount = 0;
}

void Counter::cycle() 
{
    // Handling the rising edge of the main clock (myClk)
    if (myClk && !prevClk) 
    {  
        myCount++;          // Rising edge detection
    }
    prevClk = myClk;

    // Handling the rising edge of the divided clock (myClkDiv)
    if (myClkDiv && !prevClkDiv) 
    {  
        myCount++;  // Increment counter on rising edge of myClkDiv
    }
    prevClkDiv = myClkDiv;
}

// Getter function to return the value of the counter
unsigned int Counter::get_count() const 
{
    return myCount;
}
