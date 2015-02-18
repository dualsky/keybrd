#include "c_Matrix_MCP23018.h"

/* Initiate the Matrix class and join the I2C bus as slave.
 */
void c_Matrix_MCP23018::begin()
{
    //initializate Wire for scanning
    Wire.begin();

    //set port A to read and pullup
    Wire.beginTransmission(addr);
    Wire.write(gppuCol);                        //will be setting pull-up resistors on port A
    Wire.write(0xFF);                           //set all port A pins to pullup
    Wire.endTransmission();

    //set port B to output
    Wire.beginTransmission(addr);
    Wire.write(iodirRow);                       //will be setting direction on port B
    Wire.write(0x00);                           //set all port B pins to output
    Wire.endTransmission();
}

/* strobe portB and then read portA
 * in keybrd nomenclature, portB would be the row and portA would be the column
 * in hardware, the assignments of row or column to matrix is arbirary
 */
uint8_t c_Matrix_MCP23018::scanRow(const uint8_t rowN)
{
    //BPin[] is array of port-B pin names that are strobed
    const uint8_t BPin[8] = { 1<<0, 1<<1, 1<<2, 1<<3, 1<<4,  1<<5, 1<<6, 1<<7 };


    // strobe: set active row pin to low, and set inactive row pins to high
    Wire.beginTransmission(addr);
    Wire.write(gpioRow);                        //will be setting pins on rows port
    Wire.write(~BPin[rowN]);                    //set active row pin to low
    Wire.endTransmission();

    Wire.beginTransmission(addr);
    Wire.write(gpioCol);                        //will be reading from columns port
    Wire.endTransmission();

    Wire.requestFrom(addr, static_cast<uint8_t>(1));
    //sample is 0 for released, 1 for pressed
    //which makes samples[] and state more human readable for debugging
    //and default initialization of samples[] is all 0s
    //invert bits ("~" infront of Wire.read) for active-low row
    return ~Wire.read();                        //read all columns of row
}
