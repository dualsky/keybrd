#ifndef C_ROWPORT_MCP23018_H
#define C_ROWPORT_MCP23018_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_RowPort.h"
#include "c_IOExpanderPort.h"

/* Connecting MCP23018 I/O Expander to a Keyboard
==============================================
This describes how to connect a MCP23018 I/O expander to a keyboard.
Connecting LEDs to MCP23018 is described in c_LED_MCP23018.h.

[MCP23018/MCP23S18 data sheet](http://ww1.microchip.com/downloads/en/DeviceDoc/22103a.pdf)

MCP23018 Pin Diagram
--------------------
Inner columns are pin numbers, outer columns are port+bit pin name.
```
	   GND   VSS 1          28 NC
		  NC 2          27 GPA7
		GPB0 3          26 GPA6
		GPB1 4          25 GPA5
		GPB2 5          24 GPA4
		GPB3 6          23 GPA3
		GPB4 7          22 GPA2
		GPB5 8          21 GPA1
		GPB6 9          20 GPA0
		GPB7 10         19 INTA
	   power VDD 11         18 INTB
	   SCL   SCL 12         17 NC
	   SDA   SDA 13         16 RESET	power
		  NC 14         15 ADDR		GND
```
from MCP23018 Datasheet, Package Types: MCP23018

Diode orientation
-----------------
The keyboard's matrix is composed of rows and columns.
The rows and columns are physically connected to the keys.
The rows and columns are distinguishable by diode orientation (not horizontal/vertical):
    cathodes on rows
    anodes on columns

Pull-up resistors
-----------------
c_RowPort_MCP23018 uses the micro-controller's internal pull-up resistors.

Connect I2C to Micro Processor
------------------------------
Four wires connect IO Expander to uC (from 1.1 Pin Descriptions, TABLE 1-1 p5):

|Pin Name | Pin Number |      Pin Function      | Wire Color |
|---------|------------|------------------------|------------|
| VSS     | 1          | Ground (Voltage Drain) | black      |
| SCL     | 12         | Serial CLock input     | red        |
| SDA     | 13         | Serial DAta I/O        | green      |
| VDD     | 11         | Power (Voltage Source) | yellow     |

(Wire Color is a suggestion based on Apple Data port 4P4C modular plug)

Jumpers
-------

| Pin Number | Jump to Pin Number |    Jumper Purpose    |
|------------|--------------------|----------------------|
| 11         | 16                 | POR (Power On Reset) |
| 1          | 15                 | ADDR 0x20            |

(see datasheet for other I2C addresses)
*/
class c_Matrix;

class c_RowPort_MCP23018 : public c_RowPort
{ 
    private:
        c_IOExpanderPort& port;
        const uint8_t IODIR;                    //Input/Ouput Direction register address
        const uint8_t GPIO;                     //General Purpose Input/Ouput register address

    public:
        //The constructor initialization list configures column port's IODIR, GPIO, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //MCP23018 I2C address is 0x20 when ADDR pin is grounded
        //example instantiation for port A columns:
        //      c_RowPort_MCP23018 rowPortA(portA, 1<<0 | 1<<1 );
        //example instantiation for port B columns:
        //      c_RowPort_MCP23018 rowPortB(portB, 1<<0 | 1<<1 );
        c_RowPort_MCP23018(c_IOExpanderPort& port, const uint8_t pins);

        virtual void scanRow(const uint8_t activeLowPin, c_Matrix *const matrix);
};
#endif
