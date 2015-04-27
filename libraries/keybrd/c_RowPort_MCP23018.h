#ifndef C_ROWPORT_MCP23018_H
#define C_ROWPORT_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_RowPort.h"
#include "c_IOExpanderPort.h"

class c_Matrix;

class c_RowPort_MCP23018 : public c_RowPort
{ 
    private:
        c_IOExpanderPort& port;
        const uint8_t IODIR;                    //Input/Ouput Direction register address
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address

    public:
        //The constructor initialization list configures column port's IODIR, GPIO, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //MCP23018 I2C address is 0x20 when ADDR pin is grounded
        //example instantiation for port A columns:
        //      c_RowPort_MCP23018 rowPortA(portA, 0x00, 0x12, 1<<0 | 1<<1 );
        //example instantiation for port B columns:
        //      c_RowPort_MCP23018 rowPortB(portB, 0x01, 0x13, 1<<0 | 1<<1 );
        c_RowPort_MCP23018(c_IOExpanderPort& ep, const uint8_t IODIRx,
                const uint8_t GPIOx, const uint8_t pins):
                port(ep), IODIR(IODIRx), GPIO(GPIOx), c_RowPort(pins) {}

        void begin();

        virtual void scanRow(const uint8_t activeLowPin, c_Matrix *const matrix);
};
#endif
