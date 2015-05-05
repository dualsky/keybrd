#ifndef L_KEY_LAYERED_H
#define L_KEY_LAYERED_H
#include <Arduino.h>
#include <inttypes.h>
#include "c_Key.h"
#include "l_Code.h"
#include <l_LayerManager.h>

/* Class l_Key_Layered contains an array of l_Code pointers, one pointer per layer.
 * When the key is pressed, the l_Code for the active layer is called.
 *
 * The layer may change while the key is being held down.
 * layerWhenPressed insures that the same l_Code that was called on press is called for release.
 */
class l_Key_Layered: public c_Key
{
    private:
        l_Code* const* const ptrsCodes;         //array of Codes, one l_Code object per layer
        uint8_t layerWhenPressed;               //active layer when key was pressed
        static l_LayerManager& refLayerManager;
    public:
        l_Key_Layered(l_Code* const pa[]): ptrsCodes(pa) {}
        void press();                           //send scancode to USB for press
        void release();                         //send scancode to USB for release
};
#endif
