#include "c_ColPort_PCA9655E.h"

c_ColPort_PCA9655E::c_ColPort_PCA9655E(c_IOExpanderPort& port, const uint8_t pins):
            port(port), configuration(port.num + 6), input(port.num), c_ColPort(pins)
{
    Wire.begin();
    
    Wire.beginTransmission(port.ADDR);
    Wire.write(configuration);
    Wire.write(pins);       //0=configure as output (for LED), 1=configure as input (for read)
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

    Wire.requestFrom(port.ADDR, 1u);            //request one byte from input port

    portState = Wire.read();
}
