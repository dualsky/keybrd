#include "c_Matrix.h"
#include "c_RowPort.h"                          //included in implementation because circular

void c_Matrix::begin()
{
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)  //for each row port
    {
        ptrsRowPorts[i]->begin();               //configure port
    }

    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for each col port
    {
        ptrsColPorts[i]->begin();               //configure port
    }
}

//scan every row port
void c_Matrix::scan()
{
    rowN = 0;

    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)  //for each row port
    {
        ptrsRowPorts[i]->scan(this);
    }
}

//read every column port
void c_Matrix::read()
{
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for each col port
    {
        ptrsColPorts[i]->read();
    }
}

//return rowState
//rowState is state of row's keys, one bit per column, where 1 means key is pressed
//rowState is for an entire row, which may be contain multiple column ports
void c_Matrix::processRow()
{
    uint8_t colBit = 1;                         //row mask, one bit per column
    uint8_t rowState = 0;                       //bitwise, 1 means key is pressed

    //computeRowState
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for each col port
    {
        ptrsColPorts[i]->portToRowState(colBit, rowState);
    }

    ptrsRows[rowN]->pressRelease(rowState);

    rowN++;                                     //next row number
}
