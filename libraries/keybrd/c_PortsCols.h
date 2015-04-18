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
        c_PortCols *const *const ptrsColPorts;        //array of ports connected to matrix columns
        const uint8_t COL_PORT_COUNT;
    public:
        c_PortsCols(c_PortCols *const p[], const uint8_t pc): ptrsColPorts(p), COL_PORT_COUNT(pc) {}

        void begin();

        //read every column port
        void readPortsCols();

        //return state of row's keys, one bit per column, where 1 means key is pressed
        uint8_t computeRowState();
};
#endif
