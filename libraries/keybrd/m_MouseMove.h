#ifndef M_MOUSEMOVE_H
#define M_MOUSEMOVE_H
#include <Arduino.h>
#include <inttypes.h>
#include <Mouse.h>
#include "m_Mouse.h"

/* Class m_MouseMove can be used with single-layer or multiple-layer keybrds.
 * press() moves mouse x, y, or scroll wheel //http://arduino.cc/en/Reference/MouseKeyboard
 * shift can modify mouse move  http://en.wikipedia.org/wiki/Shift_key > mouse
 */
class m_MouseMove: public m_Mouse
{
    private:
        const uint16_t x;
        const uint16_t y;
        const uint16_t wheel;
    public:
        m_MouseMove(const uint16_t x, const uint16_t y, const uint16_t w):
            x(x), y(y), wheel(w) { }
        void press();
        void release();
};
#endif
