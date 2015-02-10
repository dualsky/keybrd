#include "l_Code_Shift.h"

void l_Code_Shift::press()
{
    KBShifted = true;
    syncOSShifted(true);
}

void l_Code_Shift::release()
{
    KBShifted = false;
    syncOSShifted(false);
}

void l_Code_Shift::restoreKBShifted()
{
    syncOSShifted(KBShifted);
}

void l_Code_Shift::syncOSShifted(bool shifted)
{
    //if shifted and OSShifted are out of sync, send scancode
    if (shifted && !OSShifted)
        {
        Keyboard.press(scancode);
        OSShifted = true;
        }
    else if (!shifted && OSShifted)
        {
        Keyboard.release(scancode);
        OSShifted = false;
        }
}
