#include "c_RowPort_MCP23018.h"
#include "c_Matrix.h"                           //included in implementation because circular

void c_RowPort_MCP23018::begin()
{
    Wire.begin();
    
    Wire.beginTransmission(port.ADDR);
    Wire.write(IODIR);
    Wire.write(0);                            //0=configure as output (for strobe pins and LED pins)
    Wire.endTransmission();
}

/* scanRow strobes row using active low.
activeLowPin is one pin per bit, where active pin is 1.
Strobe is turned off after matrix reads the columns.
*/
void c_RowPort_MCP23018::scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe on
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal &= ~activeLowPin); //strobe on: set strobe pin output to low
    Wire.endTransmission();

    matrix->read();                             //read the IC's column ports

    //strobe off
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal |= activeLowPin); //strobe off: set strobe pin output to high
    Wire.endTransmission();
}
