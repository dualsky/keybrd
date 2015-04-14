#include "c_PortRows.h"

//for each scan row, strobe the row and read it's columns
//then send the resulting rowState to c_Row for further processing
void c_PortRows::scanPortRows(c_PortsCols *const cols, uint8_t& rowN) //rowN is row number
{
    uint8_t pin;                                //active low for row being scanned, one bit per pin
    uint8_t rowState;                           //state of row's keys, one bit per col

    //for every pin of row port
    for ( pin = 1; pin > 0; pin <<= 1)     //shift pin until overflow
    {
        if (pin & pins)                         //if scan pin
        {
            readCols(pin, cols);
            rowState = cols->computeRowState();
            ptrsRows[rowN]->pressRelease(rowState);
            rowN++;                             //next row
        }
    }
}
