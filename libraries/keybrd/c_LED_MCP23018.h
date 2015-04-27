#ifndef C_LED_MCP23018_H
#define C_LED_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_LED.h"

/* Class c_LED_MCP23018 turns LED attached to MCP23018 I/O expander PORT pin on and off
   IODIRx Input/Ouput Direction register is configured as ouput in c_RowPort_MCP23018::begin()

   MCP23018 ouput is open drain
   The output acts like a switch to ground.  It cannot produce a high (+5V) signal by itself.
   connect LED (-) ground to the output pin, and connect LED (+) to power pin,
   with resistor in series.
*/
class c_LED_MCP23018: public c_LED
{
    private:
        c_IOExpanderPort& port;
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_MCP23018(c_IOExpanderPort& port, const uint8_t p):
                port(port), GPIO(port.num + 0x12), pin(p) {}

        virtual void on();

        virtual void off();
};
#endif
