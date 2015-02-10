#include "l_Code_NASTenKeyLock.h"

void l_Code_NASTenKeyLock::press()
{
    refLayerManager.lock(layerCode);
    resumeLayer = layerCode;
}

void l_Code_NASTenKeyLock::release()
{
}
