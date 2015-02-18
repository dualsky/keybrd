keybrd Library User's Guide
===========================
This guide shows you how to set up Arduiono IDE and keybrd library.
We also cover how to compile and load keybrd firmware onto the keyboard's processor.

## Who This Guide is for
This guide is for users that want to develop custom keyboard firmware using the keybrd library.
It is assumed the reader is familiar with C/C++ language including pointers, static class variables, and composition.

## Getting Started with Teensy2.0, Arduino IDE, and keybrd
A **keybrd sketch** is an C++ file that uses the keybrd library to define keyboard firmware.
The Arduiono IDE is free, easy to setup, and simple to use.
The Arduino IDE compiles the keybrd sketch to make an executable keyboard firmware.
The firmware is then loaded onto the keyboard's Teensy2.0 microcontroller.
The result is a keyboard that is compatible with standard USB keyboard drivers.

Teensy2.0 is a USB-based microcontroller development system.  It runs the keyboard.
A good way to get familiar with Teesny2.0 is [Teensy Getting Started](http://www.pjrc.com/teensy/first_use.html).

Teensyduino is a software add-on for the Arduino IDE that allows it to compile to Teensy2.0
Follow the [install steps](https://www.pjrc.com/teensy/td_download.html)
(you may need to run the Teensyduino installer as Administrator).

A program written for Arduino is called a sketch.
The Arduino IDE is used to compile keybrd sketches.
Here is a brief description of the [Arduino Development Environment](http://arduino.cc/en/guide/Environment).

### Setup Arduino IDE for Compiling keybrd Firmware
From the Arduino IDE tool bar, select: 
* Tools > Board > Teensy2.0
* Tools > USB Type > Keyboard + Mouse + Joystick

### Download and Unpack keybrd-master.zip into Your Arduino Folder
Down load keybrd-master.zip from the [Download ZIP](https://github.com/wolfv6/keybrd) button.
Unpack keybrd-master.zip into your Arduino folder on your system (default location on Windows is Documents\Arduino\).

### Move the keybrd_Layers Folder
keybrd sketches are grouped into folders by layer scheme.
Each layer scheme has a keybrd_Layers folder that the keybrd sketches depend on.
keybrd_Layers folders are in the keybrd_sketches subfolders:
* Arduino\keybrd_sketches\keybrd_DodoHand\keybrd_Layers
* Arduino\keybrd_sketches\keybrd_multi-layer\keybrd_Layers
* Arduino\keybrd_sketches\keybrd_single-layer\keybrd_Layers

For whichever keybrd sketch you want to compile, move the corresponding keybrd_Layers folder into Arduino\libraries\.

If you decide to change layer schemes, remember to follow these steps:
1. If there is keybrd_Layers folder in Arduino\libraries\, move it back to it's original location
   (each keybrd_Layers folder contains a README file that identifies the origin of the folder).
2. Move keybrd_Layers folder from Arduino\keybrd_sketches\keybrd_layer-scheme\ to Arduino\libraries\.
If a keybrd sketch was compiled with a missing or wrong keybrd_Layers folder, also:
3. Delete AppData\Local\Temp\build123456789012345678.tmp (the folder number will be unique).
4. Close and reopen the Arduino IDE.

These steps are a work-a-round for the Arduino IDE.

#### Move the keybrd_Layers Folder Work-a-round for Arduino IDE Explained
The Arduino IDE can not handle more than one layer scheme.
People using just one layer scheme are not affected.
However, it is annoying for developing many keyboards with different layer schemes.
The work-a-round is to move the keybrd_Layers folder into the Arduino/libraries/.
The reason for moving keybrd_Layers folder is explained in [Arudino issue 2547](https://github.com/arduino/Arduino/issues/2547).

Arduino IDE caches object files when compiling a sketch.
This saves on compile time, but links break if files of same name are swapped into the library.
If the build..tmp folder is not deleted after moving the keybrd_Layers folder, one of three things happens when the Arduino IDE compiles:
* everything runs normal
* nonsense link errors
* keyboard runs fine for a while and then spews charters or other unexpected behavior

### Compile and Load
If it isn't already plugged in, plug the USB cable into the computer and Teensy2 processor.

> CAUTION: It is possible to loose control of your keyboard to bad firmware.
> If the keybrd has a mouse object, it is also possible to loose control of your mouse.
> The processor is capable of sending characters and mouse commands at USB connection speeds.
> Take the following precautions before uploading an untested keyboard program to Teensy:
> * Save all files and park the cursor in an empty editor.
> That way you can immediately see if the processor starts spewing characters.
> * Be prepared to turn off Teensy (by pushing the Teensy button or unplugging it from USB).

Compile and load:
* Open a keybrd sketch in the Arduino IDE (for example Arduino\keybrds\firmware\keybrd_single-layer\keybrd_single-layer_1221_bb\keybrd_single-layer_1221_bb.ino)
* Click the Upload button.
* The Teensy boot loader window opens, press and release the tiny pushbutton on the Teensy circuit board.

## Sample keybrd Sketches
Sample keybrd sketches are in the keybrd_sketches folder, grouped by layer scheme.
The sketches use the following naming conventions.

    keybrd_layerScheme_1234_feature_layout_version.ino

where
* **keybrd** is a literal string
* **layerScheme** is layer scheme name e.g. single-layer, multi-layer, DualMode, DodoHand
* **1** is matrixCount
* **2** is max rowCount (use letters ABCDEFG for rowCount 10 to 16)
* **3** is max colCount (use letters ABCDEFG for colCount 10 to 16)
* **4** is layerCount
* **feature** is distinguishing feature of keybrd e.g. bb (breadboard), LEDs, sound, lock
* **layout** is keyboard layout e.g. QWERTY
* **version** is version number

**keybrd** and **layerScheme** are mandatory, remaining parts are optional.
