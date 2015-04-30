#include "c_ColPort_AVR_ActiveHigh.h"

c_ColPort_AVR_ActiveHigh::c_ColPort_AVR_ActiveHigh
    (volatile unsigned char& DDRx, volatile unsigned char& PORTx, volatile unsigned char& PINx, const uint8_t pins):
    DDR(DDRx = ~pins), PORT(PORTx = pins), PIN(PINx), c_ColPort(pins)
{}

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's ports are read and strobe is turned off.
*/
void c_ColPort_AVR_ActiveHigh::read()
{
    portState = ~PIN;
}
