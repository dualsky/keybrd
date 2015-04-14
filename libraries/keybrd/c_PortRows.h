#ifndef C_PORTROWS_H
#define C_PORTROWS_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortsCols.h"
#include "c_Row_Ex.h"

/* class c_PortRows is an abstract base class.
 * IC port with pins connected to matrix rows
 * Port is scanned from pin 0 up.
 */
class c_PortRows
{ 
    public:
        static c_Row_Ex *const *const ptrsRows;//todo change to parent type c_Row

        virtual void scanPortRows(c_PortsCols *const cols, uint8_t& rowN)=0; //rowN is row number
};
#endif
