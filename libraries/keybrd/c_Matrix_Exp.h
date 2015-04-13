#ifndef C_M_EXP_H
#define C_M_EXP_H
#include <Arduino.h>
#include <inttypes.h>
#include <Wire.h>
#include "c_Matrix.h"
class c_Row_Ex;
//todo: rewrite documentation, copy much from c_Matrix_AVR.h
//todo: update connecting_MCP23018_to_keyboard.md ##keybrd sketch c_Matrix_Exp parameters

/* Class c_Matrix_Exp strobes portB and reads portA on the MCP23018 I/O expander.
 * ptrsRows and scanMatrix() are inherited from c_Matrix
 *
 * strobe portB (pin numbers  3 to 10)
 * read   portA (pin numbers 20 to 27)
 * anode (banded end) of diodes point torwards port B
 * pinout diagram is in doc/connecting_MCP23018_to_keyboard.md
 */
class c_Matrix_Exp: public c_Matrix
{
    private:
        //register addresses todo: change const to caps
        const uint8_t addr;       //the 7-bit address of the I2C slave device to transmit to

        const uint8_t gpioCol;    //address of all general purpose pins on port A
        const uint8_t gppuCol;    //internal-pull-up-resisters for port A

        const uint8_t gpioRow;    //address of all general purpose pins on port B
        const uint8_t iodirRow;   //I/O direction register for port B is input

        //scanRow() reads one row of matrix and returns state of 8 switches, one bit per switch
        uint8_t scanRow(const uint8_t rowN);

        c_Row_Ex *const *const ptrsRows;        //row pointers array
        const uint8_t ROW_COUNT;

    public:
        c_Matrix_Exp(c_Row_Ex *const pr[], const uint8_t rc, const uint8_t addr,
               const uint8_t gpioCol, const uint8_t gppuCol,
               const uint8_t gpioRow, const uint8_t iodirRow):
            ptrsRows(pr), ROW_COUNT(rc), addr(addr),
            gpioCol(gpioCol), gppuCol(gppuCol),
            gpioRow(gpioRow), iodirRow(iodirRow) {}

        //begin() should be called once to initilize
        void begin();

        void scanMatrix();
};
#endif
