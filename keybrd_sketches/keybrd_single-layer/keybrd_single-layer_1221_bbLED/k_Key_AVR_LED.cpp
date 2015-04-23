#include "k_Key_LED.h"

void k_Key_LED::press()
{
    PORT |= pin;                                //set pin high
}

void k_Key_LED::release()
{
    PORT &= ~pin;                             //set pin low
}
