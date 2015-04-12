#include "c_UCRowPorts.h"

void c_UCRowPorts::begin()
{
    //for every row port
    for (uint8_t i=0; i < PORT_COUNT; i++)
    {
        ports[i]->begin();
    }
}

void c_UCRowPorts::scanRowPorts(c_UCColPorts *const cols)
{
    uint8_t rowN = 0;                           //row number

    //for every row port
    for (uint8_t i=0; i < PORT_COUNT; i++)
    {
        ports[i]->scanRowPort(cols, rowN);
    }
}
