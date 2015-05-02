#ifndef L_CODE_LCKLED_H
#define L_CODE_LCKLED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"
#include "c_LED.h"

/* Class l_Code_LckLED turns LED on and off
todo
This class is not finished, still need to find out how keyboard senses NumLck and CapsLck position
*/
class l_Code_LckLED: public l_Code
{
    private:
        const uint16_t scancode;
        c_LED& LED;

    public:
        //in keybrd sketch, ports should be instantiated before l_Code_LckLED is instantiated
        l_Code_LckLED(const uint16_t sc, c_LED& led);
        void press();
        void release();
};
#endif
