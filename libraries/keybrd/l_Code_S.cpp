#include "l_Code_S.h"

void l_Code_S::press()
{
    Keyboard.press(scancode);
}

void l_Code_S::release()
{
    Keyboard.release(scancode);
}
