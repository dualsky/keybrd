/* keybrd_DodoHand/keybrd_DH_2565_0.ino DataHand QWERTY layout
 * for DodoHand project on https://github.com/dodohand/dodohand
 * and https://geekhack.org/index.php?topic=41422.0
 */
// ********** INCLUDES *********
#include <Keyboard.h>
#include <Mouse.h>
#include <Wire.h>

//keybrd library files
#include <objects_scancode.h>
#include <m_MouseButton.h>
#include <m_MouseMove.h>
#include <l_Code_00.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix_MCP23018.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>
#include <l_ShiftManager.h>

//keybrd_Layers library files (custom classes for multi-layer keyboards)
#include <l_Code_NormalLock.h>
#include <l_Code_NAS.h>
#include <l_Code_NASLock.h>
#include <l_Code_NASHold.h>
#include <l_Code_NASTenKeyLock.h>
#include <l_Code_MF.h>
#include <l_Code_MFLock.h>
#include <l_Code_MFMouseArrowLock.h>
#include <l_LayerManager.h>

// ********* CONIFGURATION VALUES ******
const uint8_t MOUSE_SLOW = 8;
const uint8_t MOUSE_QUICK = 16;

//                    NAS          NAS         MF        MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MOUSE_ON, ARROW_ON };
//            0       1            2           3         4

// ********* LAYER CODES **********
//Normal
l_Code_NormalLock l_normal(NORMAL);

//NAS
l_Code_NASHold l_NAS;
l_Code_NASLock l_NASLock;
l_Code_NASTenKeyLock l_tenKeyOff(TEN_KEY_OFF);
l_Code_NASTenKeyLock l_tenKeyOn(TEN_KEY_ON);
//l_Code_MFMouseArrowLock l_tenKeyOff_NumLck(TEN_KEY_OFF_NUMLCK); to be implmented
//l_Code_MFMouseArrowLock l_tenKeyOn_NumLck(TEN_KEY_ON_NUMLCK); to be implmented

//MF
l_Code_MFLock l_MF(MOUSE_ON);
l_Code_MFMouseArrowLock l_arrowOn(ARROW_ON);
l_Code_MFMouseArrowLock l_mouseOn(MOUSE_ON);

//static variables
uint8_t l_Code_NAS::resumeLayer = TEN_KEY_OFF;
bool l_Code_MF::pressed = false;

// ********** SCANCODES NOT SHIFTED *********
l_Code_00 sns_00;                               //double zero

// ********** MOUSE CODES *********
m_MouseMove m_right(MOUSE_SLOW,0,0);
m_MouseMove m_left(-MOUSE_SLOW,0,0);
m_MouseMove m_down(0,MOUSE_SLOW,0);     //positive Y is down
m_MouseMove m_up(0,-MOUSE_SLOW,0);

m_MouseMove m_rightQuick(MOUSE_QUICK,0,0);
m_MouseMove m_leftQuick(-MOUSE_QUICK,0,0);
m_MouseMove m_downQuick(0,MOUSE_QUICK,0);
m_MouseMove m_upQuick(0,-MOUSE_QUICK,0);

m_MouseButton mb_1(MOUSE_LEFT);
m_MouseButton mb_2(MOUSE_MIDDLE);
m_MouseButton mb_3(MOUSE_RIGHT);

/******************** HAND COORDINATES *************************
Key names identify the key's position by hand coordinates.
Finger coordinates are hand+direction+column.  For example:
        k_Ln0  is key at Left north pinky
Thumb coordinates are hand+direction.  For example:
        k_Rtdd is key at Right thumb hard down

-----------------Fist coordinate is L or R hand-----------------
hand:                   L       R
meaning:                Left    Right

---------------Second coordinate is direction letter------------
L finger direction:     n       e       c       s       w
meaning:                north   east    center  south   west

R finger direction:     n       w       c       s       e
meaning:                north   west    center  south   east

thumb direction col 4:  tn      tk      td
meaning:                nail    knuckle down

thumb direction col 5:  thd     tp      tu
meaning:                hard    pad     up
                        down

row number:             0       1       2       3       4

----------------Third coordinate is column number---------------
column number:          0       1       2       3       4       5
meaning:                pinky   ring    middle  index
*/

// ********** LEFT KEYS ***********
//Layers:                 {normal,      10KeyOff,       10KeyOn,        mouseOn,        arrowOn };
//North keys row
l_Code* ptrsCodes_Ln0[] = {&s_q,        &s_exclamation, &s_exclamation,&s_F2,           &s_F2   };
l_Key_Layered k_Ln0(ptrsCodes_Ln0);

l_Code* ptrsCodes_Ln1[] = {&s_w,        &s_at,          &s_at,          &s_F4,          &s_F4   };
l_Key_Layered k_Ln1(ptrsCodes_Ln1);

l_Code* ptrsCodes_Ln2[] = {&s_e,        &s_number,      &s_number,      &s_F6,          &s_F6   };
l_Key_Layered k_Ln2(ptrsCodes_Ln2);

l_Code* ptrsCodes_Ln3[] = {&s_r,        &s_dollar,      &s_up,          &m_upQuick,     &s_up   };
l_Key_Layered k_Ln3(ptrsCodes_Ln3);

//West keys row
l_Key_1 k_Lw0(&s_delete);

l_Key_1 k_Lw1(&s_esc);

l_Code* ptrsCodes_Lw2[] = {&s_grave,    &s_lessThan,    &s_lessThan,    &s_equal,       &s_equal};
l_Key_Layered k_Lw2(ptrsCodes_Lw2);

l_Code* ptrsCodes_Lw3[] = {&s_doubleQuote,&s_slash,     &s_left,        &m_leftQuick,   &s_left};
l_Key_Layered k_Lw3(ptrsCodes_Lw3);

//Well keys row
l_Code* ptrsCodes_Lc0[] = {&s_a,        &s_1,           &s_comma,       &s_null,        &s_null};
l_Key_Layered k_Lc0(ptrsCodes_Lc0);                     //todo: replace above s_null with L/R Modf

l_Code* ptrsCodes_Lc1[] = {&s_s,        &s_2,           &s_dollar,      &mb_3,  &mb_3};
l_Key_Layered k_Lc1(ptrsCodes_Lc1);

l_Code* ptrsCodes_Lc2[] = {&s_d,        &s_3,           &s_ampersand,   &l_mouseOn,     &l_mouseOn};
l_Key_Layered k_Lc2(ptrsCodes_Lc2);

l_Code* ptrsCodes_Lc3[] = {&s_f,        &s_4,           &s_home,        &mb_1,          &s_home};
l_Key_Layered k_Lc3(ptrsCodes_Lc3);

//East keys row
l_Code* ptrsCodes_Le0[] = {&s_leftBracket, &s_tilde,    &s_tilde,       &s_scrollLock,  &s_scrollLock};
l_Key_Layered k_Le0(ptrsCodes_Le0);

l_Code* ptrsCodes_Le1[] = {&s_b,        &s_numLock,     &s_null,        &s_numLock,     &s_numLock};
l_Key_Layered k_Le1(ptrsCodes_Le1);

l_Code* ptrsCodes_Le2[] = {&s_t,        &s_greaterThan, &s_greaterThan, &s_enter,       &s_enter};
l_Key_Layered k_Le2(ptrsCodes_Le2);

l_Code* ptrsCodes_Le3[] = {&s_g,        &s_5,           &s_right,       &m_rightQuick,  &s_right};
l_Key_Layered k_Le3(ptrsCodes_Le3);

//South keys row
l_Code* ptrsCodes_Ls0[] = {&s_z,        &s_equal,       &s_leftParen,   &s_F1,          &s_F1};
l_Key_Layered k_Ls0(ptrsCodes_Ls0);

l_Code* ptrsCodes_Ls1[] = {&s_x,        &sns_00,        &s_rightParen,  &s_F3,          &s_F3};
l_Key_Layered k_Ls1(ptrsCodes_Ls1);

l_Code* ptrsCodes_Ls2[] = {&s_c,        &s_percent,     &s_percent,     &s_F5,          &s_F5};
l_Key_Layered k_Ls2(ptrsCodes_Ls2);

l_Code* ptrsCodes_Ls3[] = {&s_v,        &s_minus,       &s_down,        &m_downQuick,   &s_down};
l_Key_Layered k_Ls3(ptrsCodes_Ls3);

//thumb keys col 4
l_Key_1 k_Ltn(&s_tab);
l_Key_1 k_Ltk(&s_ctrl);
l_Key_1 k_Ltd(&s_shift);

//thumb keys col 5
l_Key_1 k_Lthd(&s_capsLock);
l_Key_1 k_Ltp(&s_enter);
l_Key_1 k_Ltu(&l_normal);

// ********** RIGHT KEYS ***********
//Layers:                 {normal,      10KeyOff,       10KeyOn,        mouseOn,        arrowOn };
//North keys row
l_Code * ptrsCodes_Rn0[]= {&s_p,        &s_rightParen,  &s_asterisk,    &s_pageUp,      &s_pageUp};
l_Key_Layered k_Rn0(ptrsCodes_Rn0);

l_Code * ptrsCodes_Rn1[]= {&s_o,        &s_leftParen,   &s_9,           &s_F10,         &s_F10};
l_Key_Layered k_Rn1(ptrsCodes_Rn1);

l_Code * ptrsCodes_Rn2[]= {&s_l,        &s_asterisk,    &s_8,           &s_F8,          &s_F8};
l_Key_Layered k_Rn2(ptrsCodes_Rn2);

l_Code * ptrsCodes_Rn3[]= {&s_u,        &s_ampersand,   &s_7,           &m_up,          &s_up};
l_Key_Layered k_Rn3(ptrsCodes_Rn3);

//West keys row
l_Code * ptrsCodes_Rw0[]= {&s_rightBracket, &l_tenKeyOff, &l_tenKeyOff, &s_F11,         &s_F11};
l_Key_Layered k_Rw0(ptrsCodes_Rw0);

l_Code * ptrsCodes_Rw1[]= {&s_n,        &s_semicolon,   &s_equal,       &s_insert,      &s_insert};
l_Key_Layered k_Rw1(ptrsCodes_Rw1);

l_Code * ptrsCodes_Rw2[]= {&s_y,        &s_circumflex,  &s_plus,        &s_end,         &s_end};
l_Key_Layered k_Rw2(ptrsCodes_Rw2);

l_Code * ptrsCodes_Rw3[]= {&s_h,        &s_6,           &s_0,           &m_left,        &s_left};
l_Key_Layered k_Rw3(ptrsCodes_Rw3);

//Well keys row
l_Code * ptrsCodes_Rc0[]= {&s_semicolon, &s_0,          &s_period,      &s_pause,       &s_pause};
l_Key_Layered k_Rc0(ptrsCodes_Rc0);

l_Code * ptrsCodes_Rc1[]= {&s_l,        &s_9,           &s_6,           &s_printscreen, &s_printscreen};
l_Key_Layered k_Rc1(ptrsCodes_Rc1);

l_Code * ptrsCodes_Rc2[]= {&s_k,        &s_8,           &s_5,           &l_arrowOn,     &l_arrowOn};
l_Key_Layered k_Rc2(ptrsCodes_Rc2);

l_Code * ptrsCodes_Rc3[]= {&s_j,        &s_7,           &s_4,           &mb_2,          &s_home};
l_Key_Layered k_Rc3(ptrsCodes_Rc3);


//East keys row
l_Code * ptrsCodes_Re0[]= {&s_backslash, &l_tenKeyOn,   &l_tenKeyOn,    &s_F12,         &s_F12};
l_Key_Layered k_Re0(ptrsCodes_Re0);

l_Key_1 k_Re1(&s_enter);

l_Code * ptrsCodes_Re2[]= {&s_colon,    &s_colon,       &s_minus,       &s_shift,       &s_shift};
l_Key_Layered k_Re2(ptrsCodes_Re2);

l_Code * ptrsCodes_Re3[]= {&s_quote,    &s_underscore,  &sns_00,        &m_right,       &s_right};
l_Key_Layered k_Re3(ptrsCodes_Re3);

//South keys row
l_Code * ptrsCodes_Rs0[]= {&s_slash,    &s_question,    &s_slash,       &s_pageDown,    &s_pageDown};
l_Key_Layered k_Rs0(ptrsCodes_Rs0);

l_Code * ptrsCodes_Rs1[]= {&s_period,   &s_period,      &s_3,           &s_F9,          &s_F9};
l_Key_Layered k_Rs1(ptrsCodes_Rs1);

l_Code * ptrsCodes_Rs2[]= {&s_comma,    &s_comma,       &s_2,           &s_F7,          &s_F7};
l_Key_Layered k_Rs2(ptrsCodes_Rs2);

l_Code * ptrsCodes_Rs3[]= {&s_m,        &s_plus,        &s_1,           &m_down,        &s_down};
l_Key_Layered k_Rs3(ptrsCodes_Rs3);

//thumb keys col 4
l_Key_1 k_Rtn(&s_backspace);
l_Key_1 k_Rtk(&s_alt);
l_Key_1 k_Rtd(&l_NASLock);

//thumb keys col 5
l_Key_1 k_Rthd(&l_NAS);
l_Key_1 k_Rtp(&s_space);
l_Key_1 k_Rtu(&l_MF);

// ********** LEFT ROWS **********
//row_L0 north          col:       0       1       2       3      4      5
c_Key* const ptrKeys_L0[] = { &k_Ln0, &k_Ln1, &k_Ln2, &k_Ln3, &k_Ltn, &k_Lthd};
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeys_L0)/sizeof(ptrKeys_L0[0]);
c_Row_Ex row_L0(ptrKeys_L0, KEYS_L0_COUNT);

//row_L1 east
c_Key* const ptrKeys_L1[] = { &k_Le0, &k_Le1, &k_Le2, &k_Le3, &k_Ltk, &k_Ltp };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeys_L1)/sizeof(ptrKeys_L1[0]);
c_Row_Ex row_L1(ptrKeys_L1, KEYS_L1_COUNT);

//row_L2 center
c_Key* const ptrKeys_L2[] = { &k_Lc0, &k_Lc1, &k_Lc2, &k_Lc3, &k_Ltd, &k_Ltu };
const uint8_t KEYS_L2_COUNT = sizeof(ptrKeys_L2)/sizeof(ptrKeys_L2[0]);
c_Row_Ex row_L2(ptrKeys_L2, KEYS_L2_COUNT);

//row_L3 south
c_Key* const ptrKeys_L3[] = { &k_Ls0, &k_Ls1, &k_Ls2, &k_Ls3 };
const uint8_t KEYS_L3_COUNT = sizeof(ptrKeys_L3)/sizeof(ptrKeys_L3[0]);
c_Row_Ex row_L3(ptrKeys_L3, KEYS_L3_COUNT);

//row_L4 west
c_Key* const ptrKeys_L4[] = { &k_Lw0, &k_Lw1, &k_Lw2, &k_Lw3 };
const uint8_t KEYS_L4_COUNT = sizeof(ptrKeys_L4)/sizeof(ptrKeys_L4[0]);
c_Row_Ex row_L4(ptrKeys_L4, KEYS_L4_COUNT);

// ********** RIGHT ROWS **********
//row_R0 north          col:       0       1       2       3      4      5
c_Key* const ptrKeys_R0[] = { &k_Rn0, &k_Rn1, &k_Rn2, &k_Rn3, &k_Rtn, &k_Rtd };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKeys_R0)/sizeof(ptrKeys_R0[0]);
c_Row_Ex row_R0(ptrKeys_R0, KEYS_R0_COUNT);

//row_R1 west
c_Key* const ptrKeys_R1[] = { &k_Rw0, &k_Rw1, &k_Rw2, &k_Rw3, &k_Rtk, &k_Rtp };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKeys_R1)/sizeof(ptrKeys_R1[0]);
c_Row_Ex row_R1(ptrKeys_R1, KEYS_R1_COUNT);

//row_R2 center
c_Key* const ptrKeys_R2[] = { &k_Rc0, &k_Rc1, &k_Rc2, &k_Rc3, &k_Rtd, &k_Rtu };
const uint8_t KEYS_R2_COUNT = sizeof(ptrKeys_R2)/sizeof(ptrKeys_R2[0]);
c_Row_Ex row_R2(ptrKeys_R2, KEYS_R2_COUNT);

//row_R3 south
c_Key* const ptrKeys_R3[] = { &k_Rs0, &k_Rs1, &k_Rs2, &k_Rs3 };
const uint8_t KEYS_R3_COUNT = sizeof(ptrKeys_R3)/sizeof(ptrKeys_R3[0]);
c_Row_Ex row_R3(ptrKeys_R3, KEYS_R3_COUNT);

//row_R4 east
c_Key* const ptrKeys_R4[] = { &k_Re0, &k_Re1, &k_Re2, &k_Re3 };
const uint8_t KEYS_R4_COUNT = sizeof(ptrKeys_R4)/sizeof(ptrKeys_R4[0]);
c_Row_Ex row_R4(ptrKeys_R4, KEYS_R4_COUNT);

// ********** MATRICES ***********
//matrixL
c_Row_Ex* const ptrsRows_L[] = { &row_L0, &row_L1, &row_L2, &row_L3, &row_L4 };
const uint8_t ROWS_L_COUNT = sizeof(ptrsRows_L)/sizeof(ptrsRows_L[0]);
c_Matrix_MCP23018 matrix_L(ptrsRows_L, ROWS_L_COUNT);

//matrixR
c_Row_Ex* const ptrsRows_R[] = { &row_R0, &row_R1, &row_R2, &row_R3, &row_R4 };
const uint8_t ROWS_R_COUNT = sizeof(ptrsRows_R)/sizeof(ptrsRows_R[0]);
c_Matrix_Teensy2 matrix_R(ptrsRows_R, ROWS_R_COUNT);

c_RowWait rowWait(ROWS_L_COUNT + ROWS_R_COUNT, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

// ********** KEYBOARD ***********
c_Matrix* const ptrsMatrices[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrices, 2);

// ********** MANAGERS ***********
//instantiate managers
l_Code_Shift* const ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager(NORMAL);
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
