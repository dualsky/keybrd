#ifndef M_MOUSE_MOVE_H
#define M_MOUSE_MOVE_H
#include <Arduino.h>
#include <inttypes.h>
#include <Mouse.h>
#include "m_Mouse.h"

/* Class m_Mouse_Move can be used with single-layer or multiple-layer keybrds.
 * press() moves mouse x, y, or scroll wheel //http://arduino.cc/en/Reference/MouseKeyboard
 * shift can modify mouse move  http://en.wikipedia.org/wiki/Shift_key > mouse
 */
class m_Mouse_Move: public m_Mouse
{
    private:
        const uint16_t x;
        const uint16_t y;
        const uint16_t wheel;
    public:
        m_Mouse_Move(const uint16_t x, const uint16_t y, const uint16_t w):
            x(x), y(y), wheel(w) { }
        void press();
        void release();
};
#endif
