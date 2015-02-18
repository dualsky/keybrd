# Change Log
All notable changes to this project will be documented in this file.
This project adheres to [Semantic Versioning](http://semver.org/).

Version 0.x.x is for initial development. The public API should not be considered stable.
Version 1.0.0 will be released when the public API is stable.

## [Unreleased][unreleased]

## [0.2.0] - 2015-02-18
### Added
- tutorial_1_keybrd_single-layer.md
- tutorial_2_keybrd_multi-layer.md

### Changed
- Improved all supporting documentation.
- Renamed 4 files (which changed public API):
        OLD NAME                NEW NAME                        EXAMPLE OBJECTS
        k_keycodes.h            objects_key.h                   k_a k_1
        l_scancodes.h           objects_scancode.h              s_a s_1
        l_scancodesNotShifted.h objects_scancodeNotShifted.h    sns_1
        m_mousecodes.h          objects_mouse.h                 mm_up mb_left

## [0.1.0] - 2015-02-10
### Added
- The library runs on Teensy 2.0 microcontroller and MCP23018 I/O expander.
- Limited to 8x8 matrix, which is enough for compact or split keyboards.
- First draft of supporting documentation.
- Example keybrd sketches for single-layer, multi-layer, and DataHand layer schemes.

