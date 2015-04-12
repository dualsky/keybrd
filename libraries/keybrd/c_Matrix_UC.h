#ifndef C_MATRIX_UC_H
#define C_MATRIX_UC_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Matrix.h"
#include "c_UCRowPorts.h"
//#include "c_UCColPorts.h"todo delete
class c_UCColPorts;

/* The keyboard's physical matrix is composed of rows and columns.
The rows and columns are connected to the keys.
The rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

c_Matrix_UC is composed of rows and cols.

objects are chained in this sequence:
    1. c_UCRowPorts
    2. c_UCRowPort
    3. c_UCColPorts
    4. c_UCColPort
*/
class c_Matrix_UC : public c_Matrix
{
    private:
        c_UCRowPorts *const rows;               //microcontroller ports connected to matrix rows
        c_UCColPorts *const cols;               //microcontroller ports connected to matrix columns

    public:
        c_Matrix_UC(c_UCRowPorts *const r, c_UCColPorts *const c): rows(r), cols(c) {}

        //initialize c_Matrix_UC object
        void begin();

        //scan matrix one time
        void scanMatrix();
};
#endif