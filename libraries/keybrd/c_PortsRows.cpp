#include "c_PortsRows.h"

void c_PortsRows::scanRowPorts(c_PortsCols *const cols)
{
    uint8_t rowN = 0;                           //row number

    //for every row port
    for (uint8_t i=0; i < PORT_COUNT; i++)
    {
        ports[i]->scanRowPort(cols, rowN);
    }
}
