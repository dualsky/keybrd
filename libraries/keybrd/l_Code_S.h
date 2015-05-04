#ifndef L_CODE_S_H
#define L_CODE_S_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"

/* Class l_Code_S is composed of one scancode, which it sends when press() or release() is called.
 * "S" stands for Scancode.
 */
class l_Code_S: public l_Code
{
    private:
        const uint16_t scancode;
    public:
        l_Code_S(): scancode(0) {};
        l_Code_S(const uint16_t sc): scancode(sc) { }
        void press();
        void release();
};
#endif
