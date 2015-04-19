#ifndef C_PORTROWS_MCP23018_H
#define C_PORTROWS_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_RowPort.h"
#include "c_Row_Ex.h"

class c_Matrix;

class c_RowPort_MCP23018 : public c_RowPort
{ 
    private:
        const uint8_t ADDR;                     //I2C address
        const uint8_t IODIR;                    //Input/Ouput Direction register address
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address
        uint8_t gpioVal;                        //value in GPIO register (PINS and LEDs)

    public:
        //The constructor initialization list configures column port's IODIR, GPIO, and PINS to output strobe.
        //parameter PINS is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port A columns: c_RowPort_MCP23018 portACols(0x20, 0x00, 0x12, 1<<0 | 1<<1 );
        //example instantiation for port B columns: c_RowPort_MCP23018 portBCols(0x20, 0x01, 0x13, 1<<0 | 1<<1 );
        c_RowPort_MCP23018(const uint8_t ADDR, volatile unsigned char& IODIRx, volatile unsigned char& GPIOx, const uint8_t PINS):
            ADDR(ADDR), IODIR(IODIRx), GPIO(GPIOx), c_RowPort(PINS) {}

        void begin();

        virtual void readCols(const uint8_t activeLowPin, c_Matrix *const matrix);
};
#endif
