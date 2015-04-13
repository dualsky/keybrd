#ifndef C_PORTSROWS_H
#define C_PORTSROWS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortRows.h"

/* all the microcontroller ports connected to matrix rows
 */
class c_PortsRows
{
    private:
        c_PortRows *const *const ports;        //array of ports connected to matrix row
        const uint8_t PORT_COUNT;

    public:
        c_PortsRows(c_PortRows *const p[], const uint8_t pc): ports(p), PORT_COUNT(pc) {}

        //scan matrix one time
        void scanPortsRows(c_PortsCols *const cols);
};
#endif
