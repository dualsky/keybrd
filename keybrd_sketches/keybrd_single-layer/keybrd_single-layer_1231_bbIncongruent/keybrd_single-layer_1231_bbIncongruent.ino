/* keybrd_single-layer_1231_bbIncongruent.ino, 6-key layout:
        a       b       c
        1       2       3
*/
// ********** INCLUDES **********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
//#include <c_Matrix_Teensy2.h>
//#include <c_Matrix_MCP23018.h>
#include <c_UCRowPort.h>
#include <c_UCRowPorts.h>
#include <c_UCColPort.h>
#include <c_UCColPorts.h>
#include <c_Matrix_UC.h>

#include <c_Keybrd.h>
#include <l_LayerManager.h>

/*************** TRANSFORM *************
This macro function transforms layout to matrix rows.
Layout is the placements of keys on a keyboard.
Matrix is the electrical row and column connections to the keys.
Matrix rows and columns are distinguishable by diode orientation.
Diode anodes point to matrix rows.  Diode cathodes point to matrix columns.

The transform function parameters list contians the layout coordinates.
Each "K" is followed by row-col layout coordinates.
Row coordinates start with 0 on top.  Col coordinates start with 0 on left.

Function body contains the matrix.
Rows and columns are pins, in the order listed in rowsPorts[] and colPorts[] arrays (below).
Each "&k_##" is followed by layout coordinates.
The layout coordinates map to the row-col pins.
*/
#define TRANSFORM( \
        K00, K01, K02, \
        K10, K11, K12  \
) \
c_Key* const ptrsKey_0[] = { &k_##K10, &k_##K00 }; \
c_Key* const ptrsKey_1[] = { &k_##K11, &k_##K01 }; \
c_Key* const ptrsKey_2[] = { &k_##K12, &k_##K02 };
//                            pin B2    pin F1
//todo name arrays after pins, after swaping ports??
// ************** LAYOUT ***************
TRANSFORM(
a,  b,  c,
1,  2,  3)

// *********** ROWS OF KEYS ************
//row objects
c_Row_Ex row_0(ptrsKey_0, 2);
c_Row_Ex row_1(ptrsKey_1, 2);
c_Row_Ex row_2(ptrsKey_2, 2);

//static variables
c_Row_Ex* const ptrsRow[] = { &row_0, &row_1, &row_2 };
c_Row_Ex* const* const c_UCRowPort::ptrsRows = ptrsRow;

c_RowWait rowWait(3, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

/*************** ROW PORTS ************* ANODE PORTS??
 * row: 0   1   2
 * pin: C7  B0  B1
 */
c_UCRowPort rowPort_C(PORTC, DDRC, 1<<7 );
c_UCRowPort rowPort_B(PORTB, DDRB, 1<<0 | 1<<1 );//portB strobing both row pins for one reading
c_UCRowPort* rowPorts[] = { &rowPort_C, &rowPort_B };
c_UCRowPorts rows(rowPorts, 2);

/*************** COL PORTS ************* CATHODE PORTS??
 * col: 0   1
 * pin: B2  F1
 */
c_UCColPort colPort_B(PORTB, DDRB, PINB, 1<<2 );
c_UCColPort colPort_F(PORTF, DDRF, PINF, 1<<1 );
c_UCColPort* colsPorts[] = { &colPort_B, &colPort_F };
c_UCColPorts cols(colsPorts, 2);

// ************** MATRIX ***************
//matrix
c_Matrix_UC matrix(&rows, &cols);

//c_Row_Ex* const ptrsRow[] = { &row_0, &row_1 };
//c_Matrix_Teensy2 matrix(ptrsRow, 2);

// ************** KEYBOARD *************
c_Matrix* const ptrsMatrix[] = { &matrix };
c_Keybrd keybrd(ptrsMatrix, 1);

// **************** RUN ****************
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
