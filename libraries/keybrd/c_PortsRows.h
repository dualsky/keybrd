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
        c_PortRows *const *const ptrsPorts;        //array of ports connected to matrix row
        const uint8_t PORT_COUNT;

    public:
        c_PortsRows(c_PortRows *const p[], const uint8_t pc): ptrsPorts(p), PORT_COUNT(pc) {}

        void begin();

        //scan matrix one time
        void scanPortsRows(c_PortsCols *const cols);
};
#endif
