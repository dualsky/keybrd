#ifndef L_KEY_1_H
#define L_KEY_1_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "l_Code.h"

/* Class l_Key is composed of one l_Code pionter, which it calls when key is pressed or released.
 */
class l_Key_1: public c_Key
{
    private:
        l_Code* const ptrScanCode;

    public:
        l_Key_1(l_Code* const ptrScanCode): ptrScanCode(ptrScanCode) { }

        //send scancode to USB for press
        void press();

        //send scancode to USB for release
        void release();
};
#endif
