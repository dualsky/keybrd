#ifndef C_ROWPORT_PCA9655E_ACTIVEHIGH_H
#define C_ROWPORT_PCA9655E_ACTIVEHIGH_H
#include <Arduino.h>
#include <inttypes.h>
#include "Wire.h"
#include "c_RowPort.h"
#include "c_IOExpanderPort.h"

/* Connecting PCA9655E I/O Expander to a Keyboard
==============================================
This describes how to connect a PCA9655E I/O expander to a keyboard.
Connecting LEDs to PCA9655E is described in c_LED_PCA9655E.h.

INT pin is Interrupt Output 
PCA9655E data sheet on http://www.onsemi.com/pub_link/Collateral/PCA9655E-D.PDF

PCA9655E Pinout Diagram
-----------------------
Inner columns are pin numbers, outer columns are port+bit pin name.
```
	INT   1  	24 VDD		VCC
	AD1   2		23 SDA		SDA
	AD2   3		22 SCL		SCL
	IO0_0 4		21 AD0
	IO0_1 5		20 IO1_7
	IO0_2 6		19 IO1_6
	IO0_3 7		18 IO1_5
	IO0_4 8		17 IO1_4
	IO0_5 9		16 IO1_3
	IO0_6 10	15 IO1_2
	IO0_7 11	14 IO1_1
GND	VSS   12	13 IO1_0
```
pinouts from PCA9655E DataSheet "PIN ASSIGNMENT"

Diode orientation
-----------------
The keyboard's matrix is composed of rows and columns.
The rows and columns are physically connected to the keys.
The rows and columns are distinguishable by diode orientation (not horizontal/vertical).
Matrix rows connect to diode cathodes and matrix columns as connect to diode anodes.

Pull-down resistors
-------------------
c_RowPort_PCA9655E_activeHigh uses active high
 (c_RowPort_PCA9655E and most keyboaords use active low).
c_RowPort_PCA9655E_activeHigh requires one pull-down resistor connecting each row pin to ground.
The external pull-down resistors should have a value between 10k ohms and 2.2k ohms.

Connect I2C to Micro Processor
------------------------------
Four wires connect IO Expander to uC

|Pin Name | Pin Number |      Pin Function      | Wire Color |
|---------|------------|------------------------|------------|
| VSS     | 12         | Ground (Voltage Drain) | black      |
| SCL     | 22         | Serial CLock input     | red        |
| SDA     | 23         | Serial DAta I/O        | green      |
| VDD     | 24         | Power (Voltage Source) | yellow     |

(Wire Color is a suggestion based on Apple Data port 4P4C modular plug)

Jumpers
-------

| Pin Number | Jump to | Jumper Purpose |
|------------|---------|----------------|
| 21         | Ground  | ADDR 0x20      |
| 2          | Ground  | ADDR 0x20      |
| 3          | Ground  | ADDR 0x20      |

(see datasheet for other I2C addresses)
*/
class c_Matrix;

class c_RowPort_PCA9655E_ActiveHigh : public c_RowPort
{ 
    private:
        c_IOExpanderPort& port;
        const uint8_t configuration;            //Configuration byte command
        const uint8_t output;                   //output byte command

    public:
        //The constructor initialization list configures column port's configuration, output, and pins.
        //parameter pins is bitwise, where 1 means read the pin, 0 means don't read.
        //PCA9655E I2C address is 0x20 when all three ADDR pins are grounded
        //example instantiation for port 0 columns:
        //      c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0, 1<<0 | 1<<1 );
        //example instantiation for port 1 columns:
        //      c_RowPort_PCA9655E_ActiveHigh rowPort1_L(port1, 1<<0 | 1<<1 );
        c_RowPort_PCA9655E_ActiveHigh(c_IOExpanderPort& port, const uint8_t pins);

        virtual void scanRow(const uint8_t activeHighPin, c_Matrix *const matrix);
};
#endif
