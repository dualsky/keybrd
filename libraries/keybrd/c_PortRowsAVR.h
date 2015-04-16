#ifndef C_PORTROWSAVR_H
#define C_PORTROWSAVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortRows.h"
#include "c_PortsCols.h"
#include "c_Row_Ex.h"

class c_PortRowsAVR : public c_PortRows
{ 
    private:
        volatile unsigned char& DDR;            //Data Direction Register
        volatile unsigned char& PORT;           //PORT register

    public:
        //The constructor initialization list configures column's DDRx and PORTx to output strobe.
        //example instantiation: c_PortRowsAVR portFRows(DDRF, PORTF, 1<<1 );
        c_PortRowsAVR(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                const uint8_t PINS):
            DDR(DDRx |= PINS), PORT(PORTx), c_PortRows(PINS) {}

        virtual void readCols(const uint8_t activeLowPin, c_PortsCols *const cols);
};
#endif
