#include "k_Key_LED.h"
//LED tutorial https://www.pjrc.com/teensy/tutorial2.html

void k_Key_LED::press()
{
    //Keyboard.press(scancode);
    PORTB |= 1<<3;                              //set pin high
}

void k_Key_LED::release()
{
    //Keyboard.release(scancode);
    PORTB &= ~(1<<3);                           //set pin low
}
