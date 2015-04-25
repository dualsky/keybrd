#include "c_LED_PCA9655E.h"

void c_LED_PCA9655E::on()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal |= pin);            //set pin high
    Wire.endTransmission();

    Keyboard.press(KEY_L);
}

void c_LED_PCA9655E::off()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(output);
    Wire.write(port.outputVal &= ~pin);           //set pin low
    Wire.endTransmission();

    Keyboard.release(KEY_L);
}
