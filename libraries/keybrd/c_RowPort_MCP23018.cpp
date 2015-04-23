#include "c_RowPort_MCP23018.h"
#include "c_Matrix.h"                           //included in implementation because circular

void c_RowPort_MCP23018::begin()
{
    Wire.begin();
    
    Wire.beginTransmission(ADDR);
    Wire.write(IODIR);
    Wire.write(0);                              //0=configure as output (for strobe PINS and LED)
    Wire.endTransmission();
}

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//only read the ports, so that strobe on for the shortest possible time
void c_RowPort_MCP23018::scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe on
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal &= ~activeLowPin);       //strobe on: set strobe pin output to low
    Wire.endTransmission();
//Serial.print("\nstrobe gpioVal=");  Serial.print(gpioVal, BIN);    

    matrix->read();                             //read the IC's column ports

    //strobe off
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal |= activeLowPin);        //strobe off: set strobe pin output to high
    Wire.endTransmission();

//Serial.print("  gpioVal=");  Serial.print(gpioVal, BIN);    
}
