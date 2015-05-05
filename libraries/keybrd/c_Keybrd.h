#ifndef C_KEYBRD_H
#define C_KEYBRD_H
#include <Arduino.h>
#include "c_Matrix.h"

/* Class c_Keybrd is composed of one or more keyboard martrices.
 * Most one-peice keyboards have one matrix.
 * Most split keyboards have two matrices.
 */
class c_Keybrd
{
    private:
        c_Matrix *const *const ptrsMatrices;    //Keyb is composed of an array of matrix pointers
        const uint8_t MATRICES_COUNT;           //number of matrices in array

    public:
        c_Keybrd(c_Matrix *const ptrsMatrices[], const uint8_t MATRICES_COUNT)
            : ptrsMatrices(ptrsMatrices), MATRICES_COUNT(MATRICES_COUNT) { }

        // begin() should be called once to initilize
        void begin();

        // scan() periodically scans each matrix of keyb
        void scan();
};
#endif
