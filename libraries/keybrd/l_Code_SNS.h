#ifndef L_CODE_SNS_H
#define L_CODE_SNS_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"
#include "l_ShiftManager.h"

/* Class l_Code_SNS is composed of one scancode, which it sends when press() or release() is called.
 * ShiftManager insures that MODIFIERKEY_SHIFT is released.
 * "SNS" stands for Scancode Not Shifted.
 */
class l_Code_SNS: public l_Code
{
    private:
        const uint16_t scancode;
    public:
        l_Code_SNS(const uint16_t sc): scancode(sc) { }
        void press();
        void release();
};
#endif
