#ifndef C_COLPORT_MCP23018_H
#define C_COLPORT_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_ColPort.h"

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 */
class c_ColPort_MCP23018 : public c_ColPort
{
    private:
        const uint8_t ADDR;                     //I2C address
        const uint8_t IODIR;                    //Input/Ouput Direction register
        const uint8_t GPIO;                     //General Purpose Input/Ouput register
        const uint8_t GPPU;                     //General Purpose Pullup register
    public:
        //The constructor initialization list configures column port's IODIR, GPPU, GPIO, and PINS.
        //parameter PINS is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port A columns:
        //      c_ColPort_MCP23018 colPortA(0x20, 0x00, 0x12, 0x0C, 1<<0 | 1<<1 );
        //example instantiation for port B columns:
        //      c_ColPort_MCP23018 colPortB(0x20, 0x01, 0x13, 0x0D, 1<<0 | 1<<1 );
        c_ColPort_MCP23018(const uint8_t ADDR, const uint8_t IODIRx,
                const uint8_t GPIOx, const uint8_t GPPUx, const uint8_t PINS):
            ADDR(ADDR), IODIR(IODIRx), GPIO(GPIOx), GPPU(GPPUx), c_ColPort(PINS) {}

        void begin();

        //read port and store it in portState
        virtual void read();
};
#endif
