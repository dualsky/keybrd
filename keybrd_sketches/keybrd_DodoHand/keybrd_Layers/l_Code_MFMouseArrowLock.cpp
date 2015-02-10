#include "l_Code_MFMouseArrowLock.h"

void l_Code_MFMouseArrowLock::press()
{
    if (pressed)                                //key protection between mouseOn and arrowOn
        {
        refLayerManager.lock(layerCode);
        }
}

void l_Code_MFMouseArrowLock::release()
{
}
