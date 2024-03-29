#ifndef C_COLPORT_AVR_H
#define C_COLPORT_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_ColPort.h"

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 */
class c_ColPort_AVR_ActiveHigh : public c_ColPort
{
    private:
        const volatile unsigned char& DDR;      //Data Direction Register, Direction: 0=Input
        const volatile unsigned char& PORT;     //PORT register
        const volatile unsigned char& PIN;      //PIN read register, Input: 1=Pullup Resistor
    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //DDRx 1=configure as output (for LED), 0=configure as input (for read)
        //example instantiation: c_ColPort_AVR_ActiveHigh portBCols(DDRB, PORTB, PINB, 1<<0 | 1<<1 );
        c_ColPort_AVR_ActiveHigh(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                volatile unsigned char& PINx, const uint8_t pins);

        //read port and store it in portState
        virtual void read();
};
#endif
