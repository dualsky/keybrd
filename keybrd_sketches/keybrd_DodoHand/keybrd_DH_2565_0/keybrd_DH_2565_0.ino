/* keybrd_DodoHand/keybrd_DH_2565_0.ino DataHand QWERTY layout
 * for DodoHand project on https://github.com/dodohand/dodohand
 * and https://geekhack.org/index.php?topic=41422.0
 */
// ################# GLOBAL ####################
// ================ INCLUDES ===================
#include <Keyboard.h>
#include <Mouse.h>
#include <Wire.h>

/* //keybrd library files
#include <objects_scancode.h>
#include <m_MouseButton.h>
#include <m_MouseMove.h>
#include <l_Code_00.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <c_Row.h>
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
#include <l_LayerManager.h>*/

//keybrd library files
#include <l_Code_Shift>
#include <l_ShiftManager.h>

#include <l_Code_NormalLock.h>
#include <l_Code_NAS.h>
#include <l_Code_NASLock.h>
#include <l_Code_NASHold.h>
#include <l_Code_NASTenKeyLock.h>
#include <l_Code_MF.h>
#include <l_Code_MFLock.h>
#include <l_Code_MFMouseArrowLock.h>

#include <l_Code_SNS_00.h>
#include <l_Code_LckLED.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <objects_scancode.h>

#include <m_Mouse_Button.h>
#include <m_Mouse_Move.h>

#include <c_IOExpanderPort.h>
#include <c_RowPort_PCA9655E_ActiveHigh.h>
#include <c_ColPort_PCA9655E_ActiveHigh.h>
#include <c_LED_PCA9655E.h>

#include <c_RowPort_AVR_ActiveHigh.h>
#include <c_ColPort_AVR_ActiveHigh.h>
#include <c_LED_AVR.h>

#include <c_RowWait.h>
#include <c_Row.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_LayerManager.h>
#include <l_Code_Layer.h>

// ================= LAYERS ====================
//                    NAS          NAS         MF        MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MOUSE_ON, ARROW_ON };

// ============= STATIC MEMBERS ================
c_RowWait rowWait(10, 5);
c_RowWait& c_Row::refRowWait = rowWait;

l_Code_Shift* ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager(NORMAL);
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

uint8_t l_Code_NAS::resumeLayer = TEN_KEY_OFF;
bool l_Code_MF::pressed = false;

// ################## MAIN #####################
void setup() {}
void loop()
{
// ================= CODES =====================
// -------------- LAYER CODES ------------------
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

// --------------- SCAN CODES ------------------
l_Code_SNS_00 sns_00;                           //double zero

// -------------- MOUSE CODES ------------------
const uint8_t MOUSE_SLOW = 8;
const uint8_t MOUSE_QUICK = 16;

m_Mouse_Move m_right(MOUSE_SLOW,0,0);
m_Mouse_Move m_left(-MOUSE_SLOW,0,0);
m_Mouse_Move m_down(0,MOUSE_SLOW,0);            //positive Y is down
m_Mouse_Move m_up(0,-MOUSE_SLOW,0);

m_Mouse_Move m_rightQuick(MOUSE_QUICK,0,0);
m_Mouse_Move m_leftQuick(-MOUSE_QUICK,0,0);
m_Mouse_Move m_downQuick(0,MOUSE_QUICK,0);
m_Mouse_Move m_upQuick(0,-MOUSE_QUICK,0);

m_Mouse_Button mb_1(MOUSE_LEFT);
m_Mouse_Button mb_2(MOUSE_MIDDLE);
m_Mouse_Button mb_3(MOUSE_RIGHT);

/* ============ KEY COORDINATES ================
Key names identify the key's position by coordinates defined in the tables below.
Finger coordinates are hand+direction+column.  For example:
        k_Ln0  is key at Left north pinky
Thumb coordinates are hand+direction.  For example:
        k_Rtdd is key at Right thumb hard down

-------- Fist coordinate is L or R matrix --------
matrix letter:          L       R
meaning:                Left    Right

---- Second coordinate is row number -----
left row number:        0       1       2       3       4
finger direction:       north   east    center  south   west

right row number:       n       w       c       s       e
right row number:       0       1       2       3       4
finger direction:       north   west    center  south   east
 (west and east are swapped compared to left matrix because right PCB is flipped)

row number, col 4:      tn      tk      td
row number, col 4:      0       1       2
thumb direction:        nail    knuckle down

row number, col 5:      thd     tp      tu
row number, col 5:      0       1       2
thumb direction:        hard    pad     up
                        down

------- Third coordinate is column number ------
column number:          0       1       2       3       4       5
meaning:                pinky   ring    middle  index   thumb   thumb
*/

// ================== LEFT =====================
// ------------- LEFT ROW PORTS ----------------
c_RowPort_AVR_ActiveHigh rowPortF_L(DDRF, PORTF, 1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6 );

// ------------- LEFT COL PORTS ----------------
c_ColPort_AVR_ActiveHigh colPortB_L(DDRB, PORTB, PINB, 1<<0 | 1<<1 | 1<<2 | 1<<3 );
c_ColPort_AVR_ActiveHigh colPortD_L(DDRD, PORTD, PIND, 1<<2 | 1<<3 );

// ------------- LEFT LED CODES ----------------
c_LED_AVR LED_0_L(PORTB, 1<<6);
c_LED_AVR LED_1_L(PORTB, 1<<5);
c_LED_AVR LED_2_L(PORTB, 1<<7);
c_LED_AVR LED_D6_3_L(PORTD, 1<<6);
//todo: assign the LEDs to codes
//l_Code_LckLED l_capsLck_L(KEY_CAPS_LOCK, capsLck_LED_L);

// --------------- LEFT KEYS -------------------
//Layers:                 {normal,      10KeyOff,       10KeyOn,        mouseOn,        arrowOn };
//row_L0 north keys
l_Code* ptrsCodes_L00[] = {&s_q,        &s_exclamation, &s_exclamation, &s_F2,          &s_F2   };
l_Key_Layered k_L00(ptrsCodes_L00);

l_Code* ptrsCodes_L01[] = {&s_w,        &s_at,          &s_at,          &s_F4,          &s_F4   };
l_Key_Layered k_L01(ptrsCodes_L01);

l_Code* ptrsCodes_L02[] = {&s_e,        &s_number,      &s_number,      &s_F6,          &s_F6   };
l_Key_Layered k_L02(ptrsCodes_L02);

l_Code* ptrsCodes_L03[] = {&s_r,        &s_dollar,      &s_up,          &m_upQuick,     &s_up   };
l_Key_Layered k_L03(ptrsCodes_L03);

//row_L1 east keys
l_Code* ptrsCodes_L10[] = {&s_leftBracket, &s_tilde,    &s_tilde,       &s_scrollLock,  &s_scrollLock};
l_Key_Layered k_L10(ptrsCodes_L10);

l_Code* ptrsCodes_L11[] = {&s_b,        &s_numLock,     &code_null,     &s_numLock,     &s_numLock};
l_Key_Layered k_L11(ptrsCodes_L11);

l_Code* ptrsCodes_L12[] = {&s_t,        &s_greaterThan, &s_greaterThan, &s_enter,       &s_enter};
l_Key_Layered k_L12(ptrsCodes_L12);

l_Code* ptrsCodes_L13[] = {&s_g,        &s_5,           &s_right,       &m_rightQuick,  &s_right};
l_Key_Layered k_L13(ptrsCodes_L13);

//row_L2 center keys
l_Code* ptrsCodes_L20[] = {&s_a,        &s_1,           &s_comma,       &code_null,     &code_null};
l_Key_Layered k_L20(ptrsCodes_L20);                 //todo: replace above code_null with L/R Modf

l_Code* ptrsCodes_L21[] = {&s_s,        &s_2,           &s_dollar,      &mb_3,  &mb_3};
l_Key_Layered k_L21(ptrsCodes_L21);

l_Code* ptrsCodes_L22[] = {&s_d,        &s_3,           &s_ampersand,   &l_mouseOn,     &l_mouseOn};
l_Key_Layered k_L22(ptrsCodes_L22);

l_Code* ptrsCodes_L23[] = {&s_f,        &s_4,           &s_home,        &mb_1,          &s_home};
l_Key_Layered k_L23(ptrsCodes_L23);

//row_L3 south keys
l_Code* ptrsCodes_L30[] = {&s_z,        &s_equal,       &s_leftParen,   &s_F1,          &s_F1};
l_Key_Layered k_L30(ptrsCodes_L30);

l_Code* ptrsCodes_L31[] = {&s_x,        &sns_00,        &s_rightParen,  &s_F3,          &s_F3};
l_Key_Layered k_L31(ptrsCodes_L31);

l_Code* ptrsCodes_L32[] = {&s_c,        &s_percent,     &s_percent,     &s_F5,          &s_F5};
l_Key_Layered k_L32(ptrsCodes_L32);

l_Code* ptrsCodes_L33[] = {&s_v,        &s_minus,       &s_down,        &m_downQuick,   &s_down};
l_Key_Layered k_L33(ptrsCodes_L33);

//row_L4 west keys
l_Key_1 k_L40(&s_delete);

l_Key_1 k_L41(&s_esc);

l_Code* ptrsCodes_L42[] = {&s_grave,    &s_lessThan,    &s_lessThan,    &s_equal,       &s_equal};
l_Key_Layered k_L42(ptrsCodes_L42);

l_Code* ptrsCodes_L43[] = {&s_doubleQuote,&s_slash,     &s_left,        &m_leftQuick,   &s_left};
l_Key_Layered k_L43(ptrsCodes_L43);

//thumb col 4 keys
l_Key_1 k_L04(&s_tab);                         //thumb nail
l_Key_1 k_L14(&s_ctrl);                        //thumb knuckle
l_Key_1 k_L24(&s_shift);                       //thumb down

//thumb col 5 keys
l_Key_1 k_L05(&s_capsLock);                   //thumb hard down
l_Key_1 k_L15(&s_enter);                       //thumb pad
l_Key_1 k_L25(&l_normal);                      //thumb up

// --------------- LEFT ROWS -------------------
//                             pinky    ring  middle   index  thumb  thumb
//row_L0 north          col:       0       1       2       3      4      5
c_Key* const ptrKeys_L0[] = { &k_L00, &k_L01, &k_L02, &k_L03, &k_L04, &k_L05};
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeys_L0)/sizeof(ptrKeys_L0[0]);
c_Row row_L0(ptrKeys_L0, KEYS_L0_COUNT);

//row_L1 east
c_Key* const ptrKeys_L1[] = { &k_L10, &k_L11, &k_L12, &k_L13, &k_L14, &k_L15 };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeys_L1)/sizeof(ptrKeys_L1[0]);
c_Row row_L1(ptrKeys_L1, KEYS_L1_COUNT);

//row_L2 center
c_Key* const ptrKeys_L2[] = { &k_L20, &k_L21, &k_L22, &k_L23, &k_L24, &k_L25 };
const uint8_t KEYS_L2_COUNT = sizeof(ptrKeys_L2)/sizeof(ptrKeys_L2[0]);
c_Row row_L2(ptrKeys_L2, KEYS_L2_COUNT);

//row_L3 south
c_Key* const ptrKeys_L3[] = { &k_L30, &k_L31, &k_L32, &k_L33 };
const uint8_t KEYS_L3_COUNT = sizeof(ptrKeys_L3)/sizeof(ptrKeys_L3[0]);
c_Row row_L3(ptrKeys_L3, KEYS_L3_COUNT);

//row_L4 west
c_Key* const ptrKeys_L4[] = { &k_L40, &k_L41, &k_L42, &k_L43 };
const uint8_t KEYS_L4_COUNT = sizeof(ptrKeys_L4)/sizeof(ptrKeys_L4[0]);
c_Row row_L4(ptrKeys_L4, KEYS_L4_COUNT);

// -------------- LEFT MATRIX ------------------
c_RowPort* ptrsRowPorts_L[] = { &rowPortF_L };
c_ColPort* ptrsColPorts_L[] = { &colPortB_L, &colPortD_L };
c_Row* const ptrsRows_L[] = { &row_L0, &row_L1, &row_L2, &row_L3, &row_L4 };
c_Matrix matrix_L(ptrsRowPorts_L, 1, ptrsColPorts_L, 2, ptrsRows_L, 5);

// ================= RIGHT =====================
// ------------- RIGHT ROW PORTS ---------------
c_IOExpanderPort port1_R(0x30, 1);
c_RowPort_PCA9655E_ActiveHigh rowPort1_R(port1_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 );

// ------------- RIGHT COL PORTS ---------------
c_IOExpanderPort port0_R(0x30, 0);
c_ColPort_PCA9655E_ActiveHigh colPort0_R(port0_R, 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5 );
//(on schematic https://geekhack.org/index.php?topic=41422.msg1680696#msg1680696 Reply #418,
//column port to pin mapping appears reversed because right PCB is flipped)

// ------------- RIGHT LED CODES ---------------
c_LED_PCA9655E LED_0_R(port0_R, 1<<6);
c_LED_PCA9655E LED_1_R(port0_R, 1<<7);
c_LED_PCA9655E LED_2_R(port1_R, 1<<5);
c_LED_PCA9655E LED_D6_3_R(port1_R, 1<<6);
//todo: assign the LEDs to codes
//l_Code_LckLED l_capsLck_R(KEY_CAPS_LOCK, capsLck_LED_R);

// -------------- RIGHT KEYS -------------------
//Layers:                 {normal,      10KeyOff,       10KeyOn,        mouseOn,        arrowOn };
//row_R0 north
l_Code * ptrsCodes_R00[]= {&s_p,        &s_rightParen,  &s_asterisk,    &s_pageUp,      &s_pageUp};
l_Key_Layered k_R00(ptrsCodes_R00);

l_Code * ptrsCodes_R01[]= {&s_o,        &s_leftParen,   &s_9,           &s_F10,         &s_F10};
l_Key_Layered k_R01(ptrsCodes_R01);

l_Code * ptrsCodes_R02[]= {&s_l,        &s_asterisk,    &s_8,           &s_F8,          &s_F8};
l_Key_Layered k_R02(ptrsCodes_R02);

l_Code * ptrsCodes_R03[]= {&s_u,        &s_ampersand,   &s_7,           &m_up,          &s_up};
l_Key_Layered k_R03(ptrsCodes_R03);

//row_R1 west
l_Code * ptrsCodes_R10[]= {&s_rightBracket, &l_tenKeyOff, &l_tenKeyOff, &s_F11,         &s_F11};
l_Key_Layered k_R10(ptrsCodes_R10);

l_Code * ptrsCodes_R11[]= {&s_n,        &s_semicolon,   &s_equal,       &s_insert,      &s_insert};
l_Key_Layered k_R11(ptrsCodes_R11);

l_Code * ptrsCodes_R12[]= {&s_y,        &s_circumflex,  &s_plus,        &s_end,         &s_end};
l_Key_Layered k_R12(ptrsCodes_R12);

l_Code * ptrsCodes_R13[]= {&s_h,        &s_6,           &s_0,           &m_left,        &s_left};
l_Key_Layered k_R13(ptrsCodes_R13);

//row_R2 center
l_Code * ptrsCodes_R20[]= {&s_semicolon, &s_0,          &s_period,      &s_pause,       &s_pause};
l_Key_Layered k_R20(ptrsCodes_R20);

l_Code * ptrsCodes_R21[]= {&s_l,        &s_9,           &s_6,       &s_printscreen, &s_printscreen};
l_Key_Layered k_R21(ptrsCodes_R21);

l_Code * ptrsCodes_R22[]= {&s_k,        &s_8,           &s_5,           &l_arrowOn,     &l_arrowOn};
l_Key_Layered k_R22(ptrsCodes_R22);

l_Code * ptrsCodes_R23[]= {&s_j,        &s_7,           &s_4,           &mb_2,          &s_home};
l_Key_Layered k_R23(ptrsCodes_R23);

//row_R3 south
l_Code * ptrsCodes_R30[]= {&s_slash,    &s_question,    &s_slash,       &s_pageDown,   &s_pageDown};
l_Key_Layered k_R30(ptrsCodes_R30);

l_Code * ptrsCodes_R31[]= {&s_period,   &s_period,      &s_3,           &s_F9,          &s_F9};
l_Key_Layered k_R31(ptrsCodes_R31);

l_Code * ptrsCodes_R32[]= {&s_comma,    &s_comma,       &s_2,           &s_F7,          &s_F7};
l_Key_Layered k_R32(ptrsCodes_R32);

l_Code * ptrsCodes_R33[]= {&s_m,        &s_plus,        &s_1,           &m_down,        &s_down};
l_Key_Layered k_R33(ptrsCodes_R33);

//row_R4 east
l_Code * ptrsCodes_R40[]= {&s_backslash, &l_tenKeyOn,   &l_tenKeyOn,    &s_F12,         &s_F12};
l_Key_Layered k_R40(ptrsCodes_R40);

l_Key_1 k_R41(&s_enter);

l_Code * ptrsCodes_R42[]= {&s_colon,    &s_colon,       &s_minus,       &s_shift,       &s_shift};
l_Key_Layered k_R42(ptrsCodes_R42);

l_Code * ptrsCodes_R43[]= {&s_quote,    &s_underscore,  &sns_00,        &m_right,       &s_right};
l_Key_Layered k_R43(ptrsCodes_R43);

//thumb col 4 keys
l_Key_1 k_R04(&s_backspace);                   //thumb nail
l_Key_1 k_R14(&s_alt);                         //thumb knuckle
l_Key_1 k_R24(&l_NASLock);                     //thumb down

//thumb col 5 keys
l_Key_1 k_R05(&l_NAS);                        //thumb hard down
l_Key_1 k_R15(&s_space);                       //thumb pad
l_Key_1 k_R25(&l_MF);                          //thumb up

// -------------- RIGHT ROWS -------------------
//                             pinky    ring  middle   index  thumb  thumb
//row_R0 north          col:       0       1       2       3      4      5
c_Key* const ptrKeys_R0[] = { &k_R00, &k_R01, &k_R02, &k_R03, &k_R04, &k_R05 };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKeys_R0)/sizeof(ptrKeys_R0[0]);
c_Row row_R0(ptrKeys_R0, KEYS_R0_COUNT);

//row_R1 west
c_Key* const ptrKeys_R1[] = { &k_R10, &k_R11, &k_R12, &k_R13, &k_R14, &k_R15 };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKeys_R1)/sizeof(ptrKeys_R1[0]);
c_Row row_R1(ptrKeys_R1, KEYS_R1_COUNT);

//row_R2 center
c_Key* const ptrKeys_R2[] = { &k_R20, &k_R21, &k_R22, &k_R23, &k_R24, &k_R25 };
const uint8_t KEYS_R2_COUNT = sizeof(ptrKeys_R2)/sizeof(ptrKeys_R2[0]);
c_Row row_R2(ptrKeys_R2, KEYS_R2_COUNT);

//row_R3 south
c_Key* const ptrKeys_R3[] = { &k_R30, &k_R31, &k_R32, &k_R33 };
const uint8_t KEYS_R3_COUNT = sizeof(ptrKeys_R3)/sizeof(ptrKeys_R3[0]);
c_Row row_R3(ptrKeys_R3, KEYS_R3_COUNT);

//row_R4 east
c_Key* const ptrKeys_R4[] = { &k_R40, &k_R41, &k_R42, &k_R43 };
const uint8_t KEYS_R4_COUNT = sizeof(ptrKeys_R4)/sizeof(ptrKeys_R4[0]);
c_Row row_R4(ptrKeys_R4, KEYS_R4_COUNT);

// ------------- RIGHT MATRIX ------------------
c_RowPort* ptrsRowPorts_R[] = { &rowPort1_R };
c_ColPort* ptrsColPorts_R[] = { &colPort0_R };
c_Row* const ptrsRows_R[] = { &row_R0, &row_R1, &row_R2, &row_R3, &row_R4 };
c_Matrix matrix_R(ptrsRowPorts_R, 1, ptrsColPorts_R, 1, ptrsRows_R, 5);

// =============== KEYBOARD ====================
c_Matrix* const ptrsMatrices[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrices, 2);

// ================== RUN ======================
    keybrd.begin();

    while (true)
    {
        keybrd.scan();
    }
}
