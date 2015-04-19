#ifndef C_ROWPORT_H
#define C_ROWPORT_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Row_Ex.h"

class c_Matrix;

/* class c_RowPort is an abstract base class.
 * One IC port with some pins connected to matrix rows.
 * Port is read from pin 0 up.
 */
class c_RowPort
{ 
    private:
        const uint8_t PINS;                     //row pins to scan i.e. pins connected to rows

    public:
        static c_Row_Ex *const *const ptrsRows;//array of row pointers todo change to parent type c_Row
        //ROWS_COUNT not needed because rowN counts up untill all row pins are scanned

        c_RowPort(const uint8_t p): PINS(p) {}

        void begin() {} //derived classes for I/O expanders will override the begin() function

        void scan(c_Matrix *const matrix, uint8_t& rowN); //rowN is row number

        virtual void scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)=0;
};
#endif
