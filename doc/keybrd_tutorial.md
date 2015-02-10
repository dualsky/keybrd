
Multi-layer keyboard Nomenclature
---------------------------------
**[USB scancode](http://en.wikipedia.org/wiki/Scancode)** -
is an integer assigned to a key position on keyboard.
The keyboard sends a scancode to the PC for every key press and release.

**[Layer](http://deskthority.net/wiki/Layer)** -
are key bindings provided by the keyboard firmware.
Many compact keyboards have a [Fn layer](http://en.wikipedia.org/wiki/Fn_key).
The [Neo layout](http://neo-layout.org/index_en.html) has 6 layers.

**Layer code** - is an integer assigned to a layer.

**Layer scheme** - is a system for changing layers while typing.

Structure of a keybrd Sketch
------------------------------
The keybrd object has a hierarchal structure (listed below).
Each level of the keybrd hierarchy is composed of interchangeable objects.
These objects are instantiated by classes (the links below are to the class header files).
todo: link the file names, and link level name to parent class

1. keybrd is composed of 1 or 2 matrices
 * [c_Keybrd.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/c_Keybrd.h)
2. Matrix is composed of rows and scans the pins of a micro processor or I/O expander
 * [c_Matrix_Teensy2.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/c_Matrix_Teensy2.h)
 * [c_Matrix_MCP23018.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/c_Matrix_MCP23018.h)
3. Row is composed of keys
 * [c_Row_Ex.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/c_Row_Ex.h)
4. Single-layer keys are composed of USB scancodes
 * [k_Key_1.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/k_Key_1.h)
 * [k_Key_Null.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/k_Key_Null.h)
 * [k_keycodes.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/k_keycodes.h)
5. Multi-layered keys are composed of codes, one code per layer
 * [l_Key_1.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Key_1.h)
 * [l_Key_Layered.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Key_Layered.h)
6. Codes can be USB scancodes or layer codes
 * [l_Code_S.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Code_S.h)
 * [l_Code_SS.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Code_SS.h)
 * [l_Code_SNS.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Code_SNS.h)
 * [l_Code_Shift.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Code_Shift.h)
 * [l_Code_Null.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_Code_Null.h)
 * [l_scancodes.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_scancodes.h)
 * [l_scancodesNotShifted.h](https://github.com/wolfv6/keybrd/blob/master/libraries/keybrd/l_scancodesNotShifted.h)
   Each layer scheme has it's own keybrd_Layers library folder.
   Multiple-layer keybrds have layer codes and a layer manager, for example:
 * [l_Code_Layer.h](https://github.com/wolfv6/keybrd/blob/master/keybrd_sketches/keybrd_multi-layer/keybrd_Layers/l_Code_Layer.h)
 * [l_LayerManager.h](https://github.com/wolfv6/keybrd/blob/master/keybrd_sketches/keybrd_multi-layer/keybrd_Layers/l_LayerManager.h)

