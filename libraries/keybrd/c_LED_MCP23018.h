#ifndef C_LED_MCP23018_H
#define C_LED_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_LED.h"

/* Class c_LED_MCP23018 uses a MCP23018 I/O expander pin to turn a LED on and off.
c_RowPort or c_ColPort (whichever is used by LED) must be instantiated before c_LED_MCP23018 is instantiated.
This is because MCP23018 direction register is configured in the c_RowPort and c_ColPort constructors.

Connect the LED in series with the resistor:
    determin resistor value needed (Internet search: LED resistor value)
    Connect the LED's (-) ground to the AVR output pin
    connect LED's (+) to power
Never connect a LED directly from ground to power.  Doing so would destroy the LED.

MCP23018 ouput is open drain.  The output acts like a switch to ground.
It cannot produce a high signal by itself.
*/
class c_LED_MCP23018: public c_LED
{
    private:
        c_IOExpanderPort& port;
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_MCP23018(c_IOExpanderPort& port, const uint8_t pin)
            : port(port), GPIO(port.num + 0x12), pin(pin) {}

        virtual void on();

        virtual void off();
};
#endif
