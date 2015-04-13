#include "c_PortCols.h"

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be read one pin at a time in portToRowState() after strobe is turned off.
*/
void c_PortCols::readPortCols()
{
    portState = PIN;
}

/* Copy only read-pin values from portState to rowState.
portState stores all pins values of port.
Some pins may not be connected to a column.
rowState stores only column values so that
rowState bits align with c_Row::prtKeys[] elements by column.
colBit is row mask, where current column bit is 1.
rowState is state of row's keys, where pressed key bit is 1.
*/
void c_PortCols::portToRowState(uint8_t& colBit, uint8_t& rowState)
{
    uint8_t pin;                                //pin mask, one bit per pin

    //for every pin of port
    for ( pin = 1; pin > 0; pin = pin << 1)     //shift pin until overflow
    {
        if (pin & pins)                         //if column pin
        {
            if (pin & ~portState)               //if pin's key is pressed
            {
                rowState |= colBit;             //set rowState bit for this column
            }
            colBit = colBit << 1;               //shift bit to next column
        }
    }
}
