#include "l_LayerManager.h"

void l_LayerManager::setActiveLayer(uint8_t layerCode)
{
    activeLayer = layerCode;
}

uint8_t l_LayerManager::getActiveLayer()
{
    return activeLayer;
}
