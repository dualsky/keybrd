Wiring MCP23018 I/O Expander for keybrd
=======================================
This document contains information useful for wiring a MCP23018 I/O expander to a keyboard.
The corresponding keybrd class is in keybrd\c_Matrix_MCP23018.

Most of the following information is copied from the [MCP23018/MCP23S18 data sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/22103a.pdf).

## MCP23018 Pinout Diagram p3
"U" notch is on top in the diagram.
Inner columns are pin numbers, outer columns are port+bit.
```
         VSS 1     U    28 NC
          NC 2          27 GPA7
        GPB0 3          26 GPA6
        GPB1 4          25 GPA5
        GPB2 5          24 GPA4
        GPB3 6          23 GPA3
        GPB4 7          22 GPA2
        GPB5 8          21 GPA1
        GPB6 9          20 GPA0
        GPB7 10         19 INTA
         VDD 11         18 INTB
         SCL 12         17 NC
         SDA 13         16 RESET
          NC 14         15 ADDR
```

## Row And Column Pins
See c_Matrix_MCP23018.h for pin numbers used by firmware.

Keybrd convention is to have keyboard row 0 on top, and column 0 on left.

## Diodes
1N4148 diodes with anodes (banded end) towards row.

## I2C Wires to Micro Processor
Two jumpers:
```
PIN NUMBER      PIN NUMBER      JUMPER PURPOSE          JUMPER COLOR
11              16              POR (Power On Reset)    red
 1              15              ADDR 0x20               black
```

Four wires connect IO Expander to uC (from 1.1 Pin Descriptions, TABLE 1-1 p5):
```
PIN NAME        PIN NUMBER      PIN FUNCTION            WIRE COLOR
 VSS             1              Ground - Voltage Drain  black
 SCL            12              Serial CLock input      red
 SDA            13              Serial DAta I/O         green
 VDD            11              Power  + Voltage Source yellow
```
WIRE COLOR is a suggestion based on Apple Data port 4P4C modular plug.

