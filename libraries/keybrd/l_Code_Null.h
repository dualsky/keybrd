#ifndef L_CODE_NULL_H
#define L_CODE_NULL_H
#include <Arduino.h>
#include "l_Code.h"

/* Class l_Code_Null doesn't no anything.  It is usefull for blank keys.
 */
class l_Code_Null: public l_Code
{
    public:
        void press() {};
        void release() {};
};
#endif
