#include "c_PortColsAVR.h"

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be processed after all the IC's ports are read and strobe is turned off.
*/
void c_PortColsAVR::readPortCols()
{
    portState = PIN;
}
