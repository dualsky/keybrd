#include "k_Key_1.h"

void k_Key_1::press()
{
    Keyboard.press(scancode);
}

void k_Key_1::release()
{
    Keyboard.release(scancode);
}
