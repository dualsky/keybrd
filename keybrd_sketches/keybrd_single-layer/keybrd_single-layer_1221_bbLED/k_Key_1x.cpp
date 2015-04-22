#include "k_Key_1x.h"

void k_Key_1x::press()
{
    Keyboard.press(scancode);
}

void k_Key_1x::release()
{
    Keyboard.release(scancode);
}
