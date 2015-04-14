#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortsRows.h"
#include "c_Row_Ex.h"

/* class c_Matrix is an abstract base class.
 * Derived Matrix class contains pin numbers and registers for a Micro controller or I/O expander
 * Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.
 */
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
class c_Matrix
{
    private:
        c_PortsRows *const rows;               //microcontroller ports connected to matrix rows
        c_PortsCols *const cols;               //microcontroller ports connected to matrix columns

    public:
        c_Matrix(c_PortsRows *const r, c_PortsCols *const c): rows(r), cols(c) {}

        //dummy begin function todo: why is this needed?
        void begin() {}

        //scanMatrix() scans each row of matrix one time
        void scanMatrix();
};
#endif
