/* This file instandiates l_Code_SNS objects for multiple-layer keybrd sketches.
 * The scancode is always sent in the unshifted state regardless of shift key position.
 * Letters will still printed as capital if CapsLck is on.
 *
 * If your uC is low on memory, copy needed lines rather than including the entire file.
 * With the Arduino IDE, objects consume memory if they are used or not.
 *
 * The scancode macros are defined in the top part of
 * Arduino\hardware\teensy\cores\teensy\keylayouts.h which is intended for use in "normal" programs.
 * This has been tested on teensy2.0.
 */
#include <l_Code_SNS.h>
#include <l_Code_00.h>

// ********** SCANCODES NOT SHIFTED *********
l_Code_00 sns_00;                               //double zero

l_Code_SNS sns_1(KEY_1);                        //could get similar effect with s_pad1
l_Code_SNS sns_2(KEY_2);
l_Code_SNS sns_3(KEY_3);
l_Code_SNS sns_4(KEY_4);
l_Code_SNS sns_5(KEY_5);
l_Code_SNS sns_6(KEY_6);
l_Code_SNS sns_7(KEY_7);
l_Code_SNS sns_8(KEY_8);
l_Code_SNS sns_9(KEY_9);
l_Code_SNS sns_0(KEY_0);

l_Code_SNS sns_minus(KEY_MINUS);                //could get similar effect with s_padMinus
l_Code_SNS sns_equal(KEY_EQUAL);
l_Code_SNS sns_leftBracket(KEY_LEFT_BRACE);     //[ ("brace" means curly bracket {})
l_Code_SNS sns_rightBracket(KEY_RIGHT_BRACE);   //]
l_Code_SNS sns_backslash(KEY_BACKSLASH);
l_Code_SNS sns_semicolon(KEY_SEMICOLON);
l_Code_SNS sns_quote(KEY_QUOTE);
l_Code_SNS sns_tilde(KEY_TILDE);
l_Code_SNS sns_comma(KEY_COMMA);
l_Code_SNS sns_period(KEY_PERIOD);
l_Code_SNS sns_slash(KEY_SLASH);
