#ifndef C_ROWPORT_AVR_ACTIVEHIGH_H
#define C_ROWPORT_AVR_ACTIVEHIGH_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_RowPort.h"

/* Connecting Teensy 2.0 to a Keyboard
===================================
This describes how to connect a Teensy 2.0 to a keyboard.
Connecting LEDs to Teensy is described in c_LED_AVR.h.

Teensy 2.0 Pinout Diagram
-------------------------
USB is on top in the diagram.
Inner columns are pin numbers, outer columns are port+bit pin name.
```
ground  GND      USB      VCC   +5v power
        B0 0            21 F0
        B1 1            20 F1
        B2 2            19 F4
        B3 3            18 F5
        B7 4            17 F6
SCL     D0 5            16 F7
SDA     D1 6            15 B6
        D2 7            14 B5
        D3 8            13 B4
        C6 9            12 D7
        C7 10           11 D6   Do not use pin D6 for scanning keyboard matrix
                                LED on pin D6 pulls voltage down and will always return low

BOTTOM (USB on top, left to right)
PIN#    port+bit        function
23      D5
        VCC             5v power
        GND             ground
        RST             reset
22      D4

MID (below USB, left to right)
PIN#    port+bit        function
24      E6
Ref
```
Pin numbers are from http://www.pjrc.com/teensy/teensyduino.html and https://www.pjrc.com/teensy/pinout.html.
Pin names are from http://www.pjrc.com/teensy/td_digital.html.

Teensy 2.0 has 21 digital I/O pins
21 pins can scan 110 keys (10+11=21 pins and 10*11=110 keys).

Diode orientation
-----------------
The keyboard's matrix is composed of rows and columns.
The rows and columns are physically connected to the keys.
The rows and columns are distinguishable by diode orientation (not horizontal/vertical):
    cathodes on columns
    anodes on rows

Pull-down resistors
-------------------
c_RowPort_AVR_activeHigh uses active high (most keyboards use active low).
c_RowPort_AVR_activeHigh requires one pull-down resistor connecting each row pin to ground.
The external pull-down resistors should have a value between 10k ohms and 2.2k ohms.

Connecting I2C to I/O Expander
------------------------------
Four wires connect uC to I/O Expander:

|Pin Name | Pin Number |      Pin Function      | Wire Color | resistor
|---------|------------|------------------------|------------|----------|
| GND     | -          | Ground (Voltage Drain) | black      |          |
| SCL     | 5          | Serial CLock input     | red        | Pull-up  |
| SDA     | 6          | Serial DAta I/O        | green      | Pull-up  |
| +5v     | -          | Power (Voltage Source) | yellow     |          |

I2C needs 4.7K Ohm external pull-up resistors on SCL and SDA

Wire Color is a suggestion based on Apple Data port 4P4C modular plug.
*/

class c_Matrix;

class c_RowPort_AVR_ActiveHigh : public c_RowPort
{ 
    private:
        volatile unsigned char& DDR;            //Data Direction Register
        volatile unsigned char& PORT;           //PORT register

    public:
        //The constructor initialization list configures column's DDRx and PORTx to output strobe.
        //configure all pins as output (for strobe pins and LED)
        //example instantiation: c_RowPort_AVR_ActiveHigh portFRows(DDRF, PORTF, 1<<1 );
        c_RowPort_AVR_ActiveHigh
            (volatile unsigned char& DDRx, volatile unsigned char& PORTx, const uint8_t pins);

        virtual void scanRow(const uint8_t activeHighPin, c_Matrix *const matrix);
};
#endif
