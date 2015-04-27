#include "c_RowWait.h"

void c_RowWait::delay()
{
    delayMicroseconds(WAIT_MICROSECONDS);
}

/* WAIT_MICROSECONDS
 *
 * Why wait is uint16_t microseconds:
 * WAIT = 1000 * SWITCH_BOUNCE_MILLIS/(TOTAL_ROW_COUNT*(SAMPLE_COUNT-1))
 * WAIT = 1000 * 10/(1*(4-1)) = 3333 microseconds with default values, needs uint16_t
 * WAIT = 1000 * 5/(10*(4-1)) = 166 microseconds for 10-row Cherry MX, needs delayMicroseconds()
 *
 * WAIT derived:
 * A simplified equation is illustrated in table below.
 * The [] bracket represent the switch's bounce time.
 * Each x represents a sample.
 * WAIT is the distance between each x.
 * All samples left of brackets are one value, and all samples on right are the opposite value.
 * The sample values inside the brackets don't matter, as long as they all have the same value.
 * Worst case is left and right samples barely inside bounce time boundary
 *      SWITCH_BOUNCE           SAMPLE_COUNT
 *      [x      ]               1
 *      [x     x]               2
 *      [x  x  x]               3
 * WAIT = SWITCH_BOUNCE/(SAMPLE_COUNT-1)
 *
 * SAMPLE_COUNT value:
 * SAMPLE_COUNT is the number of consecutive equal samples needed to debounce.
 * It is a macro because it is used to define array size of samples[SAMPLE_COUNT] in c_Row.
 * SAMPLE_COUNT should be at lease 2.
 * Multiple samples are for error correction on I2C I/O expander and shorten response time.
 * On keyboards without I/O expander, multiple samples only shorten response time.
 * Larger SAMPLE_COUNTs are more reliable but consume more memory, where
 *      SAMPLE_COUNT*ROW_COUNT = bytes of memory consumed by keyboard
 * So don't make SAMPLE_COUNT too large, SAMPLE_COUNT = 4 is very reliable for I2C error correction.
 *
 * Switch bounce times:
 * Cherry MX has 5msec bounce time http://www.cherrycorp.com/english/switches/key/mx.htm
 * hasu measured Cherry MX bounce times .3ms to 1.4ms http://geekhack.org/index.php?topic=42385.0
 * tactile switch MJTP series bounce 10 ms http://www.apem.com/files/apem/brochures/MJTP_6MM.pdf
 *
 * slow-scan debugging trick: change SWITCH_BOUNCE_MILLIS to 100
 */
