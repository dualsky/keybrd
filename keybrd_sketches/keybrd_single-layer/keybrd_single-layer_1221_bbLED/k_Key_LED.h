#ifndef K_KEY_LED_H
#define K_KEY_LED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "c_Key.h"

/* Class k_Key is composed of one scancode, which it sends to USB when key is pressed or released.
 */
class k_Key_LED: public c_Key
{
    private:
        const uint16_t scancode;

    public:
        //k_Key_1(const uint16_t sc): scancode(sc) { }
        k_Key_LED(const uint16_t sc): scancode(sc) { }

        //send scancode to USB for press
        void press();

        //send scancode to USB for release
        void release();
};
#endif
