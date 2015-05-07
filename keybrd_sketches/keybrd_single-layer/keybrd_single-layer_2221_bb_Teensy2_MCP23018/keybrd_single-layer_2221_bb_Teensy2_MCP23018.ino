/* test 1 - keybrd_single-layer_2221_bb_Teensy2_MCP23018, 8-key layout:
      Left Matrix       Rigth Matrix
      -----------       ------------
      capsLck  2        3       mouse up
      null     b        c       right click
*/
// ################# GLOBAL ####################
// ================ INCLUDES ===================
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row.h>
#include <c_RowWait.h>
#include <c_RowPort_AVR.h>
#include <c_ColPort_AVR.h>
#include <c_RowPort_MCP23018.h>
#include <c_ColPort_MCP23018.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_LayerManager.h>

#include "c_IOExpanderPort.h"
#include "c_LED_AVR.h"
#include "c_LED_MCP23018.h"
#include "k_Key_LckLED.h"

#include <Mouse.h>
#include <m_Mouse_Button.h>
#include <m_Mouse_Move.h>

// ============= STATIC MEMBERS ================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

// ################## MAIN #####################
void setup() {}
void loop()
{
// ================== KEYS =====================
m_Mouse_Button mb_right(MOUSE_RIGHT);
m_Mouse_Move mm_up(0,-8,0);                     //negative Y is up
    
// ================== LEFT =====================
// -------- LEFT I/O EXPANDER PORTS ------------
c_IOExpanderPort portA_L(0x20, 0);
c_IOExpanderPort portB_L(0x20, 1);

// ------------- LEFT ROW PORTS ----------------
// row: 0   1
// pin: B0  B1

c_RowPort_MCP23018 rowPortB_L(portB_L, 1<<0 | 1<<1 );

// ------------- LEFT COL PORTS ----------------
// col: 0   1
// pin: A0  A1

c_ColPort_MCP23018 colPortA_L(portA_L, 1<<0 | 1<<1 );

// ------------- LEFT LED KEYS -----------------
c_LED_MCP23018 capsLck_LED_L(portB_L, 1<<2);
k_Key_LckLED k_capsLck(KEY_CAPS_LOCK, capsLck_LED_L);

// --------------- LEFT ROWS -------------------
//row0
c_Key* ptrsKey_L0[] = {     &k_capsLck,   &k_2      };
c_Row row_L0(ptrsKey_L0, 2);

//row1
c_Key* ptrsKey_L1[] = {     &k_null,    &k_b      };
c_Row row_L1(ptrsKey_L1, 2);

// -------------- LEFT MATRIX ------------------
c_Row* ptrsRows_L[] = { &row_L0, &row_L1 };
c_RowPort* ptrsRowPorts_L[] = { &rowPortB_L };
c_ColPort* ptrsColPorts_L[] = { &colPortA_L };
c_Matrix matrix_L(ptrsRowPorts_L, 1, ptrsColPorts_L, 1, ptrsRows_L, 2);

// ================= RIGHT =====================
// this test shows how pins from any port can be used
// AVR PORTB is shared by c_RowPort_AVR (pin B2) and c_ColPort_AVR (pins B0 and B1)
// rowPort uses pins B2 and F1
// ------------ RIGHT ROW PORTS ----------------
// row: 0   1
// pin: B2  F1              (testing row with pins from two different ports)

c_RowPort_AVR rowPortB_R(DDRB, PORTB, 1<<2 );
c_RowPort_AVR rowPortF_R(DDRF, PORTF, 1<<1 );

// ------------ RIGHT COL PORTS ----------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// -------------- RIGHT KEYS -------------------
//row0
c_Key* ptrsKey_R0[] = {     &k_3,   &mm_up      };
c_Row row_R0(ptrsKey_R0, 2);

//row1
c_Key* ptrsKey_R1[] = {     &k_c,   &mb_right       };
c_Row row_R1(ptrsKey_R1, 2);

// ------------- RIGHT MATRIX ------------------
c_Row* ptrsRows_R[] = { &row_R0, &row_R1 };
c_RowPort* ptrsRowPorts_R[] = { &rowPortB_R, &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortB_R };
c_Matrix matrix_R(ptrsRowPorts_R, 2, ptrsColPorts_R, 1, ptrsRows_R, 2);

// =============== KEYBOARD ====================
c_Matrix* ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

// ================== RUN ======================
    keybrd.begin(); 

    while (true)
    {
        keybrd.scan();
    }
}
