/* keybrd_multi-layer_2223_bb.ino layout:
 *      a!9     b@8     c#7     d$6
 *      alpha   sym     fn      shift
 */
// ********** INCLUDES *********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <l_scancodes.h>
#include <l_scancodesNotShifted.h>
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
//instantiate Layer objects where parameter is index for l_Key_Layered::ptrsCode[] array
l_Code_Layer l_alpha(0);
l_Code_Layer l_sym(1);
l_Code_Layer l_fn(2);

// ********** KEYS ***********
//                        {alpha        sym             fn      };
l_Code * prtsCodes_00[] = {&s_a,        &s_exclamation, &sns_9  };
l_Key_Layered k_00(prtsCodes_00);

l_Code * prtsCodes_01[] = {&s_b,        &s_ampersand,   &sns_8  };
l_Key_Layered k_01(prtsCodes_01);

l_Code * prtsCodes_02[] = {&s_c,        &s_number,      &sns_7  };
l_Key_Layered k_02(prtsCodes_02);

l_Code * prtsCodes_03[] = {&s_d,        &s_dollar,      &sns_6  };
l_Key_Layered k_03(prtsCodes_03);

l_Key_1 k_alpha(&l_alpha);
l_Key_1 k_sym(&l_sym);
l_Key_1 k_fn(&l_fn);
l_Key_1 k_shift(&s_shift);

// ********** LEFT ROWS **********
//rowL0
c_Key* const ptrKeysL0[] = { &k_00, &k_01 };
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeysL0)/sizeof(ptrKeysL0[0]);
c_Row_Ex rowL0(ptrKeysL0, KEYS_L0_COUNT);

//rowL1
c_Key* const ptrKeysL1[] = { &k_alpha, &k_sym };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeysL1)/sizeof(ptrKeysL1[0]);
c_Row_Ex rowL1(ptrKeysL1, KEYS_L1_COUNT);

// ********** RIGHT ROWS **********
//rowR0
c_Key* const ptrKeysR0[] = { &k_02, &k_03 };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKeysR0)/sizeof(ptrKeysR0[0]);
c_Row_Ex rowR0(ptrKeysR0, KEYS_R0_COUNT);

//rowR1
c_Key* const ptrKeysR1[] = { &k_fn, &k_shift };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKeysR1)/sizeof(ptrKeysR1[0]);
c_Row_Ex rowR1(ptrKeysR1, KEYS_R1_COUNT);

// ********** MATRICES ***********
//matrixL
c_Row_Ex* const ptrsRowsL[] = { &rowL0, &rowL1 };
const uint8_t ROWS_L_COUNT = sizeof(ptrsRowsL)/sizeof(ptrsRowsL[0]);
c_Matrix_MCP23018 matrixL(ptrsRowsL, ROWS_L_COUNT);

//matrixR
c_Row_Ex* const ptrsRowsR[] = { &rowR0, &rowR1 };
const uint8_t ROWS_R_COUNT = sizeof(ptrsRowsR)/sizeof(ptrsRowsR[0]);
c_Matrix_Teensy2 matrixR(ptrsRowsR, ROWS_R_COUNT);

c_RowWait rowWait(ROWS_L_COUNT + ROWS_R_COUNT, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
c_Matrix* const ptrsMatrices[] = { &matrixL, &matrixR };
c_Keybrd keybrd(ptrsMatrices, 2);

// ********** MANAGERS ***********
l_Code_Shift* const ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager;
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
