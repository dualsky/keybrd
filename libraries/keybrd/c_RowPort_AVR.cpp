#include "c_RowPort_AVR.h"
#include "c_Matrix.h"

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//only read the ports, so that strobe on for the shortest possible time
void c_RowPort_AVR::readCols(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe on
    PORT &= ~activeLowPin;                      //set output to low

    matrix->readPortsCols();                    //read the IC's column ports

    //strobe off
    PORT |= activeLowPin;                       //set output to high
}
