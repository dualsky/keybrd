#ifndef L_CODE_NAS_H
#define L_CODE_NAS_H

#include <l_Code_Layer.h>

class l_Code_NAS : public l_Code_Layer
{
    protected:
        static uint8_t resumeLayer;             //activate resumeLayer next time NAS Mode is pressed
};
#endif
