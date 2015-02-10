#ifndef L_CODE_SHIFT_H
#define L_CODE_SHIFT_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"

/* Class l_Code_Shift sends shift scancode for multi-layered keybrds.
 * documention in l_Shiftmanager.h explains how the system works.
 */
class l_Code_Shift: public l_Code
{
    private:
        bool KBShifted;                         //key's shift state
        bool OSShifted;                         //operating system's shift state
        const uint16_t scancode;                //MODIFIERKEY_LEFT_SHIFT, MODIFIERKEY_RIGHT_SHIFT
    public:
        l_Code_Shift(const uint16_t sc): KBShifted(false), OSShifted(false), scancode(sc) {}
        void press();
        void release();
        void restoreKBShifted();
        void syncOSShifted(bool shifted);
};
#endif
