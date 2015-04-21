#include "c_ColPort_MCP23018.h"

void c_ColPort_MCP23018::begin()
{
/* original
    Wire.beginTransmission(ADDR);
    Wire.write(IODIR);
    Wire.write(PINS); //0=configure as output (for LED), 1=configure as input (for read)
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(GPPU);
    Wire.write(PINS); //0=configure pull-up disabled (for LED), 1=configure pull-up enabled (for read)
    Wire.endTransmission();
    */
/* debug
    Wire.beginTransmission(ADDR);
    Wire.write(0x00);                           //IODIRB Configuration Port A
    Wire.write(~0);                             //as input
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x0C);                           //GPPUB pull-up Port A
    //Wire.write(~0);                             //pull-up enabled
Wire.write(0);
    Wire.endTransmission();    
Serial.print("\nin c_ColPort_MCP23018::begin()");
*/
    Wire.beginTransmission(ADDR);
    Wire.write(0x00);                           //IODIRA Configuration Port A
    Wire.write(~0);                             //as input
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x0C);                           //GPPUB pull-up Port A
    Wire.write(~0);                             //pull-up enabled
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x01);                           //IODIRB Configuration Port B
    Wire.write(~0);                             //as input
    Wire.endTransmission();

    Wire.beginTransmission(ADDR);
    Wire.write(0x0D);                           //GPPUB pull-up Port B
    Wire.write(~0);                             //pull-up enabled
    Wire.endTransmission();
}

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's ports are read and strobe is turned off.
*/
void c_ColPort_MCP23018::read()
{
/* original
    Wire.beginTransmission(ADDR);
    Wire.write(GPIO);                           //GPIO immediately before requestFrom
    Wire.endTransmission(); */

/*debug
    Wire.beginTransmission(ADDR);
    Wire.write(0x12);                           //GPIOA 0x12(Port A immediately before requestFrom)
    Wire.endTransmission();
    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input port
*/

//    portState = Wire.read();

/* debug
if (portState < B11111111) //if a low pin was detected
    {   //todo delete
    Serial.print("\nportState = ");  Serial.print(portState, BIN);//all 1s, no low pin detected
    }
*/
    //port A
    Wire.beginTransmission(ADDR);
    Wire.write(0x12);                           //GPIOA (Port A immediately before requestFrom)
    Wire.endTransmission();

    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input Port A

    portState = Wire.read();
    Serial.print("\nportState A = ");  Serial.print(portState, BIN);

    //port B
    Wire.beginTransmission(ADDR);
    Wire.write(0x13);                           //GPIOB (Port B immediately before requestFrom)
    Wire.endTransmission();

    Wire.requestFrom(ADDR, static_cast<uint8_t>(1)); //request one byte from input Port B

    portState = Wire.read();
    Serial.print("\nportState B = ");  Serial.print(portState, BIN);

while (true) {}    
}
