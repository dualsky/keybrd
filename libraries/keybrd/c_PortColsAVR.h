#ifndef C_PORTCOLSAVR_H
#define C_PORTCOLSAVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortCols.h"

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_PortColsAVR : public c_PortCols
{
    private:
        const volatile unsigned char& DDR;      //Data Direction Register, Direction: 0=Input
        const volatile unsigned char& PORT;     //PORT register
        const volatile unsigned char& PIN;      //PIN read register, Input: 1=Pullup Resistor
        //const uint8_t pins;                     //col pins to read i.e. pins connected to columns
        //uint8_t portState;                      //state of port pins on most recent reading
    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //example instantiation: c_PortColsAVR portBCols(DDRB, PORTB, PINB, 1<<0 | 1<<1 );
        c_PortColsAVR(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                volatile unsigned char& PINx, const uint8_t pins):
            DDR(DDRx &= ~pins), PORT(PORTx |= pins), PIN(PINx), c_PortCols(pins) {}

        //read port and store it in portState
        virtual void readPortCols();
};
#endif