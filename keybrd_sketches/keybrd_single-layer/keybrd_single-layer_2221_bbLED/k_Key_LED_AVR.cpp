#include "k_Key_LED_AVR.h"

void k_Key_LED_AVR::press()
{
    PORT |= pin;                                //set pin high
}

void k_Key_LED_AVR::release()
{
    PORT &= ~pin;                               //set pin low
}
