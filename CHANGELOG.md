# Change Log
All notable changes to the keybrd project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

Version 0.x.x is for initial development. The public API should not be considered stable.
Version 1.0.0 will be released when the public API is stable.

## [Unreleased][unreleased]

## [0.3.0] - 2015-05-08
### Added
* Teensy2.0 and PCA9655E I/O expander can scan ports as active low or active high.
* port classes make it easy for user to specify IC ports and pins:
	c_RowPort
	c_RowPort_AVR
	c_RowPort_AVR_ActiveHigh
	c_RowPort_MCP23018
	c_RowPort_PCA9655E

	c_ColPort
	c_ColPort_AVR
	c_ColPort_AVR_ActiveHigh
	c_ColPort_MCP23018
	c_ColPort_PCA9655E
	c_ColPort_PCA9655E_ActiveHigh

	c_IOExpanderPort
* LED classes to turn LEDs on/off:
	c_LED
	c_LED_AVR
	c_LED_MCP23018
	c_LED_PCA9655E

### Changed
* Renamed 4 classes (which changed public API):

| Old Name                | New Name               |
|-------------------------|------------------------|
| c_Row_Ex                | c_Row                  |
| l_Code_00               | l_Code_SNS_00          |
| m_MouseButton           | m_Mouse_Button         |
| m_MouseMove             | m_Mouse_Move           |

## [0.2.0] - 2015-02-18
### Added
* tutorial_1_keybrd_single-layer.md
* tutorial_2_keybrd_multi-layer.md

### Changed
* Improved all supporting documentation.
* Renamed 4 files (which changed public API):

| Old Name                | New Name                     | Example Objects |  
|-------------------------|------------------------------|-----------------|  
| k_keycodes.h            | objects_key.h                | k_a k_1         |  
| l_scancodes.h           | objects_scancode.h           | s_a s_1         |  
| l_scancodesNotShifted.h | objects_scancodeNotShifted.h | sns_1           |  
| m_mousecodes.h          | objects_mouse.h              | mm_up mb_left   |  

## [0.1.0] - 2015-02-10
### Added
* The library runs on Teensy 2.0 microcontroller and MCP23018 I/O expander.
* Limited to 8x8 matrix, which is enough for compact or split keyboards.
* First draft of supporting documentation.
* Example keybrd sketches for single-layer, multi-layer, and DataHand layer schemes.

