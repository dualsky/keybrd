#ifndef C_IOEXPANDERPORT_H
#define C_IOEXPANDERPORT_H
#include <inttypes.h>

struct c_IOExpanderPort
{
    const uint8_t ADDR;
    uint8_t portVal;
};
#endif
