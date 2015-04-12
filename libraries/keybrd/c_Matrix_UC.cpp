#include "c_Matrix_UC.h"
/*
void c_Matrix_UC::begin()
{
    rows->begin();
}*/

void c_Matrix_UC::scanMatrix()
{
    rows->scanRowPorts(cols);
}
