#include "k_Key_LckLED.h"

void k_Key_LckLED::press()
{
    led.on();                   //todo: toggle LED like CapsLck
}

void k_Key_LckLED::release()
{
    led.off();
}
