keybrd Library Developer's Guide
================================
This guide contains naming conventions, diagrams, and a style guide.
Class naming conventions and class diagrams are helpful for understanding the structure of the keybrd library.

Some keyboard designs require new classes.  The most common need for custom classes are:
 * matrices for keyboard micro processors and I/O expanders
 * layer schemes for multi-layer keyboards
This guide will help you design your new class to fit into the keybrd library.

## Who This Guide is For
This guide is for the maintainers and developers of the keybrd library.
It is assumed the reader is familiar with C/C++ language including pointers, static class variables, and object-oriented programming concepts.

## Class Naming Conventions
Class-name prefixes are used in lieu of directory structure (Arduino does not support subdirectories)
The Class-name prefixes make more sense if you look at the class inheritance diagrams in the next section.

Each class in keybrd library has one of 4 prefixes:
* **c_** classes common to all keybrds
* **k_** classes for keybrds with a single layer of keys
* **l_** classes for keybrds with multiple layers
* **m_** classes for mouse

The prefix is followed by a class name proper, which is CamelCase starting with a capital.

Names of inherited classes start with the base class name followed by "_" and subclass name e.g.
	l_Code
	   |
	l_Code_Layer
Underscores delineate class inheritance levels.
This convention leads to class names that convey information about the classes inheritance.
For classes with multiple inheritance, name class as if it where a base class.

## Diagrams
### Keybrd Library Common Classes
Classes inheritance diagrams:
```
	c_keybrd

	c_Matrix

	c_Row
 
	c_Key                                           c_Key is an abstract base class

	          ____ c_LED ______
	         /       |         \
	c_LED_AVR  c_LED_MCP23018  c_LED_PCA9655E

	              ______ c_PortRows ______
	             /           |            \
	c_PortRows_AVR  c_PortRows_MCP23018  c_PortRows_PCA9655E   one PortRows class for each type of IC
 
	              ______ c_PortCols ______
	             /           |            \
	c_PortCols_AVR  c_PortCols_MCP23018  c_PortCols_PCA9655E   one PortCols class for each type of IC
 
	c_IOExpanderPort

```
### Keybrd Library Matrix Classes
Classes inheritance diagrams:
``` 
	c_Matrix
``` 
Association diagram:
``` 
	        _______ matrix[1] ______
	       /           |            \
	rowPorts[1..*]  colPorts[1..*]  rows[1..*]
``` 
### Keybrd Library Single-layer Classes
Classes inheritance diagrams:
``` 
	c_Key___________
	  |             \
	k_Key_1         m_Mouse
	                /     \
	       m_Mouse_Move  m_Mouse_Button
``` 
Association diagram:
``` 
	keybrd[1]
	   |
	matrix[M] ________________________
	   |              \               \
	rowPort[M..*] -- colPort[M..*] -- row[M..*] -- rowWait[1]
	    \             /                |
	    IOExpanderPort[0..*]          key[M..*]
	                  \______________  |
	                                  LEDPort[0..*]
	M = at least one matrix
``` 
### Keybrd Library Multi-layer Classes
Class inheritance diagram:
 ``` 
	                         _ c_Key _______________________________
	                        /          \                            \
	                   l_Key_1    l_Key_Layered                      \
	                                                                  \
	         ____________________ l_Code ___________________________   \
	        /        /        /           \          \              \   \
	l_Code_S  l_Code_SS  l_Code_SNS   l_Code_Shift  l_Code_Layer   m_Mouse
	                                                                /     \
	                                                      m_Mouse_Move  m_Mouse_Button
	l_ShiftManager

	l_LayerManager
 
l_Code_Layer and l_LayerManager are custom classes in keybrd_Layers library.
 
Summary of l_Code subclasses:
 CLASS NAME     SUFFIX MEANING          ACTION
 l_Code_S       Scancode                send scancode to USB
 l_Code_SS      Scancode Shift          send scancode to USB with MODIFIERKEY_SHIFT pressed
 l_Code_SNS     Scancode No Shift       send scancode to USB with MODIFIERKEY_SHIFT released
 l_Code_Layer   Layer code              call layerManager

Scancodes for multi-layer keybrds are instantiated in:
	l_scancodes.h
	l_scancodesNotShifted.h
	m_mousecodes.h
```
Association diagram:
``` todo, no: put classes next to each other?: rowPort & row, colPort & key, IOEpanderPort & LEDPort
    leave as is to show 3 components of matrix at same level, which is more important
	keybrd[1]
	   |
	matrix[M] ________________________
	   |              \               \
	rowPort[M..*] -- colPort[M..*] -- row[M..*] -- rowWait[1]
	    \             /                |
	    IOExpanderPort[0..*]          key[M..*] -- layerManager[1]
	                 \                 |         _/
	                  \               code[M..*] -- shiftManager[1]
	                   \_____________  |
	                                  LEDPort[0..*]
	M = at least one matrix
``` 

## The Arduion Development Environment
The keybrd libraries compile on the Arduino IDE and make extensive use of the following Arduino libraries:
    #include <Arduino.h>
    #include <Keyboard.h>
    #include <Mouse.h>
    #include <Wire.h>

## Variable Naming Conventions
* **key** is a key object.
* **row** is a row of key objects.
* **col** is an index corresponding to a key object in a row.

* **itemCount** is a variable number of items.
* **ITEM_COUNT** is a constant number of items.
* **itemNum** is index number for items.

## Style Guide
Following the style guide makes it easier for the next programmer to understand your code.
* For class names, see above section "Class naming conventions"
* For function names, use camelCase starting with lowercase letter.
* Use constants rather than macros, except for header guards.
* For constant names that could be macros, use ALL_CAPS_AND_UNDERSCORE.
* Use header guards CLASS_NAME_H.
* Prefix pointer name with "ptr" e.g. ptrRow =  &row
* Name arrays using the plural of elements e.g. c_Row* const = ptrsRows { &row0,  &row1 };
* Pass arrays using array notation rather than pointer notation.  Use

    void printArray(char[] array);

not

    void printArray( char* array);

* In constructor's initialization list, use same names for fields and constructor parameters
	this is less confusing if the constructor gets moved the implementation file
* Do not use new or malloc (to make memory leaks impossible).
* If class has any non-[POD](http://en.wikipedia.org/wiki/Plain_old_data_structure) data members, [do not inline constructors and destructors](http://www.chromium.org/developers/coding-style/cpp-dos-and-donts).
* Document class in .h file, above the class declaration.

(the following styles can be automated with Artistic Style, explained in doc/astylerc)
* Indent 4 spaces.
* Do not use tabs, use spaces.
* Maximum code width of 100 columns.
* Use broken, indented brackets, except for the opening bracket:
```cpp
int Foo(bool isBar) 
{
    if (isBar)
        {
        bar();
        }
}
```

