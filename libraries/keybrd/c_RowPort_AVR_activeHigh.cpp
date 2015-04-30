#include "c_RowPort_AVR_ActiveHigh.h"
#include "c_Matrix.h"                           //included in implementation because circular

/* strobe uses active high
activeHighPin is one pin per bit, where active pin is 1
strobe the row and read the columns
(read result will be proccessed after strobe off, so that strobe is on for shortest possible time)

The delayMicroseconds() is for DodoHand keyboard's optic switches.
Strobe needs to be turned on for >= 300us before the columns are read.
During this time the state of the columns are settling into their actual values.
Seems to be necessary in order to allow the phototransistors to turn completely off.
(delay is not need for I/O expander because time between I2C Transmissions)
*/

c_RowPort_AVR_ActiveHigh::c_RowPort_AVR_ActiveHigh
    (volatile unsigned char& DDRx, volatile unsigned char& PORTx, const uint8_t pins):
    DDR(DDRx = ~0), PORT(PORTx), c_RowPort(pins)
{}

void c_RowPort_AVR_ActiveHigh::scanRow(const uint8_t activeHighPin, c_Matrix *const matrix)
{
    //strobe row on
    PORT |= activeHighPin;                      //set output to high
    delayMicroseconds(300);                     //wait for the column value to stabilize

    matrix->read();                             //read the IC's column ports

    //strobe row off
    PORT &= ~activeHighPin;                     //set output to low
}
