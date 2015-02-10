#ifndef L_CODE_LAYER_H
#define L_CODE_LAYER_H

#include <inttypes.h>
#include "l_Code.h"
#include "l_LayerManager.h"

/* Class l_Code_Layer is composed of a layerCode, which it sends to LayerManager when pressed.
 */
class l_Code_Layer: public l_Code
{
    private:
        const uint8_t layerCode;
        static l_LayerManager& refLayerManager;
    public:
        l_Code_Layer(const uint8_t lc): layerCode(lc) {}
        void press();
        void release();
};
#endif
