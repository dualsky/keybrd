#include "k_Key_Lck_LED.h"

void k_Key_Lck_LED::begin()
{
    led.off();
}

void k_Key_Lck_LED::press()
{
    led.on();
}

void k_Key_Lck_LED::release()
{
    led.off();
}
