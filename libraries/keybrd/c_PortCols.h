#ifndef C_PORTCOLS_H
#define C_PORTCOLS_H
#include <Arduino.h>
#include <inttypes.h>

/* One IC port with some pins connected to matrix columns.
 * Port is read from pin 0 up.
 */
class c_PortCols
{
    protected:
        const uint8_t PINS;                     //col pins to read i.e. pins connected to columns
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        c_PortCols(const uint8_t p): PINS(p), portState(0) {}

        void begin() {}

        //read port and store it in portState
        virtual void readPortCols()=0;

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void portToRowState(uint8_t& col, uint8_t& rowState);
};
#endif
