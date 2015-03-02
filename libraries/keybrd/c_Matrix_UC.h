#ifndef C_MATRIX_UC_H
#define C_MATRIX_UC_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Matrix.h"
#include "c_UCRowPorts.h"
//#include "c_UCColPorts.h"todo delete
class c_UCColPorts;

/* the keyboard's matrix, is composed of rows and columns
 */
class c_Matrix_UC : public c_Matrix //0
{
    private:
        c_UCRowPorts *const rows;               //microcontroller ports connected to matrix rows
        c_UCColPorts *const cols;               //microcontroller ports connected to matrix columns

    public:
        c_Matrix_UC(c_UCRowPorts *const r, c_UCColPorts *const c): rows(r), cols(c) {}

        //dummy function for c_Keybrd::begin()
        void begin() { }
        
        //scan matrix one time
        void scanMatrix();
};
#endif
