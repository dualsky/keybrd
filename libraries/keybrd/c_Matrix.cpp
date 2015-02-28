#include "c_Matrix.h"

void c_Matrix::scanMatrix()
{
    uint8_t switchStates;                           //state for row of keys, one bit per key

    for (uint8_t rowN = 0; rowN < ROW_COUNT; rowN++)
        {
        switchStates= scanRow(rowN);
        ptrsRows[rowN]->pressRelease(switchStates);
        }
}
