#ifndef C_IOEXPANDERPORT_H
#define C_IOEXPANDERPORT_H
#include <inttypes.h>

/* An IC port can be split between RowPort, ColPort, and LED
c_IOExpanderPort contains outputVal, the value of a port's output register.
outputVal is used for port manipulation by classes c_RowPort, c_ColPort, and c_LED.
For any one I/O expander port, one outputVal can be shared by c_RowPort, c_ColPort, and c_LED.

c_IOExpanderPort is only used by expander port classes.
AVR port classes do not use c_IOExpanderPort because PORTx is global in the Arduino library.
*/
struct c_IOExpanderPort
{
    const uint8_t ADDR;                     //I2C address
    const uint8_t num;                      //port number (use 0 instead of A, use 1 instead of B)
    uint8_t outputVal;                      //value of output register

    c_IOExpanderPort(const uint8_t a, const uint8_t n): ADDR(a), num(n), outputVal(~0) {}
};
#endif
