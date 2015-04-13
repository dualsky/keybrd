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
#include <c_UCRowPort.h>
#include <c_UCRowPorts.h>
#include <c_UCColPort.h>
#include <c_UCColPorts.h>
#include <c_Matrix_AVR.h>

#include <c_Keybrd.h>
#include <l_LayerManager.h>

/*************** TRANSFORM *************
TRANSFORM() is a macro function that transforms layout to matrix rows.
Layout is the placements of keys on a keyboard.
Matrix is the electrical row and column connections to the keys.
Matrix rows and columns are distinguishable by diode orientation.
The keybrd library defines matrix rows as connected to diode anodes,
and matrix columns as connected to diode cathodes.

The transform function parameters list contians the layout coordinates.
Each "K" is followed by row-col layout coordinates.
Row coordinates start with 0 on top.  Col coordinates start with 0 on left.

The function body contains the matrix.
Rows and columns are labeled after connected pin names (in array names and comment below body).
Pin names are in the order listed in rowsPorts[] and colPorts[] arrays (below).
Each "&k_##" element is followed by layout coordinates.
The layout coordinates map to the row-col pins.
*/
#define TRANSFORM( \
        K00, K01, K02, \
        K10, K11, K12  \
) \
c_Key* const ptrsKey_C7[] = { &k_##K10, &k_##K00 }; \
c_Key* const ptrsKey_B0[] = { &k_##K11, &k_##K01 }; \
c_Key* const ptrsKey_B1[] = { &k_##K12, &k_##K02 };
//                              pin B2    pin F1

// ************** LAYOUT ***************
TRANSFORM(
a,  b,  c,
1,  2,  3)

// *********** ROWS OF KEYS ************
//row objects
c_Row_Ex row_0(ptrsKey_C7, 2);
c_Row_Ex row_1(ptrsKey_B0, 2);
c_Row_Ex row_2(ptrsKey_B1, 2);

//static variables
c_Row_Ex* const ptrsRow[] = { &row_0, &row_1, &row_2 };
c_Row_Ex* const* const c_UCRowPort::ptrsRows = ptrsRow;

c_RowWait rowWait(3, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

/*************** ROW PORTS *************
 * row: 0   1   2       matrix "row" are vertical on this keyboard
 * pin: C7  B0  B1      diode anodes connect to these pins
 */
c_UCRowPort rowPort_C(DDRC, PORTC, 1<<7 );
c_UCRowPort rowPort_B(DDRB, PORTB, 1<<0 | 1<<1 );
c_UCRowPort* rowPorts[] = { &rowPort_C, &rowPort_B };
c_UCRowPorts rows(rowPorts, 2);

/*************** COL PORTS *************
 * col: 0   1           matrix "col" are horizontal on this keyboard
 * pin: B2  F1          diode cathodes connect to these pins
 */
c_UCColPort colPort_B(DDRB, PORTB, PINB, 1<<2 );
c_UCColPort colPort_F(DDRF, PORTF, PINF, 1<<1 );
c_UCColPort* colsPorts[] = { &colPort_B, &colPort_F };
c_UCColPorts cols(colsPorts, 2);

// ************** MATRIX ***************
//matrix
c_Matrix_AVR matrix(&rows, &cols);

//c_Row_Ex* const ptrsRow[] = { &row_0, &row_1 };
//c_Matrix_Teensy2 matrix(ptrsRow, 2);

// ************** KEYBOARD *************
c_Matrix* const ptrsMatrix[] = { &matrix };
c_Keybrd keybrd(ptrsMatrix, 1);

// **************** RUN ****************
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
