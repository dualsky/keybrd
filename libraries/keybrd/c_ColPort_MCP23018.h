#ifndef C_COLPORT_MCP23018_H
#define C_COLPORT_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_IOExpanderPort.h"
#include "c_ColPort.h"

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 */
class c_ColPort_MCP23018 : public c_ColPort
{
    private:
        c_IOExpanderPort& port;
        const uint8_t IODIR;                    //Input/Ouput Direction register
        const uint8_t GPIO;                     //General Purpose Input/Ouput register
        const uint8_t GPPU;                     //General Purpose Pullup register
    public:
        //The constructor initialization list configures column port's IODIR, GPPU, GPIO, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port A columns:
        //      c_ColPort_MCP23018 colPortA(portA, 1<<0 | 1<<1 );
        //example instantiation for port B columns:
        //      c_ColPort_MCP23018 colPortB(portB, 1<<0 | 1<<1 );
        c_ColPort_MCP23018(c_IOExpanderPort& port, const uint8_t pins);

        //read port and store it in portState
        virtual void read();
};
#endif
