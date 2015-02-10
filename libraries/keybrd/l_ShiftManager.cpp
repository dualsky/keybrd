#include "l_ShiftManager.h"

//called by l_Code_SS, it only needs one shift
void l_ShiftManager::pressShift0()
{
    ptrsShifts[0]->syncOSShifted(true);
}

//called by l_Code_SS
void l_ShiftManager::restoreShift0()
{
    ptrsShifts[0]->restoreKBShifted();
}

//called by l_Code_SNS and l_Code_00, they need all shifts released
void l_ShiftManager::releaseAllShifts()
{
    for (uint8_t i = 0; i < SHIFTS_COUNT; i++)
        {
        ptrsShifts[i]->syncOSShifted(false);
        }
}

//called by l_Code_SNS
void l_ShiftManager::restoreAllShifts()
{
    for (uint8_t i = 0; i < SHIFTS_COUNT; i++)
        {
        ptrsShifts[i]->restoreKBShifted();
        }
}
