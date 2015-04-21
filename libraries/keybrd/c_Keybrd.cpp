#include "c_Keybrd.h"

void c_Keybrd::begin()
{
    Keyboard.begin();
    Mouse.begin();

    for (uint8_t i = 0; i < MATRICES_COUNT; i++)
        {
        ptrsMatrices[i]->begin();
Serial.print("\nin c_Keybrd::begin()-matrix i="); Serial.print(i);
        }
}

void c_Keybrd::scan()
{
    for (uint8_t i = 0; i < MATRICES_COUNT; i++)
        {
        ptrsMatrices[i]->scan();
        }
}
