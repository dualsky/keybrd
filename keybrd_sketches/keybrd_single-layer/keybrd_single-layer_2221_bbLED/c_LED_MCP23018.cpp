#include "c_LED_MCP23018.h"

void c_LED_MCP23018::on()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal &= ~pin);           //set pin low (sink)
    Wire.endTransmission();

//    Keyboard.press(KEY_L);
}

void c_LED_MCP23018::off()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal |= pin);            //set pin high (sink off)
    Wire.endTransmission();

//    Keyboard.release(KEY_L);
}
