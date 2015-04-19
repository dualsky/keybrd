/* keybrd_single-layer_1221_bb.ino, 4-key layout:
        1       2
        a       b
*/
// ********** INCLUDES **********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_RowPort_AVR.h>
#include <c_PortColsAVR.h>
#include <c_Matrix.h>

#include <c_Keybrd.h>
#include <l_LayerManager.h>

// ************ TRANSFORMS *************
// *********** ROWS OF KEYS ************
//row0
c_Key* const ptrsKey_0[] = {     &k_1,     &k_2   };
c_Row_Ex row_0(ptrsKey_0, 2);

//row1
c_Key* const ptrsKey_1[] = {    &k_a,      &k_b    };
c_Row_Ex row_1(ptrsKey_1, 2);

//static variables
c_Row_Ex* const ptrsRows[] = { &row_0, &row_1 };
c_Row_Ex* const* const c_RowPort::ptrsRows = ::ptrsRows;

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

/*************** PORT ROWS *************
 * row: 0   1
 * pin: B2  F1              (testing row with pins from two different ports)
 */
c_RowPort_AVR portBRows(DDRB, PORTB, 1<<2 );
c_RowPort_AVR portFRows(DDRF, PORTF, 1<<1 );
c_RowPort* ptrsPortsRows[] = { &portBRows, &portFRows };//todo rename ptrsRowPorts[]

/*************** PORT COLS *************
 * col: 0   1
 * pin: B0  B1
 */
c_PortColsAVR portBCols(DDRB, PORTB, PINB, 1<<0 | 1<<1 );
c_PortCols* ptrsPortsCols[] = { &portBCols };

// ************** MATRIX ***************
//matrix
c_Matrix matrix(ptrsPortsRows, 2, ptrsPortsCols, 1);

// ************** KEYBOARD *************
c_Matrix* const ptrsMatrix[] = { &matrix };
c_Keybrd keybrd(ptrsMatrix, 1);

// **************** RUN ****************
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
