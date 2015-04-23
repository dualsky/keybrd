#ifndef K_KEY_LED_H
#define K_KEY_LED_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
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
        const uint8_t ADDR;                     //I2C address
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address
        const uint8_t pin;
        uint8_t gpioVal;                        //value in GPIO register (for PINS and LEDs)

    public:
        k_Key_LED_MCP23018(const uint8_t ADDR, const uint8_t GPIO, const uint8_t p):
                ADDR(ADDR), GPIO(GPIO), pin(p), gpioVal(~0) {}
        //todo why initial value of gpioVal make no diff? LED always on with other pins

        //LED on when key is pressed
        void press();

        //LED off when key is released
        void release();
};
#endif
