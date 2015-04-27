#ifndef C_LED_PCA9655E_H
#define C_LED_PCA9655E_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_LED.h"

/* Class c_LED_PCA9655E turns LED attached to PCA9655E I/O expander PORT pin on and off
   Input/Ouput Direction configuration is to to ouput in c_RowPort_PCA9655E::begin()
*/
class c_LED_PCA9655E: public c_LED
{
    private:
        c_IOExpanderPort& port;
        const uint8_t output;                   //General Purpose Input/Ouput register address
        const uint8_t pin;                      //bitwise pin to LED

    public:
        c_LED_PCA9655E(c_IOExpanderPort& port, const uint8_t p):
                port(port), output(port.num + 2), pin(p) {}

        virtual void on();

        virtual void off();
};
#endif
