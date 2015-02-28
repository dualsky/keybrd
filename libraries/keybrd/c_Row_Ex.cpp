#include "c_Row_Ex.h"

/* process row switchStates bitwise, and send one row of key actions to USB
 * the following variables are for this row of switches, where each bit is one key:
 *      switchStates
 *      all_1
 *      all_0
 *      debounced
 *      newDebounced
 *      debouncedChanged
 *      isFallingEdge
 *      isRisingEdge
 *
 * this function has 3 parts:
 *      debounce
 *      edge detect
 *      press and release
 * this function could be written as 3 seperate functions,
 *  but that would require passing 2 variables between functions
 */
void c_Row_Ex::pressRelease(const uint8_t rowState)
{
    /* debounce
     * takes rowState and computes newDebounced
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

    /* update newDebounce if all the samples agree with one another
       if all samples=1 then newDebounced=1
           elseif all samples=0 then newDebounced=0
               else newDebounced=debounced i.e. no change */
    newDebounced = all_1 | (all_0 & debounced);

    /* edge detector
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

    /* pressRelease
     * takes isFallingEdge and isRisingEdge and calls key's press() or release()
     */
    //send row to USB
    uint8_t colBit;                             //column-bit map
    uint8_t col;                                //row index corresponding to a key pointer

    for (colBit=1, col=0; col<COLS_COUNT; colBit=colBit<<1, col++) // for each key in row
        {
        if (colBit & isFallingEdge)             //if button was released
            {
            ptrsKeys[col]->release();           //release before press to avoid impossible sequence
            }

        if (colBit & isRisingEdge)              //if button was pressed
            {
            ptrsKeys[col]->press();
            }
        }
}

/* Debounce uses multiple samples to debounces switch states,
 * where each sample contains the switch state of upto 8 switches, one bit per switch.
 *
 * Debounce uses Marty's debounce algorithm from
 *  http://drmarty.blogspot.com.br/2009/05/best-switch-debounce-routine-ever.html
 * I2C and TWI protocals do not include any Packet Error Checking (PEC).
 * The goal of Marty's debounce routine is to reject spurious signals,
 * which is useful when conecting split keyboards with a cable using I2C or TWI.
 * Tested on split keyboard with 3-meter long telephone wire between I/O expander and Teensy2.0
 *
 * Marty's debounce algorithm:
 * periodically read samples and update the state when a number consecutive samples are equal.
 */
