#include "l_Code_LckLED.h"

void l_Code_LckLED::begin()//todo: call begin from key::begin()
{
    LED.off();
}

void l_Code_LckLED::press()
{
    Keyboard.press(scancode);
    LED.on();                   //todo: toggle LED like CapsLck
}

void l_Code_LckLED::release()
{
    Keyboard.release(scancode);
    LED.off();
}
