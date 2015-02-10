#include "l_Code_00.h"

//functions are similar to l_Code_SNS
void l_Code_00::press()
{
    refShiftManager.releaseAllShifts();
    Keyboard.press(KEY_0);
    Keyboard.release(KEY_0);
    Keyboard.press(KEY_0);
    refShiftManager.restoreAllShifts();
}

void l_Code_00::release()
{
    Keyboard.release(KEY_0);
}
