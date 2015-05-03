#include "c_RowPort_AVR.h"
#include "c_Matrix.h"                           //included in implementation because circular

c_RowPort_AVR::c_RowPort_AVR
        (volatile unsigned char& DDRx, volatile unsigned char& PORTx, const uint8_t pins):
        DDR(DDRx = ~0), PORT(PORTx), c_RowPort(pins)
{}

//strobe uses active low
//activeLowPin is one pin per bit, where active pin is 1
//strobe the row and read the columns
//(read result will be proccessed after strobe is off so that strobe on for the shortest possible time)
void c_RowPort_AVR::scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe row on
    PORT &= ~activeLowPin;                      //set output to low

    matrix->read();                             //read the IC's column ports

    //strobe row off
    PORT |= activeLowPin;                       //set output to high
}
