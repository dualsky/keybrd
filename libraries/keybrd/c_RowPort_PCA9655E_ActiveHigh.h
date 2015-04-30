#ifndef C_ROWPORT_PCA9655E_ACTIVEHIGH_H
#define C_ROWPORT_PCA9655E_ACTIVEHIGH_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_RowPort.h"
#include "c_IOExpanderPort.h"

class c_Matrix;

class c_RowPort_PCA9655E_ActiveHigh : public c_RowPort
{ 
    private:
        c_IOExpanderPort& port;
        const uint8_t configuration;            //Configuration byte command
        const uint8_t output;                   //output byte command

    public:
        //The constructor initialization list configures column port's configuration, output, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //PCA9655E I2C address is 0x20 when ADDR pin is grounded
        //example instantiation for port 0 columns:
        //      c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0, 1<<0 | 1<<1 );
        //example instantiation for port 1 columns:
        //      c_RowPort_PCA9655E_ActiveHigh rowPort1_L(port1, 1<<0 | 1<<1 );
        c_RowPort_PCA9655E_ActiveHigh(c_IOExpanderPort& port, const uint8_t pins);

        virtual void scanRow(const uint8_t activeHighPin, c_Matrix *const matrix);
};
#endif
