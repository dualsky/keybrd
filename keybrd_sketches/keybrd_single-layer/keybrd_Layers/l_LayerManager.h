#ifndef L_LAYERMANAGER_H
#define L_LAYERMANAGER_H

/* dummy layer manager for keybrd_single-layer sketches.
 Arduino IDE needs keybrd_Layers/c_LayerManager.h defined for keybrd_single-layer.ino
 because keybrd/l_Key_Layered.h includes keybrd_Layers/l_LayerManager.h
 and Arduino links every file in library, if they are used or not.
*/
class l_LayerManager
{
    public:
        uint8_t getActiveLayer() { return 0; };
};
#endif
