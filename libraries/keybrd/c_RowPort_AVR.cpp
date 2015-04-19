#include "c_RowPort_AVR.h"
#include "c_Matrix.h"                           //included in implementation because circular

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//only read the ports, so that strobe on for the shortest possible time
void c_RowPort_AVR::read(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe on
    PORT &= ~activeLowPin;                      //set output to low

    matrix->read();                    //read the IC's column ports

    //strobe off
    PORT |= activeLowPin;                       //set output to high
}
