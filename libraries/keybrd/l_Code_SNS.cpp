#include "l_Code_SNS.h"

void l_Code_SNS::press()
{
    refShiftManager.releaseAllShifts();
    Keyboard.press(scancode);
    refShiftManager.restoreAllShifts();
}

void l_Code_SNS::release()
{
    Keyboard.release(scancode);
}
