#ifndef C_ROW_H
#define C_ROW_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "c_RowWait.h"

#define SAMPLE_COUNT 4                          //should match #define SAMPLE_COUNT in c_RowWait.h

/* Class c_Row is composed of a row of keys.
 * It has switch debouncer and I2C error correction
 *
 * pressRelease() function processes the row:
 *      debounce the switches
 *      detect falling or rising edge
 *      call key's press() or release()
 */
class c_Row
{
    private:
        static c_RowWait& refRowWait;           //delay between Row scans for debouncing switch
        uint8_t samples[SAMPLE_COUNT];          //ring buffer, where each sample is a row scan
        uint8_t i;                              //ring buffer's current write index
        uint8_t debounced;                      //each bit is a debounced value of row's key

        c_Key*const *const ptrsKeys;            //row is composed of an array of Keys
        const uint8_t COL_COUNT;               //number of keys in row
    public:
        c_Row(c_Key *const ptrsKeys[], const uint8_t col_count)
            : ptrsKeys(ptrsKeys), COL_COUNT(COL_COUNT), i(0), debounced(0) { }

        void pressRelease(const uint8_t sample); //send one row of key actions to USB
};
#endif
