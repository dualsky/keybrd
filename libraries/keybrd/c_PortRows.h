#ifndef C_PORTROWS_H
#define C_PORTROWS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortsCols.h"
#include "c_Row_Ex.h"

/* class c_PortRows is an abstract base class.
 * IC port with pins connected to matrix rows.
 */
class c_PortRows
{ 
    private:
        const uint8_t pins;                     //col pins to scan i.e. pins connected to rows

    public:
        c_PortRows(const uint8_t pins): pins(pins) {}

        static c_Row_Ex *const *const ptrsRows;//array of row pointers todo change to parent type c_Row

        void scanPortRows(c_PortsCols *const cols, uint8_t& rowN); //rowN is row number

        virtual void readCols(uint8_t pin, c_PortsCols *const cols)=0;
};
#endif
