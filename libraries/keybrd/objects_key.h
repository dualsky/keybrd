/* Include this file in single-layer keybrd sketches.
 * This file instandiates k_Key objects.
 *
 * The scancode macros are defined in the top part of
 * Arduino\hardware\teensy\cores\teensy\keylayouts.h which is intended for use in "normal" programs.
 * This has been tested on teensy2.0.
 */
#include <k_Key_1.h>
#include <k_Key_Null.h>

// ********** KEY CODES *********
k_Key_1  k_shift(MODIFIERKEY_SHIFT);            //MODIFIERKEY_SHIFT = MODIFIERKEY_LEFT_SHIFT
k_Key_1  k_shift_L(MODIFIERKEY_LEFT_SHIFT);
k_Key_1  k_shift_R(MODIFIERKEY_RIGHT_SHIFT);

k_Key_1 k_ctrl(MODIFIERKEY_CTRL);
k_Key_1 k_alt(MODIFIERKEY_ALT);
k_Key_1 k_gui(MODIFIERKEY_GUI);
k_Key_1 k_leftCtrl(MODIFIERKEY_LEFT_CTRL);
k_Key_1 k_leftAlt(MODIFIERKEY_LEFT_ALT);
k_Key_1 k_leftGUI(MODIFIERKEY_LEFT_GUI);
k_Key_1 k_rightCtrl(MODIFIERKEY_RIGHT_CTRL);
k_Key_1 k_rightAlt(MODIFIERKEY_RIGHT_ALT);
k_Key_1 k_rightGUI(MODIFIERKEY_RIGHT_GUI);

k_Key_1 k_volumeInc(KEY_MEDIA_VOLUME_INC);
k_Key_1 k_volumeDec(KEY_MEDIA_VOLUME_DEC);
k_Key_1 k_mute(KEY_MEDIA_MUTE);
k_Key_1 k_playPause(KEY_MEDIA_PLAY_PAUSE);
k_Key_1 k_nextTrack(KEY_MEDIA_NEXT_TRACK);
k_Key_1 k_prevTrack(KEY_MEDIA_PREV_TRACK);
k_Key_1 k_stop(KEY_MEDIA_STOP);
k_Key_1 k_eject(KEY_MEDIA_EJECT);

k_Key_1 k_a(KEY_A);
k_Key_1 k_b(KEY_B);
k_Key_1 k_c(KEY_C);
k_Key_1 k_d(KEY_D);
k_Key_1 k_e(KEY_E);
k_Key_1 k_f(KEY_F);
k_Key_1 k_g(KEY_G);
k_Key_1 k_h(KEY_H);
k_Key_1 k_i(KEY_I);
k_Key_1 k_j(KEY_J);
k_Key_1 k_k(KEY_K);
k_Key_1 k_l(KEY_L);
k_Key_1 k_m(KEY_M);
k_Key_1 k_n(KEY_N);
k_Key_1 k_o(KEY_O);
k_Key_1 k_p(KEY_P);
k_Key_1 k_q(KEY_Q);
k_Key_1 k_r(KEY_R);
k_Key_1 k_s(KEY_S);
k_Key_1 k_t(KEY_T);
k_Key_1 k_u(KEY_U);
k_Key_1 k_v(KEY_V);
k_Key_1 k_w(KEY_W);
k_Key_1 k_x(KEY_X);
k_Key_1 k_y(KEY_Y);
k_Key_1 k_z(KEY_Z);

k_Key_1 k_1(KEY_1);
k_Key_1 k_2(KEY_2);
k_Key_1 k_3(KEY_3);
k_Key_1 k_4(KEY_4);
k_Key_1 k_5(KEY_5);
k_Key_1 k_6(KEY_6);
k_Key_1 k_7(KEY_7);
k_Key_1 k_8(KEY_8);
k_Key_1 k_9(KEY_9);
k_Key_1 k_0(KEY_0);

k_Key_1 k_enter(KEY_ENTER);
k_Key_1 k_esc(KEY_ESC);
k_Key_1 k_backspace(KEY_BACKSPACE);
k_Key_1 k_tab(KEY_TAB);
k_Key_1 k_space(KEY_SPACE);
k_Key_1 k_minus(KEY_MINUS);
k_Key_1 k_equal(KEY_EQUAL);
k_Key_1 k_leftBracket(KEY_LEFT_BRACE);          //[ ("brace" means curly bracket {})
k_Key_1 k_rightBracket(KEY_RIGHT_BRACE);        //]
k_Key_1 k_backslash(KEY_BACKSLASH);
k_Key_1 k_semicolon(KEY_SEMICOLON);
k_Key_1 k_quote(KEY_QUOTE);
k_Key_1 k_tilde(KEY_TILDE);
k_Key_1 k_comma(KEY_COMMA);
k_Key_1 k_period(KEY_PERIOD);
k_Key_1 k_slash(KEY_SLASH);
k_Key_1 k_capsLock(KEY_CAPS_LOCK);

k_Key_1 k_F1(KEY_F1);
k_Key_1 k_F2(KEY_F2);
k_Key_1 k_F3(KEY_F3);
k_Key_1 k_F4(KEY_F4);
k_Key_1 k_F5(KEY_F5);
k_Key_1 k_F6(KEY_F6);
k_Key_1 k_F7(KEY_F7);
k_Key_1 k_F8(KEY_F8);
k_Key_1 k_F9(KEY_F9);
k_Key_1 k_F10(KEY_F10);
k_Key_1 k_F11(KEY_F11);
k_Key_1 k_F12(KEY_F12);

k_Key_1 k_printscreen(KEY_PRINTSCREEN);
k_Key_1 k_scrollLock(KEY_SCROLL_LOCK);
k_Key_1 k_pause(KEY_PAUSE);
k_Key_1 k_insert(KEY_INSERT);
k_Key_1 k_home(KEY_HOME);
k_Key_1 k_pageUp(KEY_PAGE_UP);
k_Key_1 k_delete(KEY_DELETE);
k_Key_1 k_end(KEY_END);
k_Key_1 k_pageDown(KEY_PAGE_DOWN);
k_Key_1 k_right(KEY_RIGHT);
k_Key_1 k_left(KEY_LEFT);
k_Key_1 k_down(KEY_DOWN);
k_Key_1 k_up(KEY_UP);
k_Key_1 k_numLock(KEY_NUM_LOCK);

k_Key_1 k_padSlash(KEYPAD_SLASH);
k_Key_1 k_padAsterisk(KEYPAD_ASTERIX);          //correct spelling of asterisk
k_Key_1 k_padMinus(KEYPAD_MINUS);
k_Key_1 k_padPlus(KEYPAD_PLUS);
k_Key_1 k_padEnter(KEYPAD_ENTER);
k_Key_1 k_pad1(KEYPAD_1);
k_Key_1 k_pad2(KEYPAD_2);
k_Key_1 k_pad3(KEYPAD_3);
k_Key_1 k_pad4(KEYPAD_4);
k_Key_1 k_pad5(KEYPAD_5);
k_Key_1 k_pad6(KEYPAD_6);
k_Key_1 k_pad7(KEYPAD_7);
k_Key_1 k_pad8(KEYPAD_8);
k_Key_1 k_pad9(KEYPAD_9);
k_Key_1 k_pad0(KEYPAD_0);
k_Key_1 k_padPeriod(KEYPAD_PERIOD);

k_Key_1 k_menu(KEY_MENU);
k_Key_1 k_F13(KEY_F13);
k_Key_1 k_F14(KEY_F14);
k_Key_1 k_F15(KEY_F15);
k_Key_1 k_F16(KEY_F16);
k_Key_1 k_F17(KEY_F17);
k_Key_1 k_F18(KEY_F18);
k_Key_1 k_F19(KEY_F19);
k_Key_1 k_F20(KEY_F20);
k_Key_1 k_F21(KEY_F21);
k_Key_1 k_F22(KEY_F22);
k_Key_1 k_F23(KEY_F23);
k_Key_1 k_F24(KEY_F24);

k_Key_Null k_null;                              //usefull for blank keys
