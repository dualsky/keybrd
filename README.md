keybrd Library for Creating Keyboard Firmware
=============================================
> The public API should not be considered stable.
> Currently the keybrd library is limited to 8x8 matrices, which is enough for compact or split keyboards.
> 16x16 matrix capability is under development for one-piece full-size keyboards.

keybrd library is an open source library for creating custom-keyboard firmware.
keybrd library can handle keyboards with any configuration:
	one-piece
	split with I/O expander
	single-layer
	multiple-layer
keybrd library leverages the Arduino environment to create keyboard firmware that is compatible with standard USB keyboard drivers.

The library runs on Teensy 2.0 microcontroller and MCP23018 I/O expander.
A PCA9655E I/O expander will be added soon.

A **keybrd sketch** is an C++ file that uses the keybrd library to define keyboard firmware.
Anyone familiar with C++ programming can write a keybrd sketch.

Example Minimal keybrd Sketch
-----------------------------
Here is a [minimal keybrd sketch](keybrd_sketches/keybrd_single-layer/keybrd_single-layer_1221_bb/keybrd_single-layer_1221_bb.ino).
The sketch is 42 lines long and runs a 4-key keyboard.
The keyboard has rows, columns, and diodes just like the big keyboards.
The sketch is small because the keybrd library takes care of the low-level bits.

Example Complex keybrd Sketch
-----------------------------
The DodoHand keybrd has 50 keys, 5 layers, 2 matrices, and a relatively complex layer scheme.
It's [keybrd sketch](keybrd_sketches/keybrd_DodoHand/keybrd_DH_2565_0/keybrd_DH_2565_0.ino) contains about 400 lines.
The the layer scheme resides in a [keyrd_Layers folder](keybrd_sketches/keybrd_DodoHand/keybrd_Layers) and contains about 300 lines.

Got a question or need help?
----------------------------
The [doc](doc) folder contains guides and tutorials.
Please [ask a questions](todo: geekhack thread URL) if something is not clear.

Found an issue?
---------------
If you find a bug in the source code or a mistake in the documentation, you can help us by [submitting an issue](https://github.com/wolfv6/Keybrd/issues) to our GitHub Repository.

Want to contribute code?
------------------------
Please see [CONTRIBUTING](CONTRIBUTING.md).

