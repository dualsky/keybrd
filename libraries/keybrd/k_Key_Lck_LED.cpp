#include "k_Key_Lck_LED.h"
//todo rename to k_Key_LckLED, add scancode press/release similar to k_Key1

void k_Key_Lck_LED::press()
{
    led.on();
}

void k_Key_Lck_LED::release()
{
    led.off();
}
