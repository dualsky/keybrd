#ifndef L_CODE_NORMALLOCK_H
#define L_CODE_NORMALLOCK_H

#include <inttypes.h>
#include <l_Code_Layer.h>
#include <l_LayerManager.h>

class l_Code_NormalLock : public l_Code_Layer
{
    private:
        const uint8_t layerCode;
    public:
        l_Code_NormalLock(const uint8_t lc): layerCode(lc) {}
        void press();
        void release();
};
#endif
