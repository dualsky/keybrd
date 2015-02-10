#include "c_Matrix_Teensy2.h"

void c_Matrix_Teensy2::begin()
{
    PORTB = B11111111;                          //set all port B pins to pullup
    DDRF = B11111111;                           //set all port F pins to outputs
}

//strobe a row (F pins) and then read a column (B pins)
//use port manipulation to read one row of pins
uint8_t c_Matrix_Teensy2::scanRow(const uint8_t rowN)
{
    //port F has 6 pins for up to 6 rows.  row numbers wired to pin numbers F 0,1,    4,5,6,7
    //port B has 8 pins for up to 8 cols.  col numbers wired to pin numbers B 0,1,2,3,4,5,6,7
    //map FPins[rowN] to port-F pin numbers ('B' in parameter denotes binary notation)
    const uint8_t FPins[6] = { 1<<0, 1<<1,             1<<4,  1<<5, 1<<6, 1<<7 };

    PORTF = ~FPins[rowN];   //strobe: set active row pin to low, and set inactive row pins to high
    delayMicroseconds(1);   //wait for PORTF to update the activate low pin
    //__asm__ volatile (" " : : : "memory"); // did not work
    //asm("nop"); // did not work, see
    // http://forum.pjrc.com/threads/24669-Setting-PORTF-on-Teensy-2-0-is-asynchronous
    return ~PINB;           //read all columns of row
}
