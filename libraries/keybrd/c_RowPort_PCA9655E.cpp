#include "c_RowPort_PCA9655E.h"
#include "c_Matrix.h"                           //included in implementation because circular

c_RowPort_PCA9655E::c_RowPort_PCA9655E(c_IOExpanderPort& port, const uint8_t pins)
    : port(port), configuration(port.num + 6), output(port.num + 2), c_RowPort(pins)
{
    Wire.begin();
    
    Wire.beginTransmission(port.ADDR);
    Wire.write(configuration);
    Wire.write(0);                              //0=configure as output (for strobe pins and LED)
    Wire.endTransmission();
}

/* scanRow strobes row using active low.
activeLowPin is one pin per bit, where active pin is 1.
Strobe is turned off after matrix reads the columns.
*/
void c_RowPort_PCA9655E::scanRow(const uint8_t activeLowPin, c_Matrix *const matrix)
{
    //strobe row on
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal &= ~activeLowPin); //strobe on: set strobe pin output to low
    Wire.endTransmission();

    matrix->read();                             //read the IC's column ports

    //strobe row off
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    //Wire.write(port.outputVal |= activeLowPin); //strobe off: set strobe pin output to high
    Wire.write(port.outputVal |= pins);         //strobe off: todo which strobe off is better?
    Wire.endTransmission();
}
