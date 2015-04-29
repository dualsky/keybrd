#ifndef C_LED_AVR_H
#define C_LED_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_LED.h"

/* Class c_LED_AVR turns LED on and off
The LED is attached to AVR PORT pin
DDRx Data Direction Register is configured as output in c_RowPort_AVR::begin()
LED tutorial https://www.pjrc.com/teensy/tutorial2.html
*/
class c_LED_AVR: public c_LED
{
    private:
        volatile unsigned char& PORT;
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_AVR(volatile unsigned char& PORTx, const uint8_t p): PORT(PORTx), pin(p) {}

        virtual void on();

        virtual void off();
};
#endif
