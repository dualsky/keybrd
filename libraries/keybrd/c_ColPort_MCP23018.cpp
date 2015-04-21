#include "c_ColPort_MCP23018.h"

void c_ColPort_MCP23018::begin()
{
    //orig
    Wire.beginTransmission(ADDR);
    Wire.write(IODIR);
    Wire.write(PINS); //0=configure as output (for LED), 1=configure as input (for read)
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(GPPU);
    Wire.write(PINS); //0=configure pull-up disabled (for LED), 1=configure pull-up enabled (for read)
    Wire.endTransmission();
    //
/*port A debug
Wire.beginTransmission(ADDR);
Wire.write(0x00);                           //IODIRA Configuration Port A
Wire.write(~0);                             //as input
Wire.endTransmission();

Wire.beginTransmission(ADDR);
Wire.write(0x0C);                           //GPPUB pull-up Port A
Wire.write(~0);                             //pull-up enabled
Wire.endTransmission();    
*/
}

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's ports are read and strobe is turned off.
*/
void c_ColPort_MCP23018::read()
{
    //orig
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);                           //GPIO immediately before requestFrom
    Wire.endTransmission();

    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input port

    portState = Wire.read();

// Serial.print("\nportState = ");  Serial.print(portState, BIN);//all 1s, no low pin detected, A1 is grounded
//
/*port A debug
Wire.beginTransmission(ADDR);
Wire.write(0x12);                           //GPIOA (Port A immediately before requestFrom)
Wire.endTransmission();

Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input Port A

portState = Wire.read();
Serial.print("\nportState A = ");  Serial.print(portState, BIN);
*/
//while (true) {}    
}
