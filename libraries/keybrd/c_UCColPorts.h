#ifndef C_UCCOLPORTS_H
#define C_UCCOLPORTS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_UCColPort.h"

/* all the microcontroller ports connected to matrix columns
 */
class c_UCColPorts //3
{
    private:
        c_UCColPort *const *const ports;        //array of ports connected to matrix columns
        const uint8_t PORT_COUNT;
    public:
        c_UCColPorts(c_UCColPort *const p[], const uint8_t pc): ports(p), PORT_COUNT(pc) {}

    //read every column port
    void readColPorts();

    //return state of row's keys, one bit per column, where 1 means key is pressed
    uint8_t computeRowState();
};
#endif
