#ifndef C_MATRIX_AVR_H
#define C_MATRIX_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Matrix.h"
#include "c_PortsRows.h"

class c_PortsCols;

/* The keyboard's physical matrix is composed of rows and columns.
The rows and columns are connected to the keys.
The rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

c_Matrix_AVR is composed of rows and cols.

objects are chained in this sequence:
    1. c_PortsRows
    2. c_PortRows
    3. c_PortsCols
    4. c_PortCols
*/
class c_Matrix_AVR : public c_Matrix
{
    private:
        c_PortsRows *const rows;               //microcontroller ports connected to matrix rows
        c_PortsCols *const cols;               //microcontroller ports connected to matrix columns

    public:
        c_Matrix_AVR(c_PortsRows *const r, c_PortsCols *const c): rows(r), cols(c) {}

        //dummy begin function todo: why is this needed?
        void begin() {}

        //scan matrix one time
        void scanMatrix();
};
#endif
