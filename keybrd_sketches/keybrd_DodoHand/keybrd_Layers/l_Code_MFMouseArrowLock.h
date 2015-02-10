#ifndef L_CODE_MFMOUSEARROWLOCK_H
#define L_CODE_MFMOUSEARROWLOCK_H

#include <inttypes.h>
#include <l_Code_MF.h>
#include <l_LayerManager.h>

class l_Code_MFMouseArrowLock : public l_Code_MF //inherit static bool pressed
{
    private:
        const uint8_t layerCode;
    public:
        l_Code_MFMouseArrowLock(const uint8_t lc): layerCode(lc) {}
        void press();
        void release();
};
#endif
