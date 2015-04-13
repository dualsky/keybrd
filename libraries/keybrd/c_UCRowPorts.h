#ifndef C_UCROWPORTS_H
#define C_UCROWPORTS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_UCRowPort.h"

/* all the microcontroller ports connected to matrix rows
 */
class c_UCRowPorts
{
    private:
        c_UCRowPort *const *const ports;        //array of ports connected to matrix row
        const uint8_t PORT_COUNT;

    public:
        c_UCRowPorts(c_UCRowPort *const p[], const uint8_t pc): ports(p), PORT_COUNT(pc) {}

        //scan matrix one time
        void scanRowPorts(c_UCColPorts *const cols);
};
#endif
