#ifndef M_MOUSE_H
#define M_MOUSE_H
#include <Arduino.h>
#include "c_Key.h"
#include "l_Code.h"

/* m_Mouse is an abstract class.
 * Multiple inhertance alows it to be used with single-layer or multiple-layer keybrds.
 */
class m_Mouse: public c_Key, public l_Code
{
};
#endif
