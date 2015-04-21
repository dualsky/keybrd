#include "c_ColPort.h"

/* convert portState to RowState
read-pin values from portState and set them in rowState.
read-pins are identifed by "1" bit in the PINS varialbe, skip the "0" bits.
portState stores all pins values of port.
Some pins may not be connected to a column.
rowState stores only column values so that
rowState bits align with c_Row::prtKeys[] elements by column.
colBit is row mask, where current column bit is 1.
rowState is state of row's keys, where pressed key bit is 1.

converting portState to rowState is faster than requesting individual col bits from I/O expander.
*/
void c_ColPort::rowStateCat(uint8_t& rowState, uint8_t& colBit)
{
    uint8_t pin;                                //pin mask, one bit per pin

    //for each pin of port
    for ( pin = 1; pin > 0; pin <<= 1)          //shift pin until overflow
    {
        if (pin & PINS)                         //if pin is connected to column
        {
            if (pin & ~portState)               //if pin's key is pressed
            {
                rowState |= colBit;             //set rowState bit for this column
            }
            colBit <<= 1;                       //shift bit to next column
        }
    }
}
