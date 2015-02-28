#include "c_Matrix_Teensy2.h"

void c_Matrix_Teensy2::begin()
{
    PORTB = B11111111;                          //set all port B pins to pullup
    DDRF = B11111111;                           //set all port F pins to outputs
}

/* Strobe portF and then read portB and return row state.
 * In keybrd nomenclature, portF would be the row and portB would be the column.
 * In hardware, the assignments of row or column to matrix is arbirary.
 */
uint8_t c_Matrix_Teensy2::scanRow(const uint8_t rowN)
{
    //FPin[rowN] is array of port-B pin names that are strobed
    const uint8_t FPin[6] = { 1<<0, 1<<1,             1<<4,  1<<5, 1<<6, 1<<7 };

    PORTF = ~FPin[rowN];   //strobe row: set active row pin to low, set inactive row pins to high
    delayMicroseconds(1);   //wait for PORTF to update the activate low pin
    //__asm__ volatile (" " : : : "memory"); // did not work
    //asm("nop"); // did not work, see
    // http://forum.pjrc.com/threads/24669-Setting-PORTF-on-Teensy-2-0-is-asynchronous
    return ~PINB;           //read all columns of row
}
