#ifndef M_MOUSE_BUTTON_H
#define M_MOUSE_BUTTON_H
#include <Arduino.h>
#include <inttypes.h>
#include <Mouse.h>
#include "m_Mouse.h"

/* Class m_Mouse_Button can be used with single-layer or multiple-layer keybrds.
 * http://arduino.cc/en/Reference/MouseKeyboard
 * shift modifies mouse buttons  http://en.wikipedia.org/wiki/Shift_key > mouse
 */
class m_Mouse_Button: public m_Mouse
{
    private:
        const uint16_t scancode;                //MOUSE_LEFT MOUSE_RIGHT MOUSE_MIDDLE
    public:
        m_Mouse_Button(const uint16_t sc): scancode(sc) { }
        void press();
        void release();
};
#endif
