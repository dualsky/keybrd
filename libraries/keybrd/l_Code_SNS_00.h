#ifndef L_CODE_SNS_00_H
#define L_CODE_SNS_00_H
#include <Arduino.h>
#include <inttypes.h>
#include <Keyboard.h>
#include "l_Code.h"
#include "l_ShiftManager.h"

/* Class l_Code_SNS_00 sends double zero ("00" as seen on adding machines).
 */
class l_Code_SNS_00: public l_Code
{
    public:
        void press();
        void release();
};
#endif
