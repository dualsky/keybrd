#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_ColPort.h"
#include "c_Row.h"

/* class c_Matrix
Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.

The keyboard's matrix is composed of rows and columns.
The rows and columns are physically connected to the keys.

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

        c_Row *const *const ptrsRows;           //array of row pointers
        const uint8_t ROW_COUNT;
        uint8_t rowNum;                         //index for ptrsRows[] array

    public:
        c_Matrix(c_RowPort *const ptrsRowPorts[], const uint8_t ROW_PORT_COUNT,
                 c_ColPort *const ptrsColPorts[], const uint8_t COL_PORT_COUNT,
                 c_Row *const ptrsRows[],const uint8_t ROW_COUNT)
            : ptrsRowPorts(ptrsRowPorts), ROW_PORT_COUNT(ROW_PORT_COUNT),
              ptrsColPorts(ptrsColPorts), COL_PORT_COUNT(COL_PORT_COUNT),
              ptrsRows(ptrsRows), ROW_COUNT(ROW_COUNT) {}

        //scanMatrix() scans each row of matrix one time
        void scan();

        //read every column port
        void read();

        //return state of row's keys, one bit per column, where 1 means key is pressed
        void processRow();
};
#endif
