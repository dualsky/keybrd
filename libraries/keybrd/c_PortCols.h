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
        const volatile unsigned char& DDR;      //Data Direction Register, Direction: 0=Input
        const volatile unsigned char& PORT;     //PORT register
        const volatile unsigned char& PIN;      //PIN read register, Input: 1=Pullup Resistor
        const uint8_t pins;                     //col pins to read i.e. pins connected to columns
        uint8_t portState;                      //state of port pins on most recent reading
    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //example instantiation: c_PortCols colPortB(DDRB, PORTB, PINB, 1<<0 | 1<<1 );
        c_PortCols(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                volatile unsigned char& PINx, const uint8_t pins):
            DDR(DDRx &= ~pins), PORT(PORTx |= pins), PIN(PINx), pins(pins), portState(0) {}

        //read port and store it in portState
        void readPortCols();

        //copy only read-pin values from portState to rowState.
        //col is row mask, where current column bit is 1.
        //rowState is state of row's keys, where pressed key bit is 1.
        void portToRowState(uint8_t& col, uint8_t& rowState);
};
#endif
