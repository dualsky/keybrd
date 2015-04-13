#include "c_Matrix_AVR.h"

void c_Matrix_AVR::scanMatrix()
{
    rows->scanPortsRows(cols);
}
