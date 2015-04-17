#include "c_PortRowsAVR.h"

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//only read the ports, so that strobe on for the shortest possible time
void c_PortRowsAVR::readCols(const uint8_t activeLowPin, c_PortsCols *const cols)
{
    //strobe on
    PORT &= ~activeLowPin;                      //set output to low

    cols->readPortsCols();                      //read the IC's column ports

    //strobe off
    PORT |= activeLowPin;                       //set output to high
}
