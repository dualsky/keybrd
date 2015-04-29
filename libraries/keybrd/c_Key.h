#ifndef C_KEY_H
#define C_KEY_H
#include <Arduino.h>
#include <inttypes.h>

/* c_Key is an abstract base class
 */
class c_Key
{
    public:
        //empty begin overriden by k_Key_Lck_LED class
        virtual void begin() {}

        //sendPress() sends scancode to USB for press
        virtual void press()=0;

        //sendRelease() sends scancode to USB for release
        virtual void release()=0;
};
#endif
