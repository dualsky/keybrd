#ifndef K_KEY_LCKLED_H
#define K_KEY_LCKLED_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "c_LED.h"

/* Class k_Key_LckLED 
this is first version, later versions will also Lock Caps, Num, Scroll, and toggle the LED on/off
Class k_Key_LckLED turns LED on and off
*/
class k_Key_LckLED: public c_Key
{
    private:
        c_LED& led;

    public:
        k_Key_LckLED(c_LED& led): led(led) {}

        void press();
        void release();
};
#endif
