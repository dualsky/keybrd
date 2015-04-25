#ifndef C_COLPORT_PCA9655E_H
#define C_COLPORT_PCA9655E_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_ColPort.h"

/* One microcontroller port with pins connected to matrix columns.
Port is read from pin 0 up.
*/
class c_ColPort_PCA9655E : public c_ColPort
{
    private:
        c_IOExpanderPort& port;
        const uint8_t configuration;            //Input/Ouput Direction register
        const uint8_t input;                    //General Purpose Input/Ouput register
    public:
        //The constructor initialization list configures column port's configuration, input, and PINS.
        //parameter PINS is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port A columns:
        //      c_ColPort_PCA9655E colPortA(portA, 0x00, 0x12, 0x0C, 1<<0 | 1<<1 );
        //example instantiation for port B columns:
        //      c_ColPort_PCA9655E colPortB(portB, 0x01, 0x13, 0x0D, 1<<0 | 1<<1 );
        c_ColPort_PCA9655E(c_IOExpanderPort& ep, const uint8_t configurationx,
                const uint8_t inputx, const uint8_t PINS):
            port(ep), configuration(configurationx), input(inputx), c_ColPort(PINS) {}

        void begin();

        //read port and store it in portState
        virtual void read();
};
#endif
