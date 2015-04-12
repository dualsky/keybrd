#ifndef C_UCROWPORT_H
#define C_UCROWPORT_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_UCColPorts.h"
#include "c_Row_Ex.h"

/* One microcontroller port with pins connected to matrix rows
 * Port is scanned from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_UCRowPort
{ 
    private:
        volatile unsigned char& PORT;           //PORT register
        volatile unsigned char& DDR;            //Data Direction Register
        const uint8_t pins;                     //col pins to scan i.e. pins connected to rows

    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //example instantiation: c_UCRowPort rowPortF(PORTF, DDRF, 1<<1 );
        c_UCRowPort(volatile unsigned char& PORTx, volatile unsigned char& DDRx,
                const uint8_t pins):
                PORT(PORTx), DDR(DDRx |= pins), pins(pins) {}

        //initialize c_UCRowPort object
        //void begin();

        static c_Row_Ex *const *const ptrsRows;//todo change to parent type c_Row

        void scanRowPort(c_UCColPorts *const cols, uint8_t& rowN); //rowN is row number
};
#endif
