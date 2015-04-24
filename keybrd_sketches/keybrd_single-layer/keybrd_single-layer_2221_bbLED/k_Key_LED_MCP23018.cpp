#include "k_Key_LED_MCP23018.h"

void k_Key_LED_MCP23018::press()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal &= ~pin);           //set pin low (sink)
    Wire.endTransmission();

//    Keyboard.press(KEY_L);
}

void k_Key_LED_MCP23018::release()
{
    Wire.beginTransmission(port.ADDR);
    Wire.write(GPIO);
    Wire.write(port.outputVal |= pin);            //set pin high (sink off)
    Wire.endTransmission();

//    Keyboard.release(KEY_L);
}
