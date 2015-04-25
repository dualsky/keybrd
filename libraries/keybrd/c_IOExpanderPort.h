#ifndef C_IOEXPANDERPORT_H
#define C_IOEXPANDERPORT_H
#include <inttypes.h>

/* c_IOExpanderPort contains outputVal, the value of a port's output register.
outputVal is manipulated by c_RowPort, c_ColPort, and c_LED.
For any one I/O expander port, one outputVal is shared by c_RowPort, c_ColPort, and c_LED.
*/
struct c_IOExpanderPort
{
    const uint8_t ADDR;                         //I2C address
    uint8_t outputVal;                          //value of output register

    c_IOExpanderPort(const uint8_t a): ADDR(a), outputVal(~0) {}
};
#endif
