#include "c_Matrix.h"

void c_Matrix::scanMatrix()
{
    uint8_t rowState;                           //state for row of switches, one bit per switch

    for (uint8_t i = 0; i < ROW_COUNT; i++)
        {
        rowState = scanRow(i);
        ptrsRows[i]->pressRelease(rowState);
        }
}

