#include "c_PortsCols.h"

void c_PortsCols::begin()
{
    //for every row port
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)
    {
        ptrsColPorts[i]->begin();                      //configure port
    }
}

//read every column port
void c_PortsCols::readPortsCols()
{
    //for every col port
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)
    {
        ptrsColPorts[i]->readPortCols();
    }
}

//return state of row's keys, one bit per column, where 1 means key is pressed
//rowState is for an entire row, which may be determined by multiple column ports
uint8_t c_PortsCols::computeRowState()
{
    uint8_t colBit = 1;                         //row mask, one bit per column
    uint8_t rowState = 0;                       //state of row's keys, one bit per column

    for (uint8_t i=0; i < COL_PORT_COUNT; i++)      //for every col port
    {
        ptrsColPorts[i]->portToRowState(colBit, rowState);
    }
    return rowState;
}
