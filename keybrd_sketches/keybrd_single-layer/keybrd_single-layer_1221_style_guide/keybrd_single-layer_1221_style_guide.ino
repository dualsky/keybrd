/* keybrd_single-layer_1221_style_guide.ino layout:
    a   1
    shift   shift

INTRODUCTION
Consistent style is essential for sharing layouts and getting help from the keybrd community.
Copying the [tutorial example todo](URL) is the easiest way to achive consistent style.
Refer to this guide to answer style questions in more detail.

This file describes conventions for single-layer and single-matrix keybrd sketches.
Most keyboards larger than 100 keys have a single layer.
Most one-peice keyboards (not split) have one matrix.
(keybrd_2232_multi-layer_style_guide.ino shows naming convention for multiple matrices)

FORMAT CONVENTIONS
section headings are all caps and bracketed by stars: // ******* SECTION HEADING *********

OBJECT AND ARRAY NAMING CONVENTIONS
Names have two parts, a prefix followed by a body.
Prefix hints at class name while the body identifies the object.
Prefix and body are delineated an "_".
Prefix and body are delineated an underscore (_).

THIS EXAMPLE
This example was tested on a breadboard keyboard.  It has:
    1 matrix
    2 rows
    2 columns
The layout is at the top of this file.
*/
// ********** INCLUDES *********
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

#include <l_LayerManager.h> //Ariduino IDE needs this even though it's not used by this sketch
//because Arduino links everything in library, even unused files.

// ********** ROWS **********
/* Instances of row classes have the following naming conventions:

 CLASS      PREFIX      BODY
 c_Key* []  ptrsKeys    row number
 c_Row_Ex   row     "

 Rows are composed of keys.
 The keys are arranged into arrays as they are wired to the matrix.
 In this example, the layout and wired matrix happen to have the same row-col numbers.

 row0 demonstrates sizeof() to compute the size of it's array.
 row1 demonstrates passing a literal array size to the constructor.
*/
//row0      matrix col:     0           1
c_Key* const ptrKeys0[] = { &k_a,       &k_1    };
const uint8_t KEYS0_COUNT = sizeof(ptrKeys0)/sizeof(ptrKeys0[0]);
c_Row_Ex row_0(ptrKeys0, KEYS0_COUNT);

//row1      matrix col:     0           1
c_Key* const ptrKeys1[] = { &k_shift_L, &k_shift_R  };
c_Row_Ex row_1(ptrKeys1, 2);

// ********** MATRICES ***********
/* Instances of matrix classes have the following naming conventions:

 CLASS      PREFIX      BODY
 c_Row* []  prtsRows
 c_Matrix   matrix

 Matrices are composed of rows.
 The rows are arranged into arrays as they are wired to the matrix.
*/
//matrix
c_Row_Ex* const ptrsRows[] = { &row_0, &row_1 };
c_Matrix_Teensy2 matrix(ptrsRows, 2);

c_RowWait rowWait(2, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
/* Instance of keybrd class has the following naming conventions:

 CLASS          OBJECTNAME
 c_Matrix* []       ptrsMatrices
 c_Keybrd       keybrd

 keybrd is composed of one or more matrices.
 The matrices are arranged into arrays.
*/
c_Matrix* const ptrsMatrices[] = { &matrix };
c_Keybrd keybrd(ptrsMatrices, 1);

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
