#ifndef K_KEY_LED_AVR_H
#define K_KEY_LED_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "c_LED.h"

/* Class k_Key_Lck_LED 
this is first version, later versions will also Lock Caps, Num, Scroll, and toggle the LED on/off
Class k_Key_Lck_LED turns LED on and off
*/
class k_Key_Lck_LED: public c_Key
{
    private:
        c_LED& led;

    public:
        k_Key_Lck_LED(c_LED& l): led(l) {}

        void begin();
        void press();
        void release();
};
#endif
