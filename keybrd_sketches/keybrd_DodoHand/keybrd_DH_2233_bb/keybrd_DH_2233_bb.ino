/* keybrd_DH_2233_bb.ino layout with layers normal/NAS10keyOff/NAS10tenKeyOn/mouse/arrow:
 *  D/3/&/mouseOn   R/$/upA/upM/upA K/8/5/arrowOn   tenKeyOff   tenKeyOn
 *  normal          Shift           NAS             NAS Lock    MF Lock
 */
// ################# GLOBAL ####################
// ================ INCLUDES ===================
//Arduino library files
#include <Keyboard.h>
#include <Mouse.h>
#include <Wire.h>

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

#include <l_Code_LckLED.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <objects_scancode.h>

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

//            NORMAL  NAS          NAS         MF        MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MOUSE_ON, ARROW_ON };

// ============= STATIC MEMBERS ================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

l_Code_Shift* const ptrsShifts[] = { &s_shift };
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
l_Code_NormalLock normal(NORMAL);

//NAS
l_Code_NASHold l_NAS;
l_Code_NASLock l_NASLock;
l_Code_NASTenKeyLock l_tenKeyOff(TEN_KEY_OFF);
l_Code_NASTenKeyLock l_tenKeyOn(TEN_KEY_ON);
//l_Code_NASTenKeyLock l_tenKeyOff_NumLck(TEN_KEY_OFF_NUMLCK);
//l_Code_NASTenKeyLock l_tenKeyOn_NumLck(TEN_KEY_ON_NUMLCK);

//MF
l_Code_MFLock MF(MOUSE_ON);
l_Code_MFMouseArrowLock l_arrowOn(ARROW_ON);
l_Code_MFMouseArrowLock l_mouseOn(MOUSE_ON);

// -------------- MOUSE CODES ------------------
m_Mouse_Move m_UpMouse(0,-8,0);                 //negative Y is up

// ================== KEYS =====================
// the 3 l_Key_Layer keys correspond to DataHand's D, K, R keys
//Modes:          normal  NAS           NAS             MF              MF
//                0       1             2               3               4
//Layers:      {normal, 10KeyOff,       10KeyOn,        mouseOn,        arrowOn         };
l_Code * kD[]= {&s_d,   &s_3,           &s_ampersand,   &l_mouseOn,     &l_mouseOn      };
l_Key_Layered k_D(kD);
l_Code * kR[]= {&s_r,   &s_dollar,      &s_up,          &m_UpMouse,     &s_up           };
l_Key_Layered k_R(kR);
l_Code * kK[]= {&s_k,   &s_8,           &s_5,           &l_arrowOn,     &l_arrowOn      };
l_Key_Layered k_K(kK);

l_Key_1 k_tenKeyOff(&l_tenKeyOff);
l_Key_1 k_tenKeyOn(&l_tenKeyOn);

l_Key_1 k_normal(&normal);
l_Key_1 k_shift(&s_shift);
l_Key_1 k_NAS(&l_NAS);
l_Key_1 k_NASLock(&l_NASLock);
l_Key_1 k_MF(&MF);

// ================== LEFT =====================
// -------- LEFT I/O EXPANDER PORTS ------------
c_IOExpanderPort port0_L(0x20, 0);
c_IOExpanderPort port1_L(0x20, 1);

// ------------- LEFT ROW PORTS ----------------
// row: 0   1
// pin: B0  B1

c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0_L, 1<<0 | 1<<1 );

// ------------- LEFT COL PORTS ----------------
// col: 0   1
// pin: A0  A1

c_ColPort_PCA9655E_ActiveHigh colPort1_L(port1_L, 1<<0 | 1<<1 );

// --------------- LEFT ROWS -------------------
//rowL0             index:    0     1
c_Key* const ptrKeysL0[] = { &k_D, &k_R};
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeysL0)/sizeof(ptrKeysL0[0]);
c_Row rowL0(ptrKeysL0, KEYS_L0_COUNT);

//rowL1             index:    0     1
c_Key* const ptrKeysL1[] = { &k_normal, &k_shift };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeysL1)/sizeof(ptrKeysL1[0]);
c_Row rowL1(ptrKeysL1, KEYS_L1_COUNT);

// -------------- LEFT MATRIX ------------------
c_RowPort* ptrsRowPorts_L[] = { &rowPort0_L };
c_ColPort* ptrsColPorts_L[] = { &colPort1_L };
c_Row* const ptrsRowsL[] = { &rowL0, &rowL1 };
c_Matrix matrixL(ptrsRowPorts_L, 1, ptrsColPorts_L, 1, ptrsRowsL, 2);

// ================= RIGHT =====================
// ------------ RIGHT ROW PORTS ----------------
// row: 0   1
// pin: F0  F1

c_RowPort_AVR_ActiveHigh rowPortF_R(DDRF, PORTF, 1<<0 | 1<<1 );

// ------------ RIGHT COL PORTS ----------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR_ActiveHigh colPortC_R(DDRC, PORTC, PINC, 1<<7 );
c_ColPort_AVR_ActiveHigh colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// -------------- RIGHT ROWS -------------------
//rowR0             index:    0     1
c_Key* const ptrKeysR0[] = { &k_K, &k_tenKeyOff, &k_tenKeyOn };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKeysR0)/sizeof(ptrKeysR0[0]);
c_Row rowR0(ptrKeysR0, KEYS_R0_COUNT);

//rowR1             index:    0     1
c_Key* const ptrKeysR1[] = { &k_NAS, &k_NASLock, &k_MF };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKeysR1)/sizeof(ptrKeysR1[0]);
c_Row rowR1(ptrKeysR1, KEYS_R1_COUNT);

// ------------- RIGHT MATRIX ------------------
c_RowPort* ptrsRowPorts_R[] = { &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortC_R, &colPortB_R };
c_Row* const ptrsRowsR[] = { &rowR0, &rowR1 };
c_Matrix matrixR(ptrsRowPorts_R, 1, ptrsColPorts_R, 2, ptrsRowsR, 2);

// =============== KEYBOARD ====================
c_Matrix* const ptrsMatrices[] = { &matrixL, &matrixR };
c_Keybrd keybrd(ptrsMatrices, 2);

// ================== RUN ======================
    keybrd.begin();

    while (true)
    {
        keybrd.scan();
    }
}
