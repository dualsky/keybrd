#ifndef C_PORTCOLS_MCP23018_H
#define C_PORTCOLS_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_PortCols.h"

/* One microcontroller port with pins connected to matrix columns.
 * Port is read from pin 0 up.
 * todo: copy from MCP23018_strobe.ino > Port B input
 */
class c_PortCols_MCP23018 : public c_PortCols
{
    private:
        const uint8_t ADDR;                     //I2C address
        const uint8_t IODIR;                    //Input/Ouput Direction register
        const uint8_t GPPU;                     //General Purpose Pullup register
        const uint8_t GPIO;                     //General Purpose Input/Ouput register
    public:
        //The constructor initialization list configures column port's IODIR, GPPU, GPIO, and PINS to read Input.
        //parameter PINS is bitwise, where 1 means read the pin, 0 means don't read.
        //example instantiation for port A columns: c_PortCols_MCP23018 portACols(0x20, 0x00, 0x0C, 0x12, 1<<0 | 1<<1 );
        //example instantiation for port B columns: c_PortCols_MCP23018 portBCols(0x20, 0x01, 0x0D, 0x13, 1<<0 | 1<<1 );
        c_PortCols_MCP23018(const uint8_t ADDR, volatile unsigned char& IODIRx, volatile unsigned char& GPPUx,
                volatile unsigned char& GPIOx, const uint8_t PINS):
            ADDR(ADDR), IODIR(IODIRx), GPPU(GPPUx), GPIO(GPIOx), c_PortCols(PINS) {}//todo swap GPPU-GPIO be consistent w/Rows

        void begin();

        //read port and store it in portState
        virtual void readPortCols();
};
#endif
