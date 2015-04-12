#ifndef C_ROW_EX_H
#define C_ROW_EX_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "c_RowWait.h"

#define SAMPLE_COUNT 4                          //should match #define SAMPLE_COUNT in c_RowWait.h

/* Class c_Row_Ex is composed of a row of keys.
 * It has switch debouncer and I2C error correction
 * The "Ex" in "c_Row_Ex" is for I/O Expander which uses I2C.
 *
 * pressRelease() function processes the row:
 *      debounce the switches
 *      detect falling or rising edge
 *      call key's press() or release()
 */
class c_Row_Ex
{
    private:
        static c_RowWait& refRowWait;           //delay between Row scans for debouncing switch
        uint8_t samples[SAMPLE_COUNT];          //ring buffer, where each sample is a row scan
        uint8_t i;                              //ring buffer's current write index
        uint8_t debounced;                      //each bit is a debounced value of row's key

        c_Key*const *const ptrsKeys;            //row is composed of an array of Keys
        const uint8_t COLS_COUNT;               //number of keys in row
    public:
        c_Row_Ex(c_Key *const pk[], const uint8_t cc):
            ptrsKeys(pk), COLS_COUNT(cc), i(0), debounced(0) { }
        void pressRelease(const uint8_t sample); //send one row of key actions to USB
};
#endif
