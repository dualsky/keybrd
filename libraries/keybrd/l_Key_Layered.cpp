#include "l_Key_Layered.h"

void l_Key_Layered::press()
{
    layerWhenPressed = refLayerManager.getActiveLayer();
    ptrsCodes[layerWhenPressed]->press();
}

void l_Key_Layered::release()
{
    ptrsCodes[layerWhenPressed]->release();
}
