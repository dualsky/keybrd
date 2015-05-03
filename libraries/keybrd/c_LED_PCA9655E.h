#ifndef C_LED_PCA9655E_H
#define C_LED_PCA9655E_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_LED.h"

/* Class c_LED_PCA9655E uses a PCA9655E I/O expander pin to turn a LED on and off.
In keybrd sketch, c_RowPort_PCA9655E instantiation must come before c_LED_PCA9655E instantiation.
This is because PCA9655E direction register is configured in the c_RowPort_PCA9655E constructor.

Connect the LED in series with the resistor:
    determin resistor value needed (Internet search: LED resistor value)
    Connect the LED's (-) ground to ground
    connect LED's (+) to the AVR output pin
Never connect a LED directly from ground to power.  Doing so would destroy the LED.

The LED is attached to PCA9655E I/O expander PORT pin 
Input/Ouput Direction configuration is to to ouput in c_RowPort_PCA9655E constructor
*/
class c_LED_PCA9655E: public c_LED
{
    private:
        c_IOExpanderPort& port;
        const uint8_t output;                   //General Purpose Input/Ouput register address
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_PCA9655E(c_IOExpanderPort& port, const uint8_t pin):
                port(port), output(port.num + 2), pin(pin) {}

        virtual void on();

        virtual void off();
};
#endif
