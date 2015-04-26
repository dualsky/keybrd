#include "c_ColPort_PCA9655E.h"

void c_ColPort_PCA9655E::begin()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(configuration);
    Wire.write(PINS);       //0=configure as output (for LED), 1=configure as input (for read)
    Wire.endTransmission();

    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    //Wire.write(port.outputVal = PINS);        //set LED pins low, sometimes breaks bot row
    Wire.write(port.outputVal = 0);           //set LED pins low, sometimes breaks bot row
    //Wire.write(port.outputVal = ~PINS);       //set LED pins low, initial green on
    //Wire.write(port.outputVal = ~0);          //set LED pins low, initial green on
    Wire.endTransmission();
}

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's col ports are read and strobe is turned off.
*/
void c_ColPort_PCA9655E::read()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(input);                          //input immediately before requestFrom
    Wire.endTransmission(false);                //PCA9655E needs false to send a restart

    Wire.requestFrom(port.ADDR, static_cast<uint8_t>(1)); //request one byte from input port

    portState = Wire.read();
}
