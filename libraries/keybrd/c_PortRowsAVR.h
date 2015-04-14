#ifndef C_PORTROWSAVR_H
#define C_PORTROWSAVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortRows.h"
//#include "c_PortsColsAVR.h"
#include "c_PortsCols.h"
#include "c_Row_Ex.h"

/* One microcontroller port with pins connected to matrix rows
 * Port is scanned from pin 0 up.
 * https://www.pjrc.com/teensy/pins.html explains registers
 */
class c_PortRowsAVR : public c_PortRows
{ 
    private:
        volatile unsigned char& DDR;            //Data Direction Register
        volatile unsigned char& PORT;           //PORT register

    public:
        //The constructor initialization list configures column's DDRx and PORTx to read Input.
        //example instantiation: c_PortRowsAVR portFRows(DDRF, PORTF, 1<<1 );
        c_PortRowsAVR(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                const uint8_t pins):
            DDR(DDRx |= pins), PORT(PORTx), c_PortRows(pins) {}

        //static c_Row_Ex *const *const ptrsRows;//todo change to parent type c_Row

        virtual void readCols(uint8_t pin, c_PortsCols *const cols);
};
#endif
