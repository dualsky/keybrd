keybrd Library for Creating Keyboard Firmware
=============================================
keybrd library is an open source library for creating custom-keyboard firmware.
The keyboards can have any layout:
* split keyboard with Teensy 2.0 on one half and an I/O Expander on the other half
* one-piece multiple-layer compact keyboard on Teensy 2.0 processor
* (one-piece single-layer full-size keyboard is planned for a later version of keybrd)

A **keybrd sketch** is an Arduiono C++ file that uses the keybrd library to define a keybrd object.
Anyone familiar with Object Oriented programming can write a keybrd sketch.

The Arduiono IDE is free, easy to setup, and simple to use.
The Arduino IDE compiles the keybrd sketch to make an executable keyboard firmware.
The resulting keyboard firmware is compatible with standard USB keyboard drivers.

Example Minimal keybrd Sketch
-----------------------------
Here is a [minimal keybrd sketch](https://github.com/wolfv6/keybrd/blob/master/keybrd_sketches/keybrd_single-layer/keybrd_single-layer_1221_bb/keybrd_single-layer_1221_bb.ino).
The sketch is 42 lines long and runs a 4-key keyboard.
The keyboard has rows, columns, and diodes just like the big keyboards.
The sketch is small because the keybrd library takes care of the low-level bits.

Example Complex keybrd Sketch
-----------------------------
The DodoHand keybrd has 50 keys, 5 layers, 2 matrices, and a relatively complex layer scheme.
It's [keybrd sketch](https://github.com/wolfv6/keybrd/blob/master/keybrd_sketches/keybrd_DodoHand/keybrd_DH_2565_0/keybrd_DH_2565_0.ino) contains about 400 lines.
The the layer scheme resides in a [keyrd_Layers folder](https://github.com/wolfv6/keybrd/tree/master/keybrd_sketches/keybrd_DodoHand/keybrd_Layers) and contains about 300 lines.

Got a Question or Need Help?
----------------------------
The doc folder contains guides and a tutorial.
Please [ask a questions](todo: geekhack thread URL) if something is not clear.

Found an Issue?
---------------
If you find a bug in the source code or a mistake in the documentation, you can help us by [submitting an issue](https://github.com/wolfv6/Keybrd/issues) to our GitHub Repository.

Want to Contribute Code?
------------------------
Please see [CONTRIBUTING](https://github.com/wolfv6/keybrd/blob/master/CONTRIBUTING.md).

