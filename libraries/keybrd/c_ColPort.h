#ifndef C_COLPORT_H
#define C_COLPORT_H
#include <Arduino.h>
#include <inttypes.h>

/* One IC port with some pins connected to matrix columns.
 * Port is read from pin 0 up.
 */
class c_ColPort
{
    protected:
        const uint8_t pins;                     //col pins to read i.e. pins connected to columns
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        c_ColPort(const uint8_t p): pins(p), portState(0) {}

        virtual void begin() {} //derived classes for I/O expanders override the begin() function

        //read port and store it in portState
        virtual void read()=0;

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void rowStateCat(uint8_t& rowState, uint8_t& colBit);
};
#endif
