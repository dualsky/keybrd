// Teensy 2.0
#ifndef C_M_TEENSY_H
#define C_M_TEENSY_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Matrix.h"
class c_Row_Ex;

/* Class c_Matrix_Teensy2 strobes portF and reads portB on the Teensy2 micro controller.
 *
 * The Teensy2 ports are wired to the Matrix.
 * portF pin numbers 0,1,    4,5,6,7 are wired to rows
 * portB pin numbers 0,1,2,3,4,5,6,7 are wired to columns
 *
 * ptrsRows and scanMatrix() are inherited from c_Matrix
 * Description of Teensy2 is in doc/wiring_teensy2_for_keybrd.md
 */
class c_Matrix_Teensy2: public c_Matrix
{
    public:
        c_Matrix_Teensy2(c_Row_Ex *const ptrsRows[], const uint8_t ROW_COUNT):
            c_Matrix(ptrsRows, ROW_COUNT) { }

        //begin() should be called once to initilize
        void begin();

        //scanRow() reads one row of matrix and returns state of 8 switches, one bit per switch
        uint8_t scanRow(const uint8_t rowN);
};
#endif
