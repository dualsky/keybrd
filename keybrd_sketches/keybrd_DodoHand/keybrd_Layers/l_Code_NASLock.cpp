#include "l_Code_NASLock.h"

void l_Code_NASLock::press()
{
    refLayerManager.lock(resumeLayer);
}

void l_Code_NASLock::release()
{
}
