#ifndef L_LAYERMANAGER_H
#define L_LAYERMANAGER_H

#include <Keyboard.h>
#include <inttypes.h>

/* Rudimentary layer manager for keybrd_multi-layer examples.
 * l_LayerManager keeps track of activeLayer.
 */
class l_LayerManager
{
    private:
        uint8_t activeLayer;                    //most recently pressed layer key
    public:
        l_LayerManager(): activeLayer(0) {}
        void setActiveLayer(uint8_t layerCode);
        uint8_t getActiveLayer();
};
#endif
