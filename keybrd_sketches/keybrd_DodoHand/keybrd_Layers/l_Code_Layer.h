#ifndef L_CODE_LAYER_H
#define L_CODE_LAYER_H

#include <inttypes.h>
#include "l_Code.h"

class l_LayerManager;

/* Concrete l_Code_Layer class names are concatenations of mode name and persistance
 *
 * 1) Mode name
 *      Normal - Alpha
 *      NAS - Numbers And Symbols
 *      NASTenKeyLock - TEN_KEY_OFF, TEN_KEY_ON
 *      MF - Mouse Function
 *      MFMouseArrowLock - MOUSE_ON, ARROW_ON
 *
 * 2) Persistance
 *      Lock - layer remains active after the layer key is released
 *      Hold - layer is active for as long as layer key is held down
 *
 * Varibles are:
 *      layerCode - defined in keybrd sketch
 *                  enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MOUSE_ON, ARROW_ON };
 *      resumeLayer - TEN_KEY_OFF or TEN_KEY_ON.  Activate resumeLayer next time NAS key is pressed
 *      pressed - true if MF key is pressed
 *
 * l_Code_Layer objects call LayerManager.
 * l_LayerManager keeps track of activeLayer and lockedLayer.

Inheritance diagram: (first two levels are abstract)
                    ______________ l_Code_Layer _______________________________
                   /                   |                                       \
                  /               l_Code_NAS                                l_Code_MF
                 /              _ static resumeLayer _                      static bool pressed
                /              /       |              \                       /         \
l_Code_NormalLock  l_Code_NASLock l_Code_NASHold l_Code_NASTenKeyLock  l_Code_MFLock   l_Code_MFMouseArrowLock
const layerCode                                  const layerCode       const layerCode const layerCode

Association diagrams:
        normal
           |
        layerCode

             ____________ resumeLayer __________________________
            /      /     /         \           \                \
        NASLock  NAS  tenKeyOff  tenKeyOn  tenKeyOff_NumLck  tenKeyOff_NumLck
                        |           |           |                |
                      layerCode  layerCode layerCode         layerCode

             ______ pressed ____
            /          |        \
          MF        arrowOn    mouseOn
           |           |         |
        layerCode   layerCode  layerCode

Objects names are from DataHandProIIUserGuide.pdf
not shown: l_LayerManager is called by all l_Code objects
*/
class l_Code_Layer: public l_Code
{
    protected:
        static l_LayerManager& refLayerManager;
};
#endif
