#include "c_Row.h"
void c_Row::begin()
{
    for (uint8_t col = 0; col < COLS_COUNT; col++) //for each key in row
        {
            ptrsKeys[col]->begin();             //initilize LEDs
        }
}

/* rowState is state of a matrix row's keys, one bit per key.
 * 1 means pressed, 0 means released.
 * pressRelease() processes rowState bitwise, and then sends key actions for the row to USB
 * the following variables are bitwise for this row of keys:
 *      rowState
 *      all_1
 *      all_0
 *      debounced
 *      newDebounced
 *      debouncedChanged
 *      isFallingEdge
 *      isRisingEdge
 *
 * this function has 3 parts:
 *      DEBOUNCE
 *      EDGE DETECT
 *      PRESS AND RELEASE
 * this function could be written as 3 seperate functions,
 *  using pass by reference for the 2 variables between each function
 */
void c_Row::pressRelease(const uint8_t rowState)
{
    /* DEBOUNCE
     * takes rowState and computes newDebounced
     *
     * Debounce uses multiple samples to debounces switch states,
     * where each sample contains the switch states for a row of keys, one bit per switch.
     *
     * Debounce uses Marty's debounce algorithm from
     *  http://drmarty.blogspot.com.br/2009/05/best-switch-debounce-routine-ever.html
     * I2C and TWI protocals do not include any Packet Error Checking (PEC).
     * The goal of Marty's debounce routine is to reject spurious signals,
     * which is useful when conecting split keyboards with a cable using I2C or TWI.
     * Tested on split keyboard with 3-meter long telephone wire to I/O expander
     *
     * Marty's debounce algorithm:
     * periodically read samples and update the state when a number consecutive samples are equal.
     */
    uint8_t all_1 = 0B11111111;
    uint8_t all_0 = 0B00000000;
    uint8_t newDebounced;

    refRowWait.delay();                         //delay between Row scans to debounce key

    samples[i] = rowState;                      //insert rowState into ring buffer

    if (++i >= SAMPLE_COUNT)
        {
        i = 0;                                  //wrap write index to beginning of ring buffer
        }

    for (uint8_t j = 0; j < SAMPLE_COUNT; j++)  //traverse ring buffer
        {
        all_1 &= samples[j];                    //1 if all samples are 1
        all_0 |= samples[j];                    //0 if all samples are 0
        }

    // update newDebounce if all the samples agree with one another
    // if all samples=1 then newDebounced=1
    //     elseif all samples=0 then newDebounced=0
    //         else newDebounced=debounced i.e. no change
    newDebounced = all_1 | (all_0 & debounced);

    /* EDGE DETECT
     * takes debounced and newDebounced and computes isFallingEdge and isRisingEdge
     */
    uint8_t isFallingEdge;
    uint8_t isRisingEdge;
    uint8_t debouncedChanged;

    debouncedChanged = newDebounced xor debounced;
    debounced = newDebounced;

    //bit=1 if last debounce changed debounced from 1 to 0, else bit=0
    isFallingEdge = debouncedChanged & ~debounced;

    //bit=1 if last debounce changed debounced from 0 to 1, else bit=0
    isRisingEdge = debouncedChanged & debounced;

    /* PRESS AND RELEASE
     * takes isFallingEdge and isRisingEdge and calls key's press() or release()
     */
    //send row to USB
    uint8_t colM;                               //column bit mask
    uint8_t col;                                //row index corresponding to a key pointer

    for (colM=1, col=0; col<COLS_COUNT; colM=colM<<1, col++) // for each key in row
        {
        if (colM & isFallingEdge)               //if button was released
            {
            ptrsKeys[col]->release();           //release before press to avoid impossible sequence
            }

        if (colM & isRisingEdge)                //if button was pressed
            {
            ptrsKeys[col]->press();
            }
        }
}
