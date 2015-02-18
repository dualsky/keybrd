/* keybrd_multi-layer_2223_bbCrossedColumns.ino 4-key layout:
        a 1       b 2
        alpha     num
For doc/tutorial_2_keybrd_multi-layer.md ## When Layout and Matrix are Incongruent
The keyboard is pictured in breadboard_keyboard_2x2_crossColumns.JPG
The column-matrix wires cross.
*/
// ********** INCLUDES *********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_scancode.h>
#include <l_Key_Layered.h>
#include <l_Key_1.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_Code_Layer.h>
#include <l_LayerManager.h>

// ********* LAYER CODES **********
l_Code_Layer l_alpha(0);
l_Code_Layer l_num(1);

// ********** KEYS ***********
//row_0                   { alpha        num   };
l_Code * prtsCodes_00[] = { &s_a,        &s_1  };
l_Key_Layered k_00(prtsCodes_00);

l_Code * prtsCodes_01[] = { &s_b,        &s_2  };
l_Key_Layered k_01(prtsCodes_01);

//row_1
l_Key_1 k_10(&l_alpha);

l_Key_1 k_11(&l_num);

// ********** ROWS **********
//row_0
c_Key* const ptrKey_0[] = { &k_00, &k_01 };
c_Row_Ex row_0(ptrKey_0, 2);

//row_1
c_Key* const ptrKey_1[] = { &k_11, &k_10 };
c_Row_Ex row_1(ptrKey_1, 2);

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** MATRICES ***********
//matrix
c_Row_Ex* const ptrsRow[] = { &row_0, &row_1 };
c_Matrix_Teensy2 matrix(ptrsRow, 2);

// ********** KEYBOARD ***********
c_Matrix* const ptrsMatrix[] = { &matrix };
c_Keybrd keybrd(ptrsMatrix, 1);

// ********** MANAGERS ***********
l_Code_Shift* const ptrsShift[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShift, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager;
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
