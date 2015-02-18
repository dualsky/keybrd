#ifndef C_ROWWAIT_H
#define C_ROWWAIT_H
#include <Arduino.h>
#include <inttypes.h>

#define SAMPLE_COUNT 4                          //should match #define SAMPLE_COUNT in c_Row_Ex.h

/* c_RowWait waits for a row of switches to debounce.
 * Default values result in reliable scans.  True values result in reliable and faster scans.
 * TOTAL_ROW_COUNT is rows of all matrices, usually 2 to 16 rows.
 * SWITCH_BOUNCE_MILLIS is usually 5ms to 10ms.
 */
class c_RowWait
{
    private:
        const uint16_t WAIT_MICROSECONDS;       //microseconds delay between row scans
    public:
        c_RowWait( const uint8_t TOTAL_ROW_COUNT=1,     //rows of all matrices
                   const uint8_t SWITCH_BOUNCE_MILLIS=10 ): //bounce time in milliseconds
            WAIT_MICROSECONDS(1000 * SWITCH_BOUNCE_MILLIS/(TOTAL_ROW_COUNT*(SAMPLE_COUNT-1))) {}

        void delay();
};
#endif
