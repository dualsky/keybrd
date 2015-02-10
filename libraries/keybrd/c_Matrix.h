#ifndef C_MATRIX_H
#define C_MATRIX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Row_Ex.h"

/* class c_Matrix is an abstract base class.
 * Derived Matrix class contains pin numbers and registers for a Micro controller or I/O expander
 * Each Matrix is wired to a Micro controller or I/O expander, which scans and reads the matrix.
 */
class c_Matrix
{
    private:
        c_Row_Ex *const *const ptrsRows;        //matrix is composed of an array of rows
        const uint8_t ROW_COUNT;
    public:
        c_Matrix(c_Row_Ex *const pr[], const uint8_t rc): ptrsRows(pr), ROW_COUNT(rc) {}

        //begin() should be called once to initilize
        virtual void begin()=0;

        //scanRow() reads one row and returns state of 8 switches, one bit per switch
        virtual uint8_t scanRow(const uint8_t row)=0;

        //scanMatrix() scans each row of matrix
        void scanMatrix();
};
#endif
