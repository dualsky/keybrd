#ifndef M_MOUSEBUTTON_H
#define M_MOUSEBUTTON_H
#include <Arduino.h>
#include <inttypes.h>
#include <Mouse.h>
#include "m_Mouse.h"

/* Class m_MouseButton can be used with single-layer or multiple-layer keybrds.
 * http://arduino.cc/en/Reference/MouseKeyboard
 * shift modifies mouse buttons  http://en.wikipedia.org/wiki/Shift_key > mouse
 */
class m_MouseButton: public m_Mouse
{
    private:
        const uint16_t scancode;                //MOUSE_LEFT MOUSE_RIGHT MOUSE_MIDDLE
    public:
        m_MouseButton(const uint16_t sc): scancode(sc) { }
        void press();
        void release();
};
#endif
