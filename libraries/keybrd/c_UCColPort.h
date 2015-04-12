#ifndef C_UCCOLPORT_H
#define C_UCCOLPORT_H
#include <Arduino.h>
#include <inttypes.h>

/* One microcontroller port with pins connected to matrix columns.
 * The constructor initialization list configures column's DDRx and PORTx to read Input.
 * Port is read from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_UCColPort
{
    private:
        const volatile unsigned char& PORT;     //PORT register
        const volatile unsigned char& DDR;      //Data Direction Register, Direction: 0=Input
        const volatile unsigned char& PIN;      //PIN read register, Input: 1=Pullup Resistor
        const uint8_t pins;                     //port pins to read i.e. pins connected to columns
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        c_UCColPort(volatile unsigned char& p, volatile unsigned char& d,
                volatile unsigned char& pn, const uint8_t pins):
            PORT(p |= pins), DDR(d &= ~pins), PIN(pn), pins(pins), portState(0) {}

        //read port and store it in portState
        void readColPort();

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void portToRowState(uint8_t& col, uint8_t& rowState);
};
#endif
