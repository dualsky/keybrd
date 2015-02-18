/* keybrd_single-layer_1221_bbCrossedColumns.ino 4-key layout:
        a       b
        1       2
For doc/tutorial_2_keybrd_single-layer.md ## When Layout and Matrix are Incongruent
The keyboard is pictured in breadboard_keyboard_2x2_crossColumns.JPG
The column-matrix wires cross.
*/
// ********** INCLUDES **********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_key.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Keybrd.h>
#include <l_LayerManager.h>

// ********** ROWS *************
//row0
c_Key* const ptrsKey_0[] = { &k_a,    &k_b };
c_Row_Ex row_0(ptrsKey_0, 2);

//row1
c_Key* const ptrsKey_1[] = { &k_2,    &k_1 };
c_Row_Ex row_1(ptrsKey_1, 2);

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** MATRIX ***********
//matrix
c_Row_Ex* const ptrsRow[] = { &row_0, &row_1 };
c_Matrix_Teensy2 matrix(ptrsRow, 2);

// ********* KEYBOARD **********
c_Matrix* const ptrsMatrix[] = { &matrix };
c_Keybrd keybrd(ptrsMatrix, 1);

// *********** RUN *************
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
