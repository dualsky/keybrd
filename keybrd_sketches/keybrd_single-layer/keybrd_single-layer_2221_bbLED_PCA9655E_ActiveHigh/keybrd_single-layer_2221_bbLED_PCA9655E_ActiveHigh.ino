/* keybrd_single-layer_2221_bbLED_PCA9655E_ActiveHigh.ino, 4-key layout:
      Left Matrix       Rigth Matrix
      -----------       ------------
      LED     2         LED     4
      LED     b         c       d
with Teensy 2.0 and PCA9655E I/O expander
*/
// ========== INCLUDES ==========
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row.h>
#include <c_RowWait.h>
#include <c_RowPort_AVR_ActiveHigh.h>
#include <c_ColPort_AVR_ActiveHigh.h>
#include <c_RowPort_PCA9655E_ActiveHigh.h>
#include <c_ColPort_PCA9655E_ActiveHigh.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_LayerManager.h>

#include "c_IOExpanderPort.h"
#include "c_LED_AVR.h"
#include "c_LED_PCA9655E.h"
#include "k_Key_Lck_LED.h"

// =============== CONFIG =====================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

// =============== LEFT =====================
// -------- LEFT IO/EXPANDER PORTS ---------
c_IOExpanderPort port0_L(0x20, 0);
c_IOExpanderPort port1_L(0x20, 1);

// ------------ LEFT LED KEYS -------------
c_LED_PCA9655E capsLck_LED(port0_L, 1<<7);   //blue top row port
k_Key_Lck_LED k_capsLck(capsLck_LED);

c_LED_PCA9655E  numLck_LED(port1_L, 1<<2);   //green bot col port
k_Key_Lck_LED  k_numLck(numLck_LED);

// ----------- LEFT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_L0[] = {     &k_capsLck,   &k_2      };
c_Row row_L0(ptrsKey_L0, 2);

//row1
c_Key* const ptrsKey_L1[] = {     &k_numLck,    &k_b      };
c_Row row_L1(ptrsKey_L1, 2);

// --------------- LEFT ROW PORTS -------------
// row: 0   1
// pin: B0  B1

c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0_L, 1<<0 | 1<<1 );

// --------------- LEFT COL PORTS -------------
// col: 0   1
// pin: A0  A1

c_ColPort_PCA9655E_ActiveHigh colPort1_L(port1_L, 1<<0 | 1<<1 );

// ------------- LEFT MATRIX --------------
c_Row* const ptrsRows_L[] = { &row_L0, &row_L1 };
c_RowPort* ptrsRowPorts_L[] = { &rowPort0_L };
c_ColPort* ptrsColPorts_L[] = { &colPort1_L };
c_Matrix matrix_L(ptrsRows_L, 2, ptrsRowPorts_L, 1, ptrsColPorts_L, 1);

// =============== RIGHT ====================
// ------------ RIGHT LED KEYS -------------
c_LED_AVR scrollLck_LED(PORTB, 1<<3);
k_Key_Lck_LED k_scrollLck(scrollLck_LED);   //red

// ----------- RIGHT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_R0[] = {     &k_scrollLck,   &k_4       };
c_Row row_R0(ptrsKey_R0, 2);

//row1
c_Key* const ptrsKey_R1[] = {     &k_c,           &k_d       };
c_Row row_R1(ptrsKey_R1, 2);

// --------------- RIGHT ROW PORTS -------------
// row: 0   1
// pin: F0  F1

c_RowPort_AVR_ActiveHigh rowPortF_R(DDRF, PORTF, 1<<0 | 1<<1 );

// --------------- RIGHT COL PORTS -------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR_ActiveHigh colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// ------------- RIGHT MATRIX --------------
c_Row* const ptrsRows_R[] = { &row_R0, &row_R1 };
c_RowPort* ptrsRowPorts_R[] = { &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortB_R };
c_Matrix matrix_R(ptrsRows_R, 2, ptrsRowPorts_R, 1, ptrsColPorts_R, 1);

// ============== KEYBOARD =============
c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

// ================ RUN ================
void setup() { keybrd.begin(); }
void loop()  { keybrd.scan();  }
