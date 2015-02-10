#ifndef L_CODE_MFLOCK_H
#define L_CODE_MFLOCK_H

#include <inttypes.h>
#include <l_Code_MF.h>
#include <l_LayerManager.h>

class l_Code_MFLock : public l_Code_MF          //inherit static bool pressed
{
    private:
        const uint8_t layerCode;
    public:
        l_Code_MFLock(const uint8_t lc): layerCode(lc) {}
        void press();
        void release();
};
#endif
