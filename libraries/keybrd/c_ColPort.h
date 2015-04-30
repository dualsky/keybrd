#ifndef C_COLPORT_H
#define C_COLPORT_H
#include <Arduino.h>
#include <inttypes.h>

/* class c_ColPort is an abstract base class.
c_ColPort is part of one IC port.
c_ColPort is all the pins of one port that are connected to matrix cols.
c_ColPort is the parent, it has the pins; the port itself is with the children.
*/
class c_ColPort
{
    protected:
        const uint8_t pins;                     //col pins to read i.e. pins connected to columns
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        c_ColPort(const uint8_t p): pins(p), portState(0) {}

        //read port and store it in portState
        virtual void read()=0;

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void rowStateCat(uint8_t& rowState, uint8_t& colBit);
};
#endif
