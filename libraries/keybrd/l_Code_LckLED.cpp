#include "l_Code_LckLED.h"

/* in keybrd sketch, ports should be instantiated before l_Code_LckLED is instantiated
because LED.off() needs ports to be configured by port constructor
*/
l_Code_LckLED::l_Code_LckLED(const uint16_t sc, c_LED& led): scancode(sc), LED(led)
{
    LED.off();                   //todo: set LED to whatever CapsLck is
}

void l_Code_LckLED::press()
{
    Keyboard.press(scancode);
    LED.on();                   //todo: set LED to whatever CapsLck is
}

void l_Code_LckLED::release()
{
    Keyboard.release(scancode);
    LED.off();                  //todo: set LED to whatever CapsLck is
}
