#include "c_PortRowsAVR.h"

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
void c_PortRowsAVR::readCols(uint8_t activeLowPin, c_PortsCols *const cols)
{
    //strobe on
    PORT &= ~activeLowPin;                      //set output to low

    cols->readPortsCols();                      //read the row's columns

    //strobe off
    PORT |= activeLowPin;                       //set output to high

    //process rowState after strobe is turned off
}
