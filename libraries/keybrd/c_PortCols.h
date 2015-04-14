#ifndef C_PORTCOLS_H
#define C_PORTCOLS_H
#include <Arduino.h>
#include <inttypes.h>

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_PortCols
{
    private:
        const uint8_t pins;                     //col pins to read i.e. pins connected to columns
    protected:
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        c_PortCols(const uint8_t pins): pins(pins), portState(0) {}

        //read port and store it in portState
        virtual void readPortCols()=0;

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void portToRowState(uint8_t& col, uint8_t& rowState);
};
#endif
