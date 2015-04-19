#include "c_PortRows_MCP23018.h"
#include "c_Matrix.h"

void c_PortRows_MCP23018::begin()
{
    Wire.beginTransmission(ADDR);
    Wire.write(IODIR);
    Wire.write(0);                              //0=configure as output (for strobe PINS and LED)
    Wire.endTransmission();
}

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//only read the ports, so that strobe on for the shortest possible time
void c_PortRows_MCP23018::readCols(const uint8_t activeLowPin, c_Matrix *const cols)
//void c_PortRows_MCP23018::readCols(const uint8_t activeLowPin, c_PortsCols *const cols) todo, rename cols
{
    //strobe on
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal &= ~activeLowPin);       //strobe on: set strobe pin output to low
    Wire.endTransmission();

    cols->readPortsCols();                      //read the IC's column ports

    //strobe off
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal |= activeLowPin);        //strobe off: set strobe pin output to high
    Wire.endTransmission();
}
