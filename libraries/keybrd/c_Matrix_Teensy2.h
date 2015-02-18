#ifndef C_M_TEENSY_H
#define C_M_TEENSY_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Matrix.h"
class c_Row_Ex;

/* Class c_Matrix_Teensy2 strobes portF and reads portB on the Teensy2 micro controller.
 * ptrsRows and scanMatrix() are inherited from c_Matrix
 *
 * strobe portF pin names 0,1,    4,5,6,7 (pin numbers 21, 20, 19, 18, 17, 16)
 * read   portB pin names 0,1,2,3,4,5,6,7 (pin numbers 0, 1, 2, 3, 13, 14, 15, 4)
 * anode (banded end) of diodes point torwards port F
 * pinout diagram is in doc/connecting_teensy2_to_keyboard.md
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
