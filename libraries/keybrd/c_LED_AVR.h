#ifndef C_LED_AVR_H
#define C_LED_AVR_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_LED.h"

/* Class c_LED_AVR uses an AVR pin to power a LED on and off.

Connect the LED in series with the resistor:
    determin resistor value needed (Internet search: LED resistor value)
    Connect the LED's (-) ground to ground
    connect LED's (+) to the AVR output pin
Never connect a LED directly from ground to power.  Doing so would destroy the LED.

DDRx Data Direction Register is configured as output in c_RowPort_AVR constructor.
*/
class c_LED_AVR: public c_LED
{
    private:
        volatile unsigned char& PORT;
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_AVR(volatile unsigned char& PORTx, const uint8_t pin): PORT(PORTx), pin(pin) {}

        virtual void on();

        virtual void off();
};
#endif
