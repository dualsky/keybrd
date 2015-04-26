#include "c_RowPort_PCA9655E.h"
#include "c_Matrix.h"                           //included in implementation because circular

void c_RowPort_PCA9655E::begin()
{
    Wire.begin();
    
    Wire.beginTransmission(port.ADDR);
    Wire.write(configuration);
    Wire.write(0);                              //0=configure as output (for strobe PINS and LED)
    Wire.endTransmission();

    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal = PINS);          //set LED pins low, remaining pins strobe off
    Wire.endTransmission();
}

/* scanRow strobes row using active low.
activeLowPin is one pin per bit, where active pin is 1.
Strobe is turned off after matrix reads the columns.
*/
void c_RowPort_PCA9655E::scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe on
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal &= ~activeLowPin); //strobe on: set strobe pin output to low
    Wire.endTransmission();

    matrix->read();                             //read the IC's column ports

    //strobe off
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal |= activeLowPin); //strobe off: set strobe pin output to high
    //Wire.write(port.outputVal |= PINS); //this did not work, exp bot row keys unresposive
    Wire.endTransmission();
}
