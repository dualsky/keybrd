#include "c_Keybrd.h"

void c_Keybrd::begin()
{
    Keyboard.begin();
    Mouse.begin();
}

void c_Keybrd::scan()
{
    for (uint8_t i = 0; i < MATRICES_COUNT; i++)
        {
        ptrsMatrices[i]->scan();
        }
}
