#include "c_Matrix.h"

void c_Matrix::begin()
{
    //rows->begin();
    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->begin();                  //configure port
    }

    cols->begin();
}

void c_Matrix::scanMatrix()
{
    //rows->scanPortsRows(cols);
    uint8_t rowN = 0;                           //row number

    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->scanPortRows(cols, rowN);
    }
}
