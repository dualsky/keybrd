#ifndef C_PORTSROWS_H
#define C_PORTSROWS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortRows.h"

/* 
 */
class c_PortsRows
{
    private:
        c_PortRows *const *const ptrsRowPorts;        //array of ports connected to matrix row
        const uint8_t ROW_PORT_COUNT;

    public:
        c_PortsRows(c_PortRows *const p[], const uint8_t pc): ptrsRowPorts(p), ROW_PORT_COUNT(pc) {}
        //todo rename so that var ptrsRowPorts is more like type c_PortRows

        void begin();

        //scan matrix one time
        void scanPortsRows(c_PortsCols *const cols);
};
#endif
