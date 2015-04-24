#ifndef C_IOEXPANDERPORT_H
#define C_IOEXPANDERPORT_H
#include <inttypes.h>

struct c_IOExpanderPort
{
    const uint8_t ADDR;                         //I2C address
    uint8_t outputVal;                          //value of output register (for PINS and LEDs)

    c_IOExpanderPort(const uint8_t a): ADDR(a), outputVal(~0) {}
};
#endif
