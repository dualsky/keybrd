#include "c_LED_AVR.h"

void c_LED_AVR::on()
{
    PORT |= pin;                                //set pin high
}

void c_LED_AVR::off()
{
    PORT &= ~pin;                               //set pin low
}
