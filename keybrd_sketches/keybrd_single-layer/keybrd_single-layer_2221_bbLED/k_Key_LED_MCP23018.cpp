#include "k_Key_LED_MCP23018.h"

void k_Key_LED_MCP23018::press()
{
Serial.print("\npress gpioVal=");  Serial.print(gpioVal, BIN);    
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal &= ~pin);                //set pin low (sink)
    Wire.endTransmission();

    Keyboard.press(KEY_L);
Serial.print("  gpioVal=");  Serial.print(gpioVal, BIN);    
delay(200);//LED turns off after delay
}

void k_Key_LED_MCP23018::release()
{
Serial.print("  gpioVal=");  Serial.print(gpioVal, BIN);    
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);
    Wire.write(gpioVal |= pin);                 //set pin high (sink off)
    Wire.endTransmission();

    Keyboard.release(KEY_L);
Serial.print("  gpioVal=");  Serial.print(gpioVal, BIN);    
}
