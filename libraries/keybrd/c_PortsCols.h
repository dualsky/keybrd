#ifndef C_PORTSCOLS_H
#define C_PORTSCOLS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortCols.h"

/* all the microcontroller ports connected to matrix columns
 */
class c_PortsCols
{
    private:
        c_PortCols *const *const ports;        //array of ports connected to matrix columns
        const uint8_t PORT_COUNT;
    public:
        c_PortsCols(c_PortCols *const p[], const uint8_t pc): ports(p), PORT_COUNT(pc) {}

    //read every column port
    void readColPorts();

    //return state of row's keys, one bit per column, where 1 means key is pressed
    uint8_t computeRowState();
};
#endif
