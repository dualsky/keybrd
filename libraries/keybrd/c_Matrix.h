#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Row_Ex.h"

/* class c_Matrix is an abstract base class.
 * Derived Matrix class contains pin numbers and registers for a Micro controller or I/O expander
 * Each Matrix is connected to a Micro controller or I/O expander, which scans the matrix.
 */
class c_Matrix
{
    public:
        //begin() should be called once to initilize
        virtual void begin()=0;

        //scanMatrix() scans each row of matrix
        virtual void scanMatrix()=0;
};
#endif
