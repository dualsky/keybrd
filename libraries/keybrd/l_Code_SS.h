#ifndef L_CODE_SS_H
#define L_CODE_SS_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"
#include "l_ShiftManager.h"

/* Class l_Code_SS contains one scancode, which it sends when press() or release() is called.
 * ShiftManager insures that MODIFIERKEY_SHIFT is pressed.
 * "SS" stands for Scancode Shifted.
 */
class l_Code_SS: public l_Code
{
    private:
        const uint16_t scancode;
    public:
        l_Code_SS(const uint16_t scancode): scancode(scancode) { }
        void press();
        void release();
};
#endif
