/* keybrd_single-layer_1221_bb.ino, 4-key layout:
        a       1
        shift   shift
*/
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <k_keycodes.h>
#include <k_Key_1.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix_MCP23018.h>
#include <c_Keybrd.h>
#include <l_LayerManager.h>

// ********** ROWS **********
//row0
c_Key* const ptrKeys0[] = {     &k_a,           &k_1         };
c_Row_Ex row_0(ptrKeys0, 2);

//row1
c_Key* const ptrKeys1[] = {     &k_shift_L,     &k_shift_R   };
c_Row_Ex row_1(ptrKeys1, 2);

// ********** MATRICES ***********
//matrix
c_Row_Ex* const ptrsRows[] = { &row_0, &row_1 };
c_Matrix_Teensy2 matrix(ptrsRows, 2);

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
c_Matrix* const ptrsMatrices[] = { &matrix };
c_Keybrd keybrd(ptrsMatrices, 1);

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
