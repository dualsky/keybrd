#include "c_PortColsAVR.h"

/* Read port and store it in portState quickly so that strobe is on for shortest possible time.
Reading and storing portState at once is faster than reading and saving each pin individually.
portState will be read one pin at a time in portToRowState() after strobe is turned off.
*/
void c_PortColsAVR::readPortCols()
{
    portState = PIN;
}
