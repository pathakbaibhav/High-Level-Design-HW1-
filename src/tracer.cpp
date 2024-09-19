#include "tracer.h"
#include <iostream>

Tracer::Tracer(bool &clk, bool &clkDiv, unsigned int &cnt, Simulator &sim, const std::string &fileType)
    : myClk(clk), myClkDiv(clkDiv), myCount(cnt), sim(sim), fileType(fileType)
{
    vcd::HeadPtr header = nullptr;

    // Create a new VCDWriter for each fileType and register the appropriate signals
    if (fileType == "clkGen") {
        writer = std::make_unique<vcd::VCDWriter>("results/clkGen.vcd", header);
        vcdVarClk = writer->register_var("Main", "clk", vcd::VariableType::wire, 1);
    } 
    else if (fileType == "counter") {
        writer = std::make_unique<vcd::VCDWriter>("results/counter.vcd", header);
        vcdVarClk = writer->register_var("Main", "clk", vcd::VariableType::wire, 1);
        vcdVarCnt = writer->register_var("Main", "myCnt", vcd::VariableType::wire, 8);
    } 
    else if (fileType == "clkDiv") {
        writer = std::make_unique<vcd::VCDWriter>("results/clkDiv.vcd", header);
        vcdVarClkDiv = writer->register_var("Main", "myClkDiv", vcd::VariableType::wire, 1);
    } 
    else if (fileType == "clkDivCounter") {
        writer = std::make_unique<vcd::VCDWriter>("results/clkDivCounter.vcd", header);
        vcdVarClk = writer->register_var("Main", "clk", vcd::VariableType::wire, 1);
        vcdVarClkDiv = writer->register_var("Main", "myClkDiv", vcd::VariableType::wire, 1);
        vcdVarCnt = writer->register_var("Main", "myCnt", vcd::VariableType::wire, 8);
    }
}

void Tracer::cycle() 
{
    // Record changes to the appropriate signals in the VCD file based on fileType
    if (fileType == "clkGen" || fileType == "clkDivCounter") {
        writer->change(vcdVarClk, sim.time_get(), myClk ? "1" : "0");
    }
    if (fileType == "counter" || fileType == "clkDivCounter") {
        writer->change(vcdVarCnt, sim.time_get(), std::bitset<8>(myCount).to_string());
    }
    if (fileType == "clkDiv" || fileType == "clkDivCounter") {
        writer->change(vcdVarClkDiv, sim.time_get(), myClkDiv ? "1" : "0");
    }
}

void Tracer::finalize() 
{
    // Close the VCD file
    writer->close();
}

Tracer::~Tracer() 
{
    // Destructor for clean-up
}
