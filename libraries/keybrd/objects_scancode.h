/* Include this file in multiple-layer keybrd sketches.
 * This file instandiates l_Code objects.
 *
 * The scancode macros are defined in the top part of
 * Arduino\hardware\teensy\cores\teensy\keylayouts.h which is intended for use in "normal" programs.
 * This has been tested on teensy2.0.
 */
#include <l_Code_Null.h>
#include <l_Code_S.h>
#include <l_Code_SS.h>
#include <l_Code_Shift.h>

// ********** SCANCODES *********
l_Code_Shift s_shift(MODIFIERKEY_SHIFT);        //MODIFIERKEY_SHIFT = MODIFIERKEY_LEFT_SHIFT
l_Code_Shift s_shift_L(MODIFIERKEY_LEFT_SHIFT);
l_Code_Shift s_shift_R(MODIFIERKEY_RIGHT_SHIFT);

l_Code_S s_ctrl(MODIFIERKEY_CTRL);
l_Code_S s_alt(MODIFIERKEY_ALT);
l_Code_S s_gui(MODIFIERKEY_GUI);
l_Code_S s_leftCtrl(MODIFIERKEY_LEFT_CTRL);
l_Code_S s_leftAlt(MODIFIERKEY_LEFT_ALT);
l_Code_S s_leftGUI(MODIFIERKEY_LEFT_GUI);
l_Code_S s_rightCtrl(MODIFIERKEY_RIGHT_CTRL);
l_Code_S s_rightAlt(MODIFIERKEY_RIGHT_ALT);
l_Code_S s_rightGUI(MODIFIERKEY_RIGHT_GUI);

l_Code_S s_volumeInc(KEY_MEDIA_VOLUME_INC);
l_Code_S s_volumeDec(KEY_MEDIA_VOLUME_DEC);
l_Code_S s_mute(KEY_MEDIA_MUTE);
l_Code_S s_playPause(KEY_MEDIA_PLAY_PAUSE);
l_Code_S s_nextTrack(KEY_MEDIA_NEXT_TRACK);
l_Code_S s_prevTrack(KEY_MEDIA_PREV_TRACK);
l_Code_S s_stop(KEY_MEDIA_STOP);
l_Code_S s_eject(KEY_MEDIA_EJECT);

l_Code_S s_a(KEY_A);
l_Code_S s_b(KEY_B);
l_Code_S s_c(KEY_C);
l_Code_S s_d(KEY_D);
l_Code_S s_e(KEY_E);
l_Code_S s_f(KEY_F);
l_Code_S s_g(KEY_G);
l_Code_S s_h(KEY_H);
l_Code_S s_i(KEY_I);
l_Code_S s_j(KEY_J);
l_Code_S s_k(KEY_K);
l_Code_S s_l(KEY_L);
l_Code_S s_m(KEY_M);
l_Code_S s_n(KEY_N);
l_Code_S s_o(KEY_O);
l_Code_S s_p(KEY_P);
l_Code_S s_q(KEY_Q);
l_Code_S s_r(KEY_R);
l_Code_S s_s(KEY_S);
l_Code_S s_t(KEY_T);
l_Code_S s_u(KEY_U);
l_Code_S s_v(KEY_V);
l_Code_S s_w(KEY_W);
l_Code_S s_x(KEY_X);
l_Code_S s_y(KEY_Y);
l_Code_S s_z(KEY_Z);

l_Code_S s_1(KEY_1);
l_Code_S s_2(KEY_2);
l_Code_S s_3(KEY_3);
l_Code_S s_4(KEY_4);
l_Code_S s_5(KEY_5);
l_Code_S s_6(KEY_6);
l_Code_S s_7(KEY_7);
l_Code_S s_8(KEY_8);
l_Code_S s_9(KEY_9);
l_Code_S s_0(KEY_0);

l_Code_S s_enter(KEY_ENTER);
l_Code_S s_esc(KEY_ESC);
l_Code_S s_backspace(KEY_BACKSPACE);
l_Code_S s_tab(KEY_TAB);
l_Code_S s_space(KEY_SPACE);
l_Code_S s_minus(KEY_MINUS);
l_Code_S s_equal(KEY_EQUAL);
l_Code_S s_leftBracket(KEY_LEFT_BRACE);         //[ ("brace" means curly bracket {})
l_Code_S s_rightBracket(KEY_RIGHT_BRACE);       //]
l_Code_S s_backslash(KEY_BACKSLASH);
l_Code_S s_semicolon(KEY_SEMICOLON);
l_Code_S s_quote(KEY_QUOTE);
l_Code_S s_tilde(KEY_TILDE);
l_Code_S s_comma(KEY_COMMA);
l_Code_S s_period(KEY_PERIOD);
l_Code_S s_slash(KEY_SLASH);
l_Code_S s_capsLock(KEY_CAPS_LOCK);

l_Code_S s_F1(KEY_F1);
l_Code_S s_F2(KEY_F2);
l_Code_S s_F3(KEY_F3);
l_Code_S s_F4(KEY_F4);
l_Code_S s_F5(KEY_F5);
l_Code_S s_F6(KEY_F6);
l_Code_S s_F7(KEY_F7);
l_Code_S s_F8(KEY_F8);
l_Code_S s_F9(KEY_F9);
l_Code_S s_F10(KEY_F10);
l_Code_S s_F11(KEY_F11);
l_Code_S s_F12(KEY_F12);

l_Code_S s_printscreen(KEY_PRINTSCREEN);
l_Code_S s_scrollLock(KEY_SCROLL_LOCK);
l_Code_S s_pause(KEY_PAUSE);
l_Code_S s_insert(KEY_INSERT);
l_Code_S s_home(KEY_HOME);
l_Code_S s_pageUp(KEY_PAGE_UP);
l_Code_S s_delete(KEY_DELETE);
l_Code_S s_end(KEY_END);
l_Code_S s_pageDown(KEY_PAGE_DOWN);
l_Code_S s_right(KEY_RIGHT);                    //arrow
l_Code_S s_left(KEY_LEFT);
l_Code_S s_down(KEY_DOWN);
l_Code_S s_up(KEY_UP);
l_Code_S s_numLock(KEY_NUM_LOCK);

l_Code_S s_padSlash(KEYPAD_SLASH);
l_Code_S s_padAsterisk(KEYPAD_ASTERIX);         //correct spelling of asterisk
l_Code_S s_padMinus(KEYPAD_MINUS);
l_Code_S s_padPlus(KEYPAD_PLUS);
l_Code_S s_padEnter(KEYPAD_ENTER);
l_Code_S s_pad1(KEYPAD_1);
l_Code_S s_pad2(KEYPAD_2);
l_Code_S s_pad3(KEYPAD_3);
l_Code_S s_pad4(KEYPAD_4);
l_Code_S s_pad5(KEYPAD_5);
l_Code_S s_pad6(KEYPAD_6);
l_Code_S s_pad7(KEYPAD_7);
l_Code_S s_pad8(KEYPAD_8);
l_Code_S s_pad9(KEYPAD_9);
l_Code_S s_pad0(KEYPAD_0);
l_Code_S s_padPeriod(KEYPAD_PERIOD);

l_Code_S s_menu(KEY_MENU);
l_Code_S s_F13(KEY_F13);
l_Code_S s_F14(KEY_F14);
l_Code_S s_F15(KEY_F15);
l_Code_S s_F16(KEY_F16);
l_Code_S s_F17(KEY_F17);
l_Code_S s_F18(KEY_F18);
l_Code_S s_F19(KEY_F19);
l_Code_S s_F20(KEY_F20);
l_Code_S s_F21(KEY_F21);
l_Code_S s_F22(KEY_F22);
l_Code_S s_F23(KEY_F23);
l_Code_S s_F24(KEY_F24);

// ********** SCANCODES SHIFTED *********
// shifted objects are named after ascii symbol names
l_Code_SS s_exclamation(KEY_1);
l_Code_SS s_at(KEY_2);
l_Code_SS s_number(KEY_3);                      //#
l_Code_SS s_dollar(KEY_4);
l_Code_SS s_percent(KEY_5);
l_Code_SS s_circumflex(KEY_6);                  //^
l_Code_SS s_ampersand(KEY_7);
l_Code_SS s_asterisk(KEY_8);
l_Code_SS s_leftParen(KEY_9);                   //parenthesis
l_Code_SS s_rightParen(KEY_0);

l_Code_SS s_underscore(KEY_MINUS);
l_Code_SS s_plus(KEY_EQUAL);
l_Code_SS s_leftBrace(KEY_LEFT_BRACE);          //{
l_Code_SS s_rightBrace(KEY_RIGHT_BRACE);        //}
l_Code_SS s_vertBar(KEY_BACKSLASH);
l_Code_SS s_colon(KEY_SEMICOLON);
l_Code_SS s_doubleQuote(KEY_QUOTE);
l_Code_SS s_grave(KEY_TILDE);                   //`
l_Code_SS s_lessThan(KEY_COMMA);
l_Code_SS s_greaterThan(KEY_PERIOD);
l_Code_SS s_question(KEY_SLASH);

// ********** MISC CODES *********
l_Code_Null s_null;                             //usefull for blank keys
