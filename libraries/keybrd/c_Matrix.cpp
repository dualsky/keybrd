#include "c_Matrix.h"
#include "c_RowPort.h"

void c_Matrix::begin()
{
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)  //for every row port
    {
        ptrsRowPorts[i]->begin();               //configure port
    }

    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for every col port
    {
        ptrsColPorts[i]->begin();               //configure port
    }
}

//scan every row port
void c_Matrix::scanMatrix()
{
    uint8_t rowN = 0;                           //row number

    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)  //for every row port
    {
        ptrsRowPorts[i]->scanPortRows(this, rowN);
    }
}

//read every column port
void c_Matrix::readPortsCols()
{
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for every col port
    {
        ptrsColPorts[i]->readPortCols();
    }
}

//return rowState
//rowState is state of row's keys, one bit per column, where 1 means key is pressed
//rowState is for an entire row, which may be contain multiple column ports
uint8_t c_Matrix::computeRowState()
{
    uint8_t colBit = 1;                         //row mask, one bit per column
    uint8_t rowState = 0;                       //bitwise, 1 means key is pressed

    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for every col port
    {
        ptrsColPorts[i]->portToRowState(colBit, rowState);
    }
    return rowState;
}
