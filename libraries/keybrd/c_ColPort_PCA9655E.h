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
        const uint8_t configuration;            //Configuration byte command
        const uint8_t input;                    //input byte command
    public:
        //The constructor initialization list configures column port's configuration, input, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port 0 columns:
        //      c_ColPort_PCA9655E colPort0_L(port0, 0, 1<<0 | 1<<1 );
        //example instantiation for port 1 columns:
        //      c_ColPort_PCA9655E colPort1_L(port1, 1, 1<<0 | 1<<1 );
        c_ColPort_PCA9655E(c_IOExpanderPort& port, const uint8_t pins);

        //read port and store it in portState
        virtual void read();
};
#endif
