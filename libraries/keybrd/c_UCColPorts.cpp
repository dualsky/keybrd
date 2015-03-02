#include "c_UCColPorts.h"

//read every column port
void c_UCColPorts::readColPorts()
{
    //for every row port
    for (uint8_t i=0; i < PORT_COUNT; i++)
    {
        ports[i]->readColPort();
    }
}

//return state of row's keys, one bit per column, where 1 means key is pressed
uint8_t c_UCColPorts::computeRowState()
{
    uint8_t colM = 1;                           //row mask, one bit per column
    uint8_t rowState = 0;                       //state of row's keys, one bit per column

    //for every row port
    for (uint8_t i=0; i < PORT_COUNT; i++)
    {
        ports[i]->portToRowState(colM, rowState);
    }
    return rowState;
}
