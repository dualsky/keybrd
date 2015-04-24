#ifndef K_KEY_LED_AVR_H
#define K_KEY_LED_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"

/* Class k_Key_LED_AVR turns LED on PORT pin on and off
   DDRx Data Direction Register is configured as output in c_RowPort_AVR::begin()
   LED tutorial https://www.pjrc.com/teensy/tutorial2.html
*/
class k_Key_LED_AVR: public c_Key
{
    private:
        volatile unsigned char& PORT;
        const uint8_t pin;                      //bitwise pin to LED

    public:
        k_Key_LED_AVR(volatile unsigned char& PORTx, const uint8_t p): PORT(PORTx), pin(p) { }

        //LED on when key is pressed
        void press();

        //LED off when key is released
        void release();
};
#endif
