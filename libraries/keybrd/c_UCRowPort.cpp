#include "c_UCRowPort.h"

//for each scan row, strobe the row and read it's columns
//then send the resulting rowState to c_Row for further processing
void c_UCRowPort::scanRowPort(c_UCColPorts *const cols, uint8_t& rowN) //rowN is row number
{
    uint8_t pin;                                //pin mask, one bit per pin
    uint8_t rowState;                           //state of row's keys, one bit per col

    //for every pin of row port
    for ( pin = 1; pin > 0; pin = pin << 1)
    {
        if (pin & pins)                         //if scan pin
        {
            //strobe on
            DDR |= pins;                        //configure direction: 1=Output
            PORT &= ~pins;                      //set output: 0=Low Output

            cols->readColPorts();               //read the row's columns

            //strobe off
            DDR &= ~pins;                       //configure direction: 0=Input
            PORT &= ~pins;                      //configure input: 0=Normal

            //process rowState after strobe is turned off
            rowState = cols->computeRowState();
            ptrsRows[rowN]->pressRelease(rowState);
            rowN++;                             //next row
        }
    }
}
