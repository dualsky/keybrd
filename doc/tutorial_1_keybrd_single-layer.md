keybrd Tutorial 1 - keybrd single-layer
=======================================

## keybrd sketch walkthrough for single-layer one-piece keyboard
We will step though a sketch for a simple keyboard.
Open the sketch [keybrd_single-layer_1221_bb.ino](../keybrd_sketches/keybrd_single-layer/keybrd_single-layer_1221_bb/keybrd_single-layer_1221_bb.ino) and follow along.

The keybrd sketch will run on either [breadboard keyboard](https://github.com/wolfv6/breadboard_keyboard).

Here is the keybrd's layout.

| Layout | **0** | **1** |  
|:------:|-------|-------|  
|  **0** | a     | b     |  
|  **1** | shift | shift |  

Row and column numbers are in the headers.
Each cell in the table's body is a key.

### Top comment
The top of the file briefly describes the keybrd.

### INCLUDES
The INCLUDES section pulls in files from libraries.
Arduino library files are used by the sketch indirectly.

Class names from the keybrd library have a prefixes c\_, k\_, l\_, or m\_
 and are used to instantiate objects in the sketch.

The included [objects_key.h](../libraries/keybrd/objects_key.h) file contains key objects.
For example, k_a is a key object for the 'a' character.

### ROWS
The ROWS section has two rows named row_0 and row_1.
Each row object is composed of an array of key pointers.
The c_Row_Ex constructor has two parameters:
1. an array of key pointers
2. the array's size

The rowWait object gives each row of switches time to debounce.
The c_RowWait constructor has two parameters:
1. total row count
2. switch bounce time in milliseconds

refRowWait is a static class variable.

### MATRICES
The MATRICES section has one Matrix named matrix.
The matrix object is composed of an array of row pointers.
The c_Matrix_Teensy2 constructor has two parameters:
1. an array of row pointers
2. the array's size

### KEYBOARD
The keybrd object is composed of an array of matrix pointers.
The c_Keybrd constructor as two parameters:
1. an array of matrix pointers
2. the array's size

### RUN
Function setup() initialized the keybrd.

Function loop() scans the keybrd.

## When Layout and Matrix are Incongruent
Most keyboards have keys laid out in straight rows and slightly slanted columns.

**[Keyboard layout](http://en.wikipedia.org/wiki/Keyboard_layout)** -
is the placements of keys on a keyboard.
**[Keyboard matrix](http://deskthority.net/wiki/Matrix)** -
is the electrical row and column connections to the keys.

In the preceding keyboard example, the matrix rows and columns follow the layout's rows and columns.
On some keyboards, the layout and matrix are incongruent.
For example, this keyboard has column wires that cross diagonally:

![2x2 breadboard keyboard with crossColumns](https://github.com/wolfv6/breadboard_keyboard/blob/master/images/breadboard_keyboard_2x2_crossColumns.jpg "2x2 breadboard keyboard with crossColumns")

In preparation of the keybrd sketch, we create separate tables for layout and matrix.

Here is the keyboard's **layout table**:

| row\col | **0** | **1** |  
|:-------:|-------|-------|
|  **0**  | a     | b     |  
|  **1**  | 1     | 2     |  

Row and column numbers are in the headers.
Each cell in the table's body is a key.

Here is the keyboard's **matrix table**:

|   Pin  | **B0** | **B1** |  
|:------:|--------|--------|  
| **F0** | a      | b      |  
| **F1** | 2      | 1      |  

The microcontroller's pin numbers are in the headers.
Each cell in the table's body contains a key
(the 1 and 2 keys are swapped compared to the layout table because the column wires are crossed).

Here is how to make a matrix table:
* Refer to the
  [matrix](https://github.com/wolfv6/breadboard_keyboard/blob/master/images/breadboard_keyboard_2x2_crossColumns.jpg),
  [pin out diagram](https://github.com/wolfv6/breadboard_keyboard/blob/master/connecting_teensy2_to_keyboard.md), and
  [c_Matrix_Teensy2.cpp](../libraries/keybrd/c_Matrix_Teensy2.cpp) > scanRow() > FPins[] array.
* Set up a spreadsheet headers like this
  [matrix table](../keybrd_sketches/keybrd_multi-layer/keybrd_multi-layer_1221_bbCrossedColumns/keybrd_single-layer_1221_bbCrossedColumns_tables.ods)
  with the pin names ordered in the sequence that they are scanned.
* For each switch in the matrix, write the key in that cell.

With the finished matrix table at hand, writing the sketch is simple.
Place keys in the arrays as they appear in the matrix table.

```cpp
// ********** ROWS *************
//row0
c_Key* const ptrsKey_0[] = {     &k_a,     &k_b   };
c_Row_Ex row_0(ptrsKey_0, 2);

//row1
c_Key* const ptrsKey_1[] = {     &k_2,     &k_1   };
c_Row_Ex row_1(ptrsKey_1, 2);
```
The ROWS section is always based on the matrix, it may or may not also be the layout.

The keybrd sketch for this example is at [keybrd_single-layer_1221_bbCrossedColumns](../keybrd_sketches/keybrd_single-layer/keybrd_single-layer_1221_bbCrossedColumns/keybrd_single-layer_1221_bbCrossedColumns).
