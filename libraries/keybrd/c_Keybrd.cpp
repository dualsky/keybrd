#include "c_Keybrd.h"

void c_Keybrd::begin()
{
    Keyboard.begin();
    Mouse.begin();

    for (uint8_t i = 0; i < MATRICES_COUNT; i++)
        {
        ptrsMatrices[i]->begin();
        }
}

void c_Keybrd::scan()//rename scanMatrices
{
    for (uint8_t i = 0; i < MATRICES_COUNT; i++)
        {
        ptrsMatrices[i]->scan();
        }
}
