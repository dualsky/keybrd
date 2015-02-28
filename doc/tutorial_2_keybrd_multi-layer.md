keybrd Tutorial 2 - keybrd multi-layer
=======================================

## keybrd sketch walkthrough for multi-layer split keyboard
We will step though a sketch for a 2-matrix keyboard with 3 layers.
Open the sketch [keybrd_multi-layer_2223_bb.ino](../keybrd_sketches/keybrd_multi-layer/keybrd_multi-layer_2223_bb/keybrd_multi-layer_2223_bb.ino) and follow along.

The keybrd sketch will run on either [breadboard keyboard](https://github.com/wolfv6/breadboard_keyboard).

Here is the keybrd's layouts, one for each half of the split keyboard.

| Left  | **0** | **1** |  
|:-----:|-------|-------|  
| **0** | a ! 6 | b @ 7 |  
| **1** | alpha | sym   |  

| Right | **0** | **1** |  
|:-----:|-------|-------|  
| **0** | c # 8 | d $ 9 |  
| **1** | fn    | shift |  

Row and column numbers are in the headers.
Each cell in the table's body is a key.
Layered keys have the layer's characters delineated by spaces.

### Top comment
The top of the file briefly describes the keybrd.

### INCLUDES
The INCLUDES section pulls in files from libraries.
Arduino library files are used by the sketch indirectly.

The included [objects_scancodes.h](../libraries/keybrd/objects_scancodes.h) file contains scancode objects.
For example, s_a is a scancode object for the 'a' character and s_9 is a scancode object for the '9' character.

Class names from the keybrd library and keybrd_Layers library have a prefixes c\_, k\_, l\_, or m\_.
The keybrd library is used by all keybrd sketches.
The keybrd_Layers library defines the layer scheme for the sketch.

Each keybrd_Layers library implements a unique layer scheme.
If you want a custom layer scheme, you will have to write your own keybrd_Layers library.
Each keybrd_Layers library contains a l_LayerManager class and a l_Code_Layer class.
Here are two example keybrd_Layers libraries:
 * [keybrd_sketches/keybrd_multi-layer/keybrd_Layers]
(../keybrd_sketches/keybrd_multi-layer/keybrd_Layers)
 * [keybrd_sketches/keybrd_DodoHand/keybrd_Layers]
(../keybrd_sketches/keybrd_DodoHand/keybrd_Layers)

### LAYER CODES
The LAYER CODES section has 3 layers named l_alpha, l_sym, and l_fn.
Each layer is composed of a layer code, which is passed to the l_Code_Layer constructor.

The behavior of this particular layer scheme is described in
 [l_Code_Layer.h](../libraries/keybrd/l_Code_Layer.h).
Other keybrd_Layers libraries have different behavior.

### KEYS
l_Key_Layered objects are multi-layered keys.
Each l_Key_Layered object is composed of an array of scancode pointers, one scancode per layer.

l_Key_1 objects are single-layer keys.
Each l_Key_1 object is composed of one layer code or one scancode.

### ROWS
The ROWS section has 4 rows named row_L0, row_L1, row_R0, row_R1.
Each row is composed of an array of key pointers.
The c_Row_Ex constructor has two parameters:
1. an array of key pointers
2. the array's size

sizeof() is used to compute the size of arrays, which eliminates the risk of the programmer forgetting to update the key count after adding or removing a key.

### MATRICES
The MATRICES section has two Matrices named matrixL and matrixR.
Each matrix object is composed of an array of row pointers.
The c_Matrix_Teensy2 and c_Matrix_MCP23018 constructors have two parameters:
1. an array of row pointers
2. the array's size

The rowWait object gives each row of switches time to debounce.
The c_RowWait constructor has two parameters:
1. total row count
2. switch bounce time in milliseconds

refRowWait is a static class variable.

(The rowWait object is not in the ROW section because total row count is computed in the MATRICES section.)

### KEYBOARD
keybrd is composed of an array of matrix pointers.
The c_Keybrd constructor as two parameters:
1. an array of matrix pointers
2. the array's size

### MANAGERS
ShiftManager automatically changes and restores shift state for l_Code_SS scancode objects.
For example, when s_exclamation is pressed, shiftManager sends a MODIFIERKEY_SHIFT scancode to the computer, then s_exclamation sends a KEY_1 scancode, and then shiftManager releases the MODIFIERKEY_SHIFT.

The shiftManager object is composed of an array of l_Code_Shift pointers, one for each shift key.

The l_ShiftManager constructor has two parameters:
1. an array of key pointers
2. the array's size

shiftManager is a static class variable.


LayerManager keeps track of the active layer.
LayerManager is a static class variable.

### RUN
Function setup() initialized the keybrd.

Function loop() scans the keybrd.

## When Layout and Matrix are Incongruent
Most keyboards have keys laid out in straight rows and slightly slanted columns.

**[Keyboard layout](http://en.wikipedia.org/wiki/Keyboard_layout)** -
is the placements of keys on a keyboard.
**[Keyboard matrix](http://deskthority.net/wiki/Matrix)** -
is the electrical row and column connections to the keys.

In the preceding keyboard example, the matrix wires follow the layout's rows and columns.
On some keyboards, the layout and matrix are incongruent.
For example, this keyboard has column wires that cross diagonally:

![2x2 breadboard keyboard with crossColumns](https://github.com/wolfv6/breadboard_keyboard/blob/master/images/breadboard_keyboard_2x2_crossColumns.jpg "2x2 breadboard keyboard with crossColumns")

In preparation of the keybrd sketch, we create separate tables for layout and matrix.

Here is the keyboard's **layout table**:

| row\col | **0** | **1** |  
|:-------:|-------|-------|  
|  **0**  | a 1   | b 2   |  
|  **1**  | alpha | num   |  

Row and column numbers are in the headers.
Each cell in the table's body is a key.

Here is the keyboard's **layout coordinates table**:

| row\col | **0** | **1** |  
|:-------:|-------|-------|  
|  **0**  | 00    | 01    |  
|  **1**  | 10    | 11    |  

Each cell in the table's body contains the key's layout row-col coordinates.

Here is the keyboard's **matrix table**:

|   Pin  | **B0** | **B1** |  
|:------:|--------|--------|  
| **F0** | 00     | 01     |  
| **F1** | 11     | 10     |  

The microcontroller's pin numbers are in the headers.
Each cell in the table's body contains a layout coordinate of that key
(the bottom coordinates are swapped compared to the layout because the column wires are crossed).

Here is how to make a matrix table:
* Refer to the
  [matrix](https://github.com/wolfv6/breadboard_keyboard/blob/master/images/breadboard_keyboard_2x2_crossColumns.jpg),
  [pin out diagram](https://github.com/wolfv6/breadboard_keyboard/blob/master/connecting_teensy2_to_keyboard.md), and
  [c_Matrix_Teensy2.cpp](../libraries/keybrd/c_Matrix_Teensy2.cpp) > scanRow() > FPins[] array.
* Set up a spreadsheet headers like this
  [matrix table](../keybrd_sketches/keybrd_multi-layer/keybrd_multi-layer_1221_bbCrossedColumns/keybrd_multi-layer_1221_bbCrossedColumns_tables.ods)
  with the pin names ordered in the sequence that they are scanned.
* For each switch in the matrix, write the layout coordinates in that cell.

With the finished layout table and matrix table at hand, writing the sketch is simple.
Name keys after their layout coordinate.
```cpp
// ********** KEYS (layout) ***********
//row_0                   { alpha        num   };
l_Code * prtsCodes_00[] = { &s_a,        &s_1  };
l_Key_Layered k_00(prtsCodes_00);

l_Code * prtsCodes_01[] = { &s_b,        &s_2  };
l_Key_Layered k_01(prtsCodes_01);

//row_1
l_Key_1 k_10(&l_alpha);

l_Key_1 k_11(&l_num);
```

Place keys in the arrays as they appear in the matrix table.
```cpp
// ********** ROWS (layout-to-matrix mapping) **********
//row_0
c_Key* const ptrKey_0[] = { &k_00, &k_01 };
c_Row_Ex row_0(ptrKey_0, 2);

//row_1
c_Key* const ptrKey_1[] = { &k_11, &k_10 };
c_Row_Ex row_1(ptrKey_1, 2);
```
Notice that the KEYS section documents the layout.
The ROWS section documents the matrix.
Self documenting code is easier to debug and maintain.

Writing other layouts for the same keyboard hardware is easy.
Just rewrite the KEYS section, and the other code sections can be reused as is.

The keybrd sketch for this example is at
 [keybrd_multi-layer_1221_bbCrossedColumns.ino](../keybrd_sketches/keybrd_multi-layer/keybrd_multi-layer_1221_bbCrossedColumnskeybrd_multi-layer_1221_bbCrossedColumns.ino).

