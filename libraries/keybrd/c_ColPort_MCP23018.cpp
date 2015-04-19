#include "c_ColPort_MCP23018.h"

void c_ColPort_MCP23018::begin()
{
    Wire.beginTransmission(ADDR);
    Wire.write(IODIR);
    Wire.write(PINS); //0=configure as output (for LED), 1=configure as input (for read)
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(GPPU);
    Wire.write(PINS); //0=configure pull-up disabled (for LED), 1=configure pull-up enabled (for read)
    Wire.endTransmission();
}

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's ports are read and strobe is turned off.
*/
void c_ColPort_MCP23018::readPortCols()
{
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);                           //GPIO immediately before requestFrom
    Wire.endTransmission();

    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input port

    portState = Wire.read();
}
