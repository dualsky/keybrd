//l_LayerManager.cpp for DodoHand keybaord
#include "l_LayerManager.h"

void l_LayerManager::lock(uint8_t layerCode)
{
    activeLayer = layerCode;
    lockedLayer = layerCode;
}

void l_LayerManager::hold(uint8_t layerCode)
{
    activeLayer = layerCode;
}

void l_LayerManager::unhold()
{
    activeLayer = lockedLayer;
}

uint8_t l_LayerManager::getActiveLayer()
{
    return activeLayer;
}
