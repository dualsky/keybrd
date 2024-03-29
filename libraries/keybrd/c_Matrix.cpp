#include "c_Matrix.h"
#include "c_RowPort.h"                          //included in implementation because circular

//scan every row port
void c_Matrix::scan()
{
    rowNum = 0;

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
    uint8_t colBit = 1;                         //row mask for one col, start with col 0 and shift 
    uint8_t rowState = 0;                       //bitwise, 1 means key is pressed

    //computeRowState
    for (uint8_t i=0; i < COL_PORT_COUNT; i++)  //for each col port
    {
        ptrsColPorts[i]->rowStateCat(rowState, colBit);
    }

    ptrsRows[rowNum]->pressRelease(rowState);

    rowNum++;                                     //next row number
}
