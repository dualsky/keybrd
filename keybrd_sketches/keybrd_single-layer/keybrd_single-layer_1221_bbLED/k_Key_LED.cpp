#include "k_Key_LED.h"
//LED tutorial https://www.pjrc.com/teensy/tutorial2.html

void k_Key_LED::press()
{
    PORTB |= pin;                              //set pin high
}

void k_Key_LED::release()
{
    PORTB &= ~(pin);                           //set pin low
}
