#include "m_Mouse_Button.h"

void m_Mouse_Button::press()
{
    Mouse.press(scancode);
}

void m_Mouse_Button::release()
{
    Mouse.release(scancode);
}
