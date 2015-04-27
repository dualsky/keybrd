#ifndef C_ROWPORT_AVR_H
#define C_ROWPORT_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_RowPort.h"

class c_Matrix;

class c_RowPort_AVR : public c_RowPort
{ 
    private:
        volatile unsigned char& DDR;            //Data Direction Register
        volatile unsigned char& PORT;           //PORT register

    public:
        //The constructor initialization list configures column's DDRx and PORTx to output strobe.
        //configure all pins as output (for strobe pins and LED)
        //example instantiation: c_RowPort_AVR portFRows(DDRF, PORTF, 1<<1 );
        c_RowPort_AVR(volatile unsigned char& DDRx, volatile unsigned char& PORTx,
                const uint8_t pins):
            DDR(DDRx = ~0), PORT(PORTx), c_RowPort(pins) {}//todo old DDR(DDRx |= pins)

        virtual void scanRow(const uint8_t activeLowPin, c_Matrix *const matrix);
};
#endif
