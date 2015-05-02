/* keybrd_single-layer_2221_bb_Teensy2_PCA9655E.ino, 4-key layout:
      Left Matrix           Rigth Matrix
      -----------           ------------
      capsLck   2           3       scrollLck
      numLck    b           c       d
with Teensy 2.0 and PCA9655E I/O expander

not tested - waiting until a breadboard is free - see keybrd_tes_suite.ods > test 3
*/
// ========== INCLUDES ==========
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row.h>
#include <c_RowWait.h>
#include <c_RowPort_AVR.h>
#include <c_ColPort_AVR.h>
#include <c_RowPort_PCA9655E.h>
#include <c_ColPort_PCA9655E.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_LayerManager.h>

#include "c_IOExpanderPort.h"
#include "c_LED_AVR.h"
#include "c_LED_PCA9655E.h"
#include "k_Key_LckLED.h"

// =============== STATIC MEMBERS =====================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

// ############### MAIN #####################
void setup() {}
void loop()
{
// =============== LEFT =====================
// -------- LEFT IO/EXPANDER PORTS ---------
c_IOExpanderPort port0_L(0x20, 0);
c_IOExpanderPort port1_L(0x20, 1);

// --------------- LEFT ROW PORTS -------------
// row: 0   1
// pin: B0  B1

c_RowPort_PCA9655E rowPort0_L(port0_L, 1<<0 | 1<<1 );

// --------------- LEFT COL PORTS -------------
// col: 0   1
// pin: A0  A1

c_ColPort_PCA9655E colPort1_L(port1_L, 1<<0 | 1<<1 );

// ------------ LEFT LED KEYS -------------
c_LED_PCA9655E capsLck_LED_L(port0_L, 1<<7);   //blue top row port
k_Key_LckLED k_capsLck(KEY_CAPS_LOCK, capsLck_LED_L);

c_LED_PCA9655E  numLck_LED_L(port1_L, 1<<2);   //green bot col port
k_Key_LckLED k_numLck(KEY_NUM_LOCK, numLck_LED_L);

// ----------- LEFT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_L0[] = {     &k_capsLck,   &k_2      };
c_Row row_L0(ptrsKey_L0, 2);

//row1
c_Key* const ptrsKey_L1[] = {     &k_numLck,    &k_b      };
c_Row row_L1(ptrsKey_L1, 2);

// ------------- LEFT MATRIX --------------
c_Row* const ptrsRows_L[] = { &row_L0, &row_L1 };
c_RowPort* ptrsRowPorts_L[] = { &rowPort0_L };
c_ColPort* ptrsColPorts_L[] = { &colPort1_L };
c_Matrix matrix_L(ptrsRowPorts_L, 1, ptrsColPorts_L, 1, ptrsRows_L, 2);

// =============== RIGHT ====================
// this test shows how pins from any port can be used
// AVR PORTB is shared by c_RowPort_AVR (pin B2), c_ColPort_AVR (pins B0,1B), and c_LED_AVR (pin B3)
// rowPort uses pins B2 and F1
// --------------- RIGHT ROW PORTS -------------
// row: 0   1
// pin: B2  F1              (testing row with pins from two different ports)

c_RowPort_AVR rowPortB_R(DDRB, PORTB, 1<<2 );
c_RowPort_AVR rowPortF_R(DDRF, PORTF, 1<<1 );

// --------------- RIGHT COL PORTS -------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// ------------ RIGHT LED KEYS -------------
c_LED_AVR scrollLck_LED_R(PORTB, 1<<3);
k_Key_LckLED k_scrollLck(KEY_SCROLL_LOCK, scrollLck_LED_R);

// ----------- RIGHT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_R0[] = {     &k_3,    &k_scrollLck       };
c_Row row_R0(ptrsKey_R0, 2);

//row1
c_Key* const ptrsKey_R1[] = {     &k_c,           &k_d       };
c_Row row_R1(ptrsKey_R1, 2);

// ------------- RIGHT MATRIX --------------
c_Row* const ptrsRows_R[] = { &row_R0, &row_R1 };
c_RowPort* ptrsRowPorts_R[] = { &rowPortB_R, &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortB_R };
c_Matrix matrix_R(ptrsRowPorts_R, 1, ptrsColPorts_R, 1, ptrsRows_R, 2);

// ============== KEYBOARD =============
c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

// ================ RUN ================
    keybrd.begin();

    while (true)
    {
        keybrd.scan();
    }
}
