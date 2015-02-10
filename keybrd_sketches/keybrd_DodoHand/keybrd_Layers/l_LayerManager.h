#ifndef L_LAYERMANAGER_H
#define L_LAYERMANAGER_H

#include <iostream>
#include <inttypes.h>

/* l_LayerManager for the DodoHand keybaord.
 * Pass initial layer id for "Noramal" layer to constructor.
 *
 * The layer scheme is based on the DataHand keyboard described in DataHandProIIUserGuide.pdf.
 * l_LayerManager keeps track of activeLayer and lockedLayer.
 * Explanation and diagrams are in l_Code_Layer.h
 */
class l_LayerManager
{
    private:
        uint8_t activeLayer;                    //currently active layer
        uint8_t lockedLayer;                    //most recently pressed lock layer
    public:
        l_LayerManager(uint8_t initLayer): activeLayer(initLayer), lockedLayer(initLayer) {}
        void lock(uint8_t layerCode);           //set activeLayer and lock it
        void hold(uint8_t layerCode);           //set activeLayer
        void unhold();                          //restore activeLayer to lockedLayer
        uint8_t getActiveLayer();
};
#endif
