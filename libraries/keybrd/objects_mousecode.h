/* m_MouseCodes.h can be included in single-layer or multiple-layer keybrds.ino
 * better yet, copy & paste what you need from this file rather than include it.
 * the MOUSE_LEFT, MOUSE_MIDDLE, and MOUSE_RIGHT macros are defined by Arduino
 */
#include <m_MouseButton.h>
#include <m_MouseMove.h>

#define MOUSE_SPEED 8

// ********** MOUSE CODES *********
m_MouseMove mm_right(MOUSE_SPEED,0,0);          //define MOUSE_SPEED in the keybrd.ino file
m_MouseMove mm_left(-MOUSE_SPEED,0,0);
m_MouseMove mm_down(0,MOUSE_SPEED,0);           //positive Y is down
m_MouseMove mm_up(0,-MOUSE_SPEED,0);

m_MouseButton mb_left(MOUSE_LEFT);
m_MouseButton mb_middle(MOUSE_MIDDLE);
m_MouseButton mb_right(MOUSE_RIGHT);

