#ifndef K_KEY_LED_H
#define K_KEY_LED_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_Key.h"

/* Class k_Key turns LED on PORT pin on and off
MCP23018 ouput is open drain
 The output acts like a switch to ground.  It cannot produce a high (+5V) signal by itself.
 connect LED (-) ground to the output pin, and connect LED (+) to power pin,
 with resistor in series.
IODIRx Input/Ouput Direction register is configured as ouput in c_RowPort_MCP23018::begin()
LED tutorial https://www.pjrc.com/teensy/tutorial2.html
*/
class k_Key_LED_MCP23018: public c_Key
{
    private:
        c_IOExpanderPort& port;
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address
        const uint8_t pin;                      //bitwise pin to LED

    public:
        k_Key_LED_MCP23018(c_IOExpanderPort& ep, const uint8_t GPIO, const uint8_t p):
                port(ep), GPIO(GPIO), pin(p) {}

        //LED on when key is pressed
        void press();

        //LED off when key is released
        void release();
};
#endif
