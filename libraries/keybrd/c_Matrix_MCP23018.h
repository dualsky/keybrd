#ifndef C_M_MCP23018_H
#define C_M_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include <Wire.h>
#include "c_Matrix.h"
class c_Row_Ex;

/* Class c_Matrix_MCP23018 strobes portB and reads portA on the MCP23018 I/O expander.
 * ptrsRows and scanMatrix() are inherited from c_Matrix
 *
 * strobe portB (pin numbers  3 to 10)
 * read   portA (pin numbers 20 to 27)
 * anode (banded end) of diodes point torwards port B
 * pinout diagram is in doc/connecting_MCP23018_to_keyboard.md
 */
class c_Matrix_MCP23018: public c_Matrix
{
    private:
        //MCP23018 register addresses
        static const uint8_t addr = 0x20;       //0x20 is address when ADDR pin is grounded

        static const uint8_t gpioCol = 0x12;    //address of all general purpose pins on port A
        static const uint8_t gppuCol = 0x0C;    //internal-pull-up-resisters for port A

        static const uint8_t gpioRow = 0x13;    //address of all general purpose pins on port B
        static const uint8_t iodirRow = 0x01;   //I/O direction register for port B is input

    public:
        c_Matrix_MCP23018(c_Row_Ex *const ptrsRows[], const uint8_t ROW_COUNT):
            c_Matrix(ptrsRows, ROW_COUNT) { }

        //begin() should be called once to initilize
        void begin();

        //scanRow() reads one row of matrix and returns state of 8 switches, one bit per switch
        uint8_t scanRow(const uint8_t rowN);
};
#endif
