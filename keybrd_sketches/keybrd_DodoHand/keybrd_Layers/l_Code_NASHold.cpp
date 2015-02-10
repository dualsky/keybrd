#include "l_Code_NASHold.h"

void l_Code_NASHold::press()
{
    refLayerManager.hold(resumeLayer);
}

void l_Code_NASHold::release()
{
    refLayerManager.unhold();
}
