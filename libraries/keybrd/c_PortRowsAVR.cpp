#include "c_PortRowsAVR.h"

void c_PortRowsAVR::readCols(uint8_t pin, c_PortsCols *const cols) //rowN is row number
{
    //strobe on
    PORT &= ~pin;                               //set output to low

    cols->readPortsCols();                      //read the row's columns

    //strobe off
    PORT |= pin;                                //set output to high

    //process rowState after strobe is turned off
}
