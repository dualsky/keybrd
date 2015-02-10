#include "l_Code_SS.h"

void l_Code_SS::press()
{
    refShiftManager.pressShift0();
    Keyboard.press(scancode);
    refShiftManager.restoreShift0();
}

void l_Code_SS::release()
{
    Keyboard.release(scancode);
}
