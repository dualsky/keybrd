#include "c_PortRows.h"
#include "c_Matrix.h"

//for each scan row, read columns and send the resulting rowState to c_Row for further processing
void c_PortRows::scanPortRows(c_Matrix *const cols, uint8_t& rowN) //rowN is row number
{
    uint8_t pin;                                //active low for row being scanned, one bit per pin
    uint8_t rowState;                           //state of row's keys, one bit per col

    //for every pin of row port
    for ( pin = 1; pin > 0; pin <<= 1)          //shift pin until overflow
    {
        if (pin & PINS)                         //if scan pin
        {
            readCols(pin, cols);
            rowState = cols->computeRowState();
            ptrsRows[rowN]->pressRelease(rowState);
            rowN++;                             //next row
        }
    }
}
