/* keybrd_single-layer_2221_bb.ino, 4-key layout:
        1       2       3       4
        a       b       c       d
*/
// ========== INCLUDES ==========
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_RowPort_AVR.h>
#include <c_ColPort_AVR.h>
#include <c_RowPort_MCP23018.h>
#include <c_ColPort_MCP23018.h>
#include <c_Matrix.h>

//keybrd_Layers library files
#include <c_Keybrd.h>
#include <l_LayerManager.h>

// =============== LEFT =====================
// ----------- LEFT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_L0[] = {     &k_1,           &k_2         };
c_Row_Ex row_L0(ptrsKey_L0, 2);

//row1
c_Key* const ptrsKey_L1[] = {     &k_a,           &k_b         };
c_Row_Ex row_L1(ptrsKey_L1, 2);

// --------------- LEFT ROW PORTS -------------
// row: 0   1
// pin: B0  B1

c_RowPort_MCP23018 rowPortB_L(0x20, 0x01, 0x13, 1<<0 | 1<<1 );

// --------------- LEFT COL PORTS -------------
// col: 0   1
// pin: A0  A1

c_ColPort_MCP23018 colPortA_L(0x20, 0x00, 0x12, 0x0C, 1<<0 | 1<<1 );

// ------------- LEFT MATRIX --------------
c_Row_Ex* const ptrsRows_L[] = { &row_L0, &row_L1 };
c_RowPort* ptrsRowPorts_L[] = { &rowPortB_L };
c_ColPort* ptrsColPorts_L[] = { &colPortA_L };
c_Matrix matrix_L(ptrsRows_L, ptrsRowPorts_L, 1, ptrsColPorts_L, 1);

// =============== RIGHT ====================
// ----------- RIGHT ROWS OF KEYS ------------
//row0
c_Key* const ptrsKey_R0[] = {     &k_3,           &k_4         };
c_Row_Ex row_R0(ptrsKey_R0, 2);

//row1
c_Key* const ptrsKey_R1[] = {     &k_c,           &k_d         };
c_Row_Ex row_R1(ptrsKey_R1, 2);

//static variables
c_RowWait rowWait(4, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// --------------- RIGHT ROW PORTS -------------
// row: 0   1
// pin: F0  F1

c_RowPort_AVR rowPortF_R(DDRF, PORTF, 1<<0 | 1<<1 );

// --------------- RIGHT COL PORTS -------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// ------------- RIGHT MATRIX --------------
c_Row_Ex* const ptrsRows_R[] = { &row_R0, &row_R1 };
c_RowPort* ptrsRowPorts_R[] = { &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortB_R };
c_Matrix matrix_R(ptrsRows_R, ptrsRowPorts_R, 1, ptrsColPorts_R, 1);

// ============== KEYBOARD =============
c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };//unresponsive on matrix_L
//c_Matrix* const ptrsMatrix[] = { &matrix_R };//works
//c_Matrix* const ptrsMatrix[] = { &matrix_L };//unresponsive
c_Keybrd keybrd(ptrsMatrix, 2);

// ================ RUN ================
void setup() { keybrd.begin(); }
void loop()  { keybrd.scan();  }
