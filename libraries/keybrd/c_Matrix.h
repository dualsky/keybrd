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

c_Matrix is composed of row ports and col ports. todo update
port objects are chained in this sequence:
    1. c_PortsRows
    2. c_RowPort
    3. c_PortsCols
    4. c_ColPort
*/
class c_RowPort;

class c_Matrix
{
    private:
        c_RowPort *const *const ptrsRowPorts;   //array of row ports
        const uint8_t ROW_PORT_COUNT;

        c_ColPort *const *const ptrsColPorts;   //array of col ports
        const uint8_t COL_PORT_COUNT;

        c_Row_Ex *const *const ptrsRows;        //array of row pointers
       // todo change to parent type c_Row
        //ROWS_COUNT not needed because rowNum increments untill all row pins are scanned
        uint8_t rowNum;                           //index for ptrsRows[] array

    public:
        c_Matrix(c_Row_Ex *const r[],
                 c_RowPort *const rp[], const uint8_t rpc,
                 c_ColPort *const cp[], const uint8_t cpc):
                 ptrsRows(r),
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
