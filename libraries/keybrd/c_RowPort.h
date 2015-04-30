#ifndef C_ROWPORT_H
#define C_ROWPORT_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Row.h"

class c_Matrix;

/* class c_RowPort is an abstract base class.
c_RowPort is part of one IC port.
c_RowPort is all the pins of one port that are connected to matrix rows.
c_RowPort is the parent, it has the pins; the port itself is with the children.
*/
class c_RowPort
{ 
    protected:
        const uint8_t pins;                     //row pins to scan i.e. pins connected to rows

    public:
        c_RowPort(const uint8_t p): pins(p) {}

        void scan(c_Matrix *const matrix);

        virtual void scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)=0;
};
#endif
