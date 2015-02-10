#ifndef K_KEY_NULL_H
#define K_KEY_NULL_H
#include <Arduino.h>
#include "c_Key.h"

/* Class k_Key_Null doesn't no anything.  It is usefull for blank keys.
 */
class k_Key_Null: public c_Key
{
    public:
        void press() {};
        void release() {};
};
#endif
