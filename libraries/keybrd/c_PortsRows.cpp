#include "c_PortsRows.h"

void c_PortsRows::begin()
{
    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->begin();                  //configure port
    }
}

void c_PortsRows::scanPortsRows(c_PortsCols *const cols)
{
    uint8_t rowN = 0;                           //row number

    //for every row port
    for (uint8_t i=0; i < ROW_PORT_COUNT; i++)
    {
        ptrsRowPorts[i]->scanPortRows(cols, rowN);
    }
}
