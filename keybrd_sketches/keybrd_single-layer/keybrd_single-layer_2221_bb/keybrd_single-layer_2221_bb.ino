/* keybrd_single-layer_2221_bb.ino, 4-key layout:
        1       2       3       4
        a       b       c       d
*/
// ********** INCLUDES **********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Exp.h>
#include <c_UCRowPort.h>
#include <c_UCRowPorts.h>
#include <c_UCColPort.h>
#include <c_UCColPorts.h>
#include <c_Matrix_UC.h>

#include <c_Keybrd.h>
#include <l_LayerManager.h>

// *********** LEFT ROWS OF KEYS ************
//row0
c_Key* const ptrsKey_L0[] = {     &k_1,           &k_2         };
c_Row_Ex row_L0(ptrsKey_L0, 2);

//row1
c_Key* const ptrsKey_L1[] = {     &k_a,           &k_b         };
c_Row_Ex row_L1(ptrsKey_L1, 2);

// *********** RIGHT ROWS OF KEYS ************
//row0
c_Key* const ptrsKey_R0[] = {     &k_3,           &k_4         };
c_Row_Ex row_R0(ptrsKey_R0, 2);

//row1
c_Key* const ptrsKey_R1[] = {     &k_c,           &k_d         };
c_Row_Ex row_R1(ptrsKey_R1, 2);

//static variables
c_Row_Ex* const ptrsRow[] = { &row_R0, &row_R1 };
c_Row_Ex* const* const c_UCRowPort::ptrsRows = ptrsRow;

c_RowWait rowWait(4, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

/*************** ROW PORTS *************
 * row: 0   1
 * pin: F0  F1
 */
c_UCRowPort rowPort_F(PORTF, DDRF, 1<<0 | 1<<1 );
c_UCRowPort* rowsPorts[] = { &rowPort_F };
c_UCRowPorts rows(rowsPorts, 1);

/*************** COL PORTS *************
 * col: 0   1
 * pin: B0  B1
 */
c_UCColPort colPort_B(PORTB, DDRB, PINB, 1<<0 | 1<<1 );
c_UCColPort* colPorts[] = { &colPort_B };
c_UCColPorts cols(colPorts, 1);

// ************* MATRICES **************
//matrix_L
c_Row_Ex* const ptrsRow_L[] = { &row_L0, &row_L1 };
const uint8_t ROWS_L_COUNT = sizeof(ptrsRow_L)/sizeof(ptrsRow_L[0]);

//the c_Matrix_Exp arguements are for the MCP23018 I/O Expander
c_Matrix_Exp matrix_L(ptrsRow_L, ROWS_L_COUNT, 0x20, 0x12, 0x0C, 0x13, 0x01);

//matrix_R
c_Matrix_UC matrix_R(&rows, &cols);

// ************** KEYBOARD *************
//c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Matrix* const ptrsMatrix[] = { &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 1);

// **************** RUN ****************
void setup() { keybrd.begin(); }
void loop()  { keybrd.scan();  }
