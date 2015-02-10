Wiring Teensy 2.0 for keybrd
============================
This document contains information useful for wiring a Teensy2 to a keyboard.
The corresponding keybrd class is in keybrd\c_Matrix_Teensy2.

Most of the following information is copied from the PJRC site.
Pin out table without physical pin positions is on http://www.pjrc.com/teensy/td_digital.html.
Pin numbers are from http://www.pjrc.com/teensy/teensyduino.html.

## Teensy2 Pinout Diagram
USB is on top in the diagram.
Inner columns are pin numbers, outer columns are port+bit.
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
        C7 10           11 D6   LED on pin 11 pulls voltage down and will always return LOW

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
24 pins can scan 128 keys (8+16=24 pins and 8*16=128 keys).

## Row and Column Pins
See c_Matrix_Teensy2.h for pin numbers used by firmware.

Keybrd convention is to have keyboard row 0 on top, and column 0 on left.

## Diodes
1N4148 diodes with anodes (banded end) towards row.

## I2C Wires to I/O Expander
Two external pull-up resistors for I2C:
```
PIN NUMBER  to PIN NUMBER       OHMS PULL-UP RESISTOR
 5              +5v power       4.7K
 6              +5v power       4.7K
```

Four wires connect uC to I/O Expander:
```
PIN NAME        PIN NUMBER      PIN FUNCTION            WIRE COLOR
 GND            -               Ground - Voltage Drain  black
 SCL            5               Serial CLock input      red
 SDA            6               Serial DAta I/O         green
 +5v            -               Power  + Voltage Source yellow
```
WIRE COLOR is a suggestion based on Apple Data port 4P4C modular plug.
Macintosh 128K, Macintosh 512K and Macintosh Plus from Apple Data port uses 4P4C modular plug.
Plug on one end of handset cable has wire order reversed.
4P4C modular plug references:
* https://github.com/altercation/tmk_firrmware_hhkb_teensy2/blob/master/converter/m0110_usb/README.md
* http://en.wikipedia.org/wiki/Modular_connector#4P4C
* http://www.digikey.com/product-search/en/cable-assemblies/modular-cables/1573024

