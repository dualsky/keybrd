#include "l_Code_MFLock.h"

void l_Code_MFLock::press()
{
    refLayerManager.lock(layerCode);
    pressed = true;
}

void l_Code_MFLock::release()
{
    pressed = false;
}
