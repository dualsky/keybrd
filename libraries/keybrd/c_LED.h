#ifndef C_LED_H
#define C_LED_H
//LED is an abstract base class
class c_LED
{
    public:
        virtual void on()=0;
        virtual void off()=0;
};
#endif
