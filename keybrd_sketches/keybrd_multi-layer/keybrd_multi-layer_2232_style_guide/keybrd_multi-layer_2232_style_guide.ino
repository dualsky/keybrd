/* keybrd_multi-layer_2232_style_guide.ino layout:
        a1      b       c!
        alpha   sym     shift

INTRODUCTION
Consistent style is essential for sharing layouts and getting help from the keybrd community.
Copying the [tutorial example todo](URL) is the easiest way to achive consistent style.
Refer to this guide to answer style questions in more detail.

This file describes conventions for multiple-layer and multiple-matrix keybrd sketches.
Most compact keyboards have multiple layers.
Most split keyboards have two matrices.
(keybrd_1221_single-layer_style_guide.ino shows conventions for single-layer single-matrix keybrd)

FORMAT CONVENTIONS
section headings are all caps and bracketed by stars: // ******* SECTION HEADING *********

OBJECT AND ARRAY NAMING CONVENTIONS
Names have two parts, a prefix followed by a body.
Prefix hints at class name while the body identifies the object.
Prefix and body are delineated an underscore (_).

THIS EXAMPLE
This example was tested on a breadboard keyboard.  It has:
        2 matrices
        2 rows
        3 columns
        2 layers
The layout is at the top of this file.
*/
// ********** INCLUDES *********
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <l_scancodes.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix_MCP23018.h>
#include <c_Keybrd.h>
#include <l_ShiftManager.h>

//keybrd_Layers library files
#include <l_LayerManager.h>
#include <l_Code_Layer.h>

// ********* LAYER CODES **********
/* Layer 0 is keybrd's default layer.
 Instances of layer code class have the following naming convention:

 CLASS          PREFIX          BODY
 l_Code_Layer   l               layer's name
*/
l_Code_Layer l_alpha(0);
l_Code_Layer l_sym(1);

// ********** LEFT KEYS ***********
/* Instances of key classes have the following naming conventions:

 CLASS          PREFIX          BODY
 l_Code* []     ptrsCodes       key's row-column layout position
 l_Key_Layered  k               "
 l_Key_1        k               "

 Keys are composed of scancode objects (scancode objects are defined in l_scancodes.h)
 In the example below, key k_00 is composed of s_a and s_1

 Keys are identified by their row-col layout position (not the matrix wiring)
 (default-layer char is not used because some are not usable in variable names e.g. punctuation)
 The column labels on the right are optional
*/
//rowL0                 layers: alpha           sym
l_Code* const ptrsCodes_00[] = {&s_a,           &s_1            };
l_Key_Layered k_00(ptrsCodes_00);               //col 0

l_Code* const ptrsCodes_01[] = {&s_b,           &s_null         };
l_Key_Layered k_01(ptrsCodes_01);               //col 1

//rowL1
l_Key_1 k_10(&l_alpha);                         //col 0

l_Key_1 k_11(&l_sym);                           //col 1

// ********** RIGHT KEYS ***********
//rowR0                 layers: alpha           sym
l_Code* const ptrsCodes_02[] = {&s_c,           &s_exclamation  };
l_Key_Layered k_02(ptrsCodes_02);               //col 2

//rowR1
l_Key_1 k_12(&s_shift);                         //col 2

// ********** LEFT ROWS **********
/* Instances of row classes have the following naming conventions:

 CLASS          PREFIX          BODY
 l_Key* []      ptrsKeys        matrix id (if more than one matrix) and row number
 c_Row_Ex       row             "

 Rows are composed of keys.
 The keys are arranged into arrays as they are wired to the matrix.
 In the example below, the left-row layout and wired matrix happen to have the same row-col numbers.
 Not so for the right rows.
*/
//rowL0         matrix col:         0               1
c_Key* const ptrKeys_L0[] = {   &k_00,          &k_01 };
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeys_L0)/sizeof(ptrKeys_L0[0]);
c_Row_Ex row_L0(ptrKeys_L0, KEYS_L0_COUNT);

//rowL1         matrix col:         0               1
c_Key* const ptrKeys_L1[] = {   &k_10,          &k_11 };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeys_L1)/sizeof(ptrKeys_L1[0]);
c_Row_Ex row_L1(ptrKeys_L1, KEYS_L1_COUNT);

// ********** RIGHT ROWS **********
/* The LEFT ROWS above demonstrate sizeof() to compute the size of arrays.
  The RIGHT ROWS below demonstrate passing literal array sizes to the constructor.
*/
//rowR0         matrix col:         0
c_Key* const ptrKeys_R0[] = {   &k_02   };
c_Row_Ex row_R0(ptrKeys_R0, 1);

//rowR1         matrix col:         0
c_Key* const ptrKeys_R1[] = {   &k_12   };
c_Row_Ex row_R1(ptrKeys_R1, 1);

// ********** MATRICES ***********
/* Instances of matrix classes have the following naming conventions:

 CLASS          PREFIX          BODY
 c_Row* []      prtsRows        matrix id (if more than one matrix)
 c_Matrix       matrix          "

 Matrices are composed of rows.
 The rows are arranged into arrays as they are wired to the matrix.
*/
//matrixL
c_Row_Ex* const ptrsRows_L[] = { &row_L0, &row_L1 };
c_Matrix_MCP23018 matrix_L(ptrsRows_L, 2);

//matrixR
c_Row_Ex* const ptrsRows_R[] = { &row_R0, &row_R1 };
c_Matrix_Teensy2 matrix_R(ptrsRows_R, 2);

c_RowWait rowWait(2 + 2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
/* Instance of keybrd class has the following naming conventions:

 CLASS                  OBJECTNAME
 c_Matrix* []           ptrsMatrices
 c_Keybrd               keybrd

 Keybrd is composed of one or more matrices.
 The matrices are arranged into arrays.
*/
c_Matrix* const ptrsMatrices[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrices, 2);

// ********** MANAGERS ***********
/* instance of l_ShiftManager and l_LayerManager classes have the following naming conventions:

 CLASS                  OBJECTNAME
 l_Code_Shift*[]        ptrsShifts
 l_ShiftManager         shiftManager
 l_LayerManager         layerManager
*/
l_Code_Shift* const ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager;
l_LayerManager& l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
