#ifndef L_CODE_NASLOCK_H
#define L_CODE_NASLOCK_H

#include <l_Code_NAS.h>
#include <l_LayerManager.h>

class l_Code_NASLock : public l_Code_NAS        //inherit static resumeLayer
{
    public:
        void press();
        void release();
};
#endif
