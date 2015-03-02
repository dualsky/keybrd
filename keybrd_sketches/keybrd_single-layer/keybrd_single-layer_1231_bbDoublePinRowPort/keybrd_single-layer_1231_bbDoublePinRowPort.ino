/* keybrd_single-layer_1231_bb.ino, 6-key layout:
        1       2       3
        a       b       c
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

// ************ TRANSFORMS *************
//this macro function transforms layout to matrix rows
#define TRANSFORM( \
        K00, K01, K02, \
        K10, K11, K12  \
) \
c_Key* const ptrsKey_0[] = { &k_##K00, &k_##K01, &k_##K02 }; \
c_Key* const ptrsKey_1[] = { &k_##K10, &k_##K11, &k_##K12 };

// ************** LAYOUT ***************
TRANSFORM(
1,  2,  3,
a,  b,  c)

// *********** ROWS OF KEYS ************
//row objects
c_Row_Ex row_0(ptrsKey_0, 3);
c_Row_Ex row_1(ptrsKey_1, 3);

//static variables
c_Row_Ex* const ptrsRow[] = { &row_0, &row_1 };
c_Row_Ex* const* const c_UCRowPort::ptrsRows = ptrsRow;

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

/*************** ROW PORTS *************
 * row: 0   1
 * pin: F0  F1
 */
c_UCRowPort rowPort_F(PORTF, DDRF, 1<<0 | 1<<1 );//bot row keys print bot+top key, same for top row, but last col print in revers
c_UCRowPort* rowsPorts[] = { &rowPort_F };
c_UCRowPorts rows(rowsPorts, 1);

/*************** COL PORTS *************
 * col: 0   1   2
 * pin: B0  B1  C7
 */
c_UCColPort colPort_C(PORTC, DDRC, PINC, 1<<7 );
c_UCColPort colPort_B(PORTB, DDRB, PINB, 1<<0 | 1<<1 );
c_UCColPort* colPorts[] = { &colPort_C, &colPort_B };
c_UCColPorts cols(colPorts, 2);

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
