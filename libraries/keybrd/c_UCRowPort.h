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
        const uint8_t pins;                     //port pins to scan i.e. pins connected to rows

    public:
        c_UCRowPort(volatile unsigned char& p, volatile unsigned char& d, const uint8_t pns):
                PORT(p), DDR(d), pins(pns) {}
        static c_Row_Ex *const *const ptrsRows;//todo change to parent type c_Row

        void scanRowPort(c_UCColPorts *const cols, uint8_t& rowN); //rowN is row number
};
#endif
