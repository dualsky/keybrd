#ifndef L_CODE_H
#define L_CODE_H

class l_ShiftManager;

/* l_Code is an abstract base class
 * It's derived concrete classes send press and release USB scancodes to the computer.
*/
class l_Code
{
    protected:
        static l_ShiftManager& refShiftManager;
    public:
        virtual void press()=0;
        virtual void release()=0;
};
#endif
