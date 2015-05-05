#ifndef K_KEY_LCKLED_H
#define K_KEY_LCKLED_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "c_LED.h"

/* Class k_Key_LckLED turns LED on and off
todo
This class is not finished, still need to find out how keyboard senses NumLck and CapsLck position
*/
class k_Key_LckLED: public c_Key
{
    private:
        const uint16_t scancode;
        c_LED& LED;

    public:
        k_Key_LckLED(const uint16_t sc, c_LED& LED);

        void press();
        void release();
};
#endif
