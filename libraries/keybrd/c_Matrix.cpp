#include "c_Matrix.h"
#include "c_PortRows.h"

void c_Matrix::begin()
{
    //rows->begin();
    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->begin();                  //configure port
    }

    //cols->begin();
    //for every row port
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)
    {
        ptrsColPorts[i]->begin();                      //configure port
    }
}

void c_Matrix::scanMatrix()
{
    //rows->scanPortsRows(cols);
    uint8_t rowN = 0;                           //row number

    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->scanPortRows(this, rowN);
    }
}

//read every column port
void c_Matrix::readPortsCols()
{
    //for every col port
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)
    {
        ptrsColPorts[i]->readPortCols();
    }
}

//return state of row's keys, one bit per column, where 1 means key is pressed
//rowState is for an entire row, which may be determined by multiple column ports
uint8_t c_Matrix::computeRowState()
{
    uint8_t colBit = 1;                         //row mask, one bit per column
    uint8_t rowState = 0;                       //state of row's keys, one bit per column

    for (uint8_t i=0; i < COL_PORT_COUNT; i++)      //for every col port
    {
        ptrsColPorts[i]->portToRowState(colBit, rowState);
    }
    return rowState;
}
