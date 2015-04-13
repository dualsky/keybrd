#ifndef C_PORTROWS_H
#define C_PORTROWS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortsCols.h"
#include "c_Row_Ex.h"

/* One microcontroller port with pins connected to matrix rows
 * Port is scanned from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_PortRows
{ 
    private:
        volatile unsigned char& DDR;            //Data Direction Register
        volatile unsigned char& PORT;           //PORT register
        const uint8_t pins;                     //col pins to scan i.e. pins connected to rows

    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //example instantiation: c_PortRows rowPortF(DDRF, PORTF, 1<<1 );
        c_PortRows(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                const uint8_t pins):
                DDR(DDRx |= pins), PORT(PORTx), pins(pins) {}

        static c_Row_Ex *const *const ptrsRows;//todo change to parent type c_Row

        void scanRowPort(c_PortsCols *const cols, uint8_t& rowN); //rowN is row number
};
#endif
