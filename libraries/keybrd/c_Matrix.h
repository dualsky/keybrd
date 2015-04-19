#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_PortCols.h"
#include "c_Row_Ex.h"

/* class c_Matrix
Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.

The keyboard's physical matrix is composed of rows and columns.
The rows and columns are connected to the keys.
The rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

c_Matrix is composed of row ports and col ports. todo update
port objects are chained in this sequence:
    1. c_PortsRows
    2. c_RowPort
    3. c_PortsCols
    4. c_PortCols
*/
class c_RowPort;

class c_Matrix
{
    private:
        c_RowPort *const *const ptrsRowPorts;  //array of row ports
        const uint8_t ROW_PORT_COUNT;

        c_PortCols *const *const ptrsColPorts;  //array of col ports
        const uint8_t COL_PORT_COUNT;

    public:
        c_Matrix(c_RowPort *const pr[], const uint8_t rpc,
                 c_PortCols *const pc[], const uint8_t cpc):
                 ptrsRowPorts(pr), ROW_PORT_COUNT(rpc),
                 ptrsColPorts(pc), COL_PORT_COUNT(cpc) {}

        //begin() initializes all row ports and col ports of matrix
        void begin();

        //scanMatrix() scans each row of matrix one time
        void scanMatrix();

        //read every column port
        void readPortsCols();

        //return state of row's keys, one bit per column, where 1 means key is pressed
        uint8_t computeRowState();
};
#endif
