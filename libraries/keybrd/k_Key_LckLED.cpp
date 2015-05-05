#include "k_Key_LckLED.h"

/* in keybrd sketch, ports should be instantiated before k_Key_LckLED is instantiated
because LED.off() needs ports to be configured by port constructor
*/
k_Key_LckLED::k_Key_LckLED(const uint16_t scancode, c_LED& LED): scancode(scancode), LED(LED)
{
    LED.off();                   //todo: set LED to whatever CapsLck is
}

void k_Key_LckLED::press()
{
    Keyboard.press(scancode);
    LED.on();                   //todo: set LED to whatever CapsLck is
}

void k_Key_LckLED::release()
{
    Keyboard.release(scancode);
    LED.off();                  //todo: set LED to whatever CapsLck is
}
