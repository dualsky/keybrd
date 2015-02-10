#include "m_MouseButton.h"

void m_MouseButton::press()
{
    Mouse.press(scancode);
}

void m_MouseButton::release()
{
    Mouse.release(scancode);
}
