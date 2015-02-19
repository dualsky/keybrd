#ifndef L_CODE_LAYER_H
#define L_CODE_LAYER_H

#include <inttypes.h>
#include "l_Code.h"

class l_LayerManager;

/* l_Code_Layer is an abstract base class
 */
class l_Code_Layer: public l_Code
{
    protected:
        static l_LayerManager& refLayerManager;
};
#endif
