keybrd Tutorial 0 - keybrd single-layer
=======================================
todo: update this file

keybrd tutorial 0 lays the foundation for tutorials 1 and 2.
After reading these tutorials you will be able to understand a keybrd sketch and be able to modify it to suite your own keyboard design.

It is assumed the reader is familiar with C/C++ language including pointers, static class variables, and composition.

## Keyboard Nomenclature
**[scancode](http://en.wikipedia.org/wiki/Scancode)** -
Is an integer assigned to a key position on keyboard.
The keyboard sends a scancode to the PC for every key press and release.

**[Layer](http://deskthority.net/wiki/Layer)** -
Are key bindings provided by the keyboard firmware.
The standard [IBM PC keyboard](http://en.wikipedia.org/wiki/IBM_PC_keyboard) has one layer.
Many compact keyboards have an additional [Fn layer](http://en.wikipedia.org/wiki/Fn_key).
The [Neo layout](http://neo-layout.org/index_en.html) has 6 layers.

**Layer code** - is an integer assigned to a layer.

**Layer scheme** - is a system for changing layers while typing.

**[Key Matrix](http://pcbheaven.com/wikipages/How_Key_Matrices_Works/)** - is a grid of rows and columns connected by switches

**[bounce](http://en.wikipedia.org/wiki/Switch#Contact_bounce)** -
Keyboard switches are made of moving contacts.
When the contacts close, they bounce apart one or more times before making steady contact.
A debouncer removes the bounce so that a key press is sent to the computer only once.

## Structure of a keybrd Sketch
A **keybrd sketch** is a source code file that defines a keybrd object.
When the keybrd sketch is compiled and run, the keybrd object scans the keyboard matrix.
If a key is pressed, the keybrd object sends a scancod to the computer.

two main parts:
	1 hardware specifications (keybrd, matrix, rowPort, colPort, LEDPort, row, key)
	2 matrix layout (transform, scancode)

The keybrd object has the hierarchal composition listed below.
Each level has a numbered description followed by bulleted classes.

1. keybrd is composed of 1 or 2 matrices
 * [c_Keybrd.h](../libraries/keybrd/c_Keybrd.h)
2. Matrix is composed of rows and scans the pins of a micro processor or I/O expander
 * [c_Matrix_Teensy2.h](../libraries/keybrd/c_Matrix_Teensy2.h)
 * [c_Matrix_MCP23018.h](../libraries/keybrd/c_Matrix_MCP23018.h)
3. Row is composed of keys
 * [c_Row_Ex.h](../libraries/keybrd/c_Row_Ex.h)
4. Single-layer keys are composed of USB scancodes
 * [k_Key_1.h](../libraries/keybrd/k_Key_1.h)
 * [k_Key_Null.h](../libraries/keybrd/k_Key_Null.h)
 * [k_keycodes.h](../libraries/keybrd/k_keycodes.h)
5. Multi-layered keys are composed of codes, one code per layer
 * [l_Key_1.h](../libraries/keybrd/l_Key_1.h)
 * [l_Key_Layered.h](../libraries/keybrd/l_Key_Layered.h)
6. Codes can be USB scancodes or layer codes
 * [l_Code_S.h](../libraries/keybrd/l_Code_S.h)
 * [l_Code_SS.h](../libraries/keybrd/l_Code_SS.h)
 * [l_Code_SNS.h](../libraries/keybrd/l_Code_SNS.h)
 * [l_Code_Shift.h](../libraries/keybrd/l_Code_Shift.h)
 * [l_Code_Null.h](../libraries/keybrd/l_Code_Null.h)
 * [l_scancodes.h](../libraries/keybrd/l_scancodes.h)
 * [l_scancodesNotShifted.h](../libraries/keybrd/l_scancodesNotShifted.h)

## LEDs
Class c_LED uses a I/O expander pin to turn a LED on and off.
c_RowPort or c_ColPort (whichever is used by LED) must be instantiated before c_LED is instantiated.
This is because I/O expander direction register is configured in the c_RowPort and c_ColPort constructors.

the order of instantiations is very important
the compiler will not give a warning, the keybrd just won't work
the safest way to write a keybrd sketch is to instantiate objects in the same order as the example keybrd sketches
