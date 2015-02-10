#ifndef L_SHIFTMANAGER_H
#define L_SHIFTMANAGER_H
#include <Arduino.h>
#include <inttypes.h>
#include "l_Code_Shift.h"

/* Class l_ShiftManager is used on multi-layered keyboards.
 * It is composed of an array of pointers to l_Code_Shift.
 * It can manage any number of shift keys.
 *
 * l_ShiftManager changes and restores the shift state for l_Code_SS and l_Code_SNS as needed:
 *      l_Code_SS object is a scancode shifted          e.g. '%' in symbols layer
 *      l_Code_SNS object is a scancode not shifted     e.g. '5' numbers layer
 *
 * keybaords without layers can omit l_ShiftManager
 *  and place scancode MODIFIERKEY_SHIFT directly in k_Key_1
 */
class l_ShiftManager
{
    private:
        l_Code_Shift*const *const ptrsShifts;   //array of shift pointers
        const uint8_t SHIFTS_COUNT;
    public:
        l_ShiftManager(l_Code_Shift *const ps[], const uint8_t sc):
            ptrsShifts(ps), SHIFTS_COUNT(sc) {}
        void pressShift0();                     //press first element of ptrsShifts[] array
        void restoreShift0();                   //restore first element of ptrsShifts[] array
        void releaseAllShifts();
        void restoreAllShifts();
};
#endif
