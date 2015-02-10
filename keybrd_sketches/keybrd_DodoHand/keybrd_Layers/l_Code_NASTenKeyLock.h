#ifndef L_CODE_NASTENKEYLOCK_H
#define L_CODE_NASTENKEYLOCK_H

#include <inttypes.h>
#include <l_Code_NAS.h>
#include <l_LayerManager.h>

class l_Code_NASTenKeyLock : public l_Code_NAS   //inherit static resumeLayer
{
    private:
        const uint8_t layerCode;
    public:
        l_Code_NASTenKeyLock(const uint8_t lc): layerCode(lc) {}
        void press();
        void release();
};
#endif
