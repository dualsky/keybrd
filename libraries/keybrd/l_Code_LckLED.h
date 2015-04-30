#ifndef L_CODE_LCKLED_H
#define L_CODE_LCKLED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"
#include "c_LED.h"

/* Class l_Code_LckLED is composed of a scancode and a c_LED.
*/
class l_Code_LckLED: public l_Code
{
    private:
        const uint16_t scancode;
        c_LED& LED;

    public:
        l_Code_LckLED(const uint16_t sc, c_LED& l): scancode(sc), LED(l) { }
        void press();
        void release();
};
#endif
