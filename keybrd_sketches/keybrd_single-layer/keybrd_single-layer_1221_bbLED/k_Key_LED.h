#ifndef K_KEY_LED_H
#define K_KEY_LED_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "c_Key.h"

/* Class k_Key turns LED on PORT pin on and off
   LED tutorial https://www.pjrc.com/teensy/tutorial2.html
*/
class k_Key_LED: public c_Key
{
    private:
        volatile unsigned char& PORT;
        const uint8_t pin;

    public:
        k_Key_LED(volatile unsigned char& PORTx, const uint8_t p): PORT(PORTx), pin(p) { }

        //LED on when key is pressed
        void press();

        //LED off when key is released
        void release();
};
#endif
