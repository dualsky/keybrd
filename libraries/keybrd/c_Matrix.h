#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_ColPort.h"
#include "c_Row_Ex.h"

/* class c_Matrix
Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.

The keyboard's physical matrix is composed of rows and columns.
The rows and columns are connected to the keys.
The rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

c_Matrix is composed of row ports, col ports, and rows.
*/
class c_RowPort;

class c_Matrix
{
    private:
        c_RowPort *const *const ptrsRowPorts;   //array of row ports
        const uint8_t ROW_PORT_COUNT;

        c_ColPort *const *const ptrsColPorts;   //array of col ports
        const uint8_t COL_PORT_COUNT;

       // todo change to parent type c_Row
        c_Row_Ex *const *const ptrsRows;        //array of row pointers
        const uint8_t ROWS_COUNT;
        uint8_t rowNum;                         //index for ptrsRows[] array

    public:
        c_Matrix(c_Row_Ex *const r[],const uint8_t rc,//todo: move c_Row_Ex to end of param list
                 c_RowPort *const rp[], const uint8_t rpc,
                 c_ColPort *const cp[], const uint8_t cpc):
                 ptrsRows(r), ROWS_COUNT(rc),
                 ptrsRowPorts(rp), ROW_PORT_COUNT(rpc),
                 ptrsColPorts(cp), COL_PORT_COUNT(cpc) {}

        //begin() initializes all row ports and col ports of matrix
        void begin();

        //scanMatrix() scans each row of matrix one time
        void scan();

        //read every column port
        void read();

        //return state of row's keys, one bit per column, where 1 means key is pressed
        void processRow();
};
#endif
