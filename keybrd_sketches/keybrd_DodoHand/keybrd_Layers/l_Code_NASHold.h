#ifndef L_CODE_NASHOLD_H
#define L_CODE_NASHOLD_H

#include <l_Code_NAS.h>
#include <l_LayerManager.h>

//hold NAS key
class l_Code_NASHold : public l_Code_NAS        //inherit static resumeLayer
{
    public:
        void press();
        void release();
};
#endif
