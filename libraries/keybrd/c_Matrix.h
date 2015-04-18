#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
//#include "c_PortsRows.h"
#include "c_PortRows.h"
#include "c_Row_Ex.h"

/* class c_Matrix
Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.

The keyboard's physical matrix is composed of rows and columns.
The rows and columns are connected to the keys.
The rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

c_Matrix is composed of row ports and col ports.
port objects are chained in this sequence:
    1. c_PortsRows
    2. c_PortRows
    3. c_PortsCols
    4. c_PortCols
*/
class c_Matrix
{
    private:
//        c_PortsRows *const rows;               //IC ports connected to matrix rows
        c_PortRows *const *const ptrsRowPorts;        //array of ports connected to matrix row
        const uint8_t ROW_PORT_COUNT;

        c_PortsCols *const cols;               //IC ports connected to matrix columns

    public:
        //c_Matrix(c_PortsRows *const r, c_PortsCols *const c): rows(r), cols(c) {}
        c_Matrix(c_PortRows *const p[], const uint8_t pc, c_PortsCols *const c):
            ptrsRowPorts(p), ROW_PORT_COUNT(pc), cols(c) {}
        //todo rename so that var ptrsRowPorts is more like type c_PortRows

        //dummy begin function
        void begin();

        //scanMatrix() scans each row of matrix one time
        void scanMatrix();
};
#endif
