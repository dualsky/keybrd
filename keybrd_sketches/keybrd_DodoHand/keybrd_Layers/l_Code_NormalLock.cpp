#include "l_Code_NormalLock.h"

void l_Code_NormalLock::press()
{
    refLayerManager.lock(layerCode);
}

void l_Code_NormalLock::release()
{
}
