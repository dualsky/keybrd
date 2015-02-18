/* keybrd_multi-layer_2223_bb.ino layout:
 *        Left Matrix             Rigth Matrix
 *      -----------------       -----------------
 *      a ! 6       b @ 7       c # 8       d $ 9
 *      alpha       sym         fn          shift
 */
// ********** INCLUDES *********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_scancode.h>
#include <l_ShiftManager.h>
#include <l_Key_Layered.h>
#include <l_Key_1.h>
#include <c_Row_Ex.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix_MCP23018.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_Code_Layer.h>
#include <l_LayerManager.h>

// ********* LAYER CODES **********
l_Code_Layer l_alpha(0);
l_Code_Layer l_sym(1);
l_Code_Layer l_fn(2);

// ********** LEFT KEYS ***********
//row_L0                   {alpha        sym             fn    };
l_Code * prtsCodes_L00[] = {&s_a,        &s_exclamation, &s_6  };
l_Key_Layered k_L00(prtsCodes_L00);

l_Code * prtsCodes_L01[] = {&s_b,        &s_at,          &s_7  };
l_Key_Layered k_L01(prtsCodes_L01);

//row_L1
l_Key_1 k_L10(&l_alpha);

l_Key_1 k_L11(&l_sym);

// ********** RIGHT KEYS ***********
//row_R0                   {alpha        sym             fn    };
l_Code * prtsCodes_R00[] = {&s_c,        &s_number,      &s_8  };
l_Key_Layered k_R00(prtsCodes_R00);

l_Code * prtsCodes_R01[] = {&s_d,        &s_dollar,      &s_9  };
l_Key_Layered k_R01(prtsCodes_R01);

//row_R1
l_Key_1 k_R10(&s_shift);
l_Key_1 k_R11(&l_fn);

// ********** LEFT ROWS **********
//row_L0
c_Key* const ptrKey_L0[] = { &k_L00, &k_L01 };
const uint8_t KEYS_L0_COUNT = sizeof(ptrKey_L0)/sizeof(ptrKey_L0[0]);
c_Row_Ex rowL0(ptrKey_L0, KEYS_L0_COUNT);

//row_L1
c_Key* const ptrKey_L1[] = { &k_L10, &k_L11 };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKey_L1)/sizeof(ptrKey_L1[0]);
c_Row_Ex rowL1(ptrKey_L1, KEYS_L1_COUNT);

// ********** RIGHT ROWS **********
//row_R0
c_Key* const ptrKey_R0[] = { &k_R00, &k_R01 };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKey_R0)/sizeof(ptrKey_R0[0]);
c_Row_Ex rowR0(ptrKey_R0, KEYS_R0_COUNT);

//row_R1
c_Key* const ptrKey_R1[] = { &k_R11, &k_R10 };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKey_R1)/sizeof(ptrKey_R1[0]);
c_Row_Ex rowR1(ptrKey_R1, KEYS_R1_COUNT);

// ********** MATRICES ***********
//matrix_L
c_Row_Ex* const ptrsRow_L[] = { &rowL0, &rowL1 };
const uint8_t ROWS_L_COUNT = sizeof(ptrsRow_L)/sizeof(ptrsRow_L[0]);
c_Matrix_MCP23018 matrix_L(ptrsRow_L, ROWS_L_COUNT);

//matrix_R
c_Row_Ex* const ptrsRow_R[] = { &rowR0, &rowR1 };
const uint8_t ROWS_R_COUNT = sizeof(ptrsRow_R)/sizeof(ptrsRow_R[0]);
c_Matrix_Teensy2 matrix_R(ptrsRow_R, ROWS_R_COUNT);

c_RowWait rowWait(ROWS_L_COUNT + ROWS_R_COUNT, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

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
