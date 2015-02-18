/* keybrd_DH_2233_bb.ino layout:
 *  D/3/&/mouseOn   R/$/upA/upM/upA K/8/5/arrowOn   tenKeyOff   tenKeyOn
 *  normal          Shift           NAS             NAS Lock    MF Lock
 */
//Arduino library files
#include <Keyboard.h>
#include <Mouse.h>
#include <Wire.h>

//keybrd library files
#include <objects_scancode.h>
#include <m_MouseButton.h>
#include <m_MouseMove.h>
#include <l_Key_1.h>
#include <l_Key_Layered.h>
#include <c_Row_Ex.h>
#include <c_RowWait.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix_MCP23018.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>
#include <l_ShiftManager.h>

//keybrd_Layers library files
#include <l_Code_NormalLock.h>
#include <l_Code_NAS.h>
#include <l_Code_NASLock.h>
#include <l_Code_NASHold.h>
#include <l_Code_NASTenKeyLock.h>
#include <l_Code_MF.h>
#include <l_Code_MFLock.h>
#include <l_Code_MFMouseArrowLock.h>
#include <l_LayerManager.h>

//********* CONIFGURATION VALUES ******
//                    NAS          NAS         MF        MF
enum layers { NORMAL, TEN_KEY_OFF, TEN_KEY_ON, MOUSE_ON, ARROW_ON };

//********** MOUSE CODES *********
m_MouseMove m_UpMouse(0,-8,0);          //negative Y is up

// ********* LAYER CODES **********
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

//static variables
uint8_t l_Code_NAS::resumeLayer = TEN_KEY_OFF;
bool l_Code_MF::pressed = false;

//********** KEYS ***********
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

//********** LEFT ROWS **********
//rowL0             index:    0     1
c_Key* const ptrKeysL0[] = { &k_D, &k_R, &k_K };
const uint8_t KEYS_L0_COUNT = sizeof(ptrKeysL0)/sizeof(ptrKeysL0[0]);
c_Row_Ex rowL0(ptrKeysL0, KEYS_L0_COUNT);

//rowL1             index:    0     1
c_Key* const ptrKeysL1[] = { &k_normal, &k_shift, &k_NAS };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKeysL1)/sizeof(ptrKeysL1[0]);
c_Row_Ex rowL1(ptrKeysL1, KEYS_L1_COUNT);

//********** RIGHT ROWS **********
//rowR0             index:    0     1
c_Key* const ptrKeysR0[] = { &k_tenKeyOff, &k_tenKeyOn };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKeysR0)/sizeof(ptrKeysR0[0]);
c_Row_Ex rowR0(ptrKeysR0, KEYS_R0_COUNT);

//rowR1             index:    0     1
c_Key* const ptrKeysR1[] = { &k_NASLock, &k_MF };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKeysR1)/sizeof(ptrKeysR1[0]);
c_Row_Ex rowR1(ptrKeysR1, KEYS_R1_COUNT);

//********** MATRICES ***********
//matrixL
c_Row_Ex* const ptrsRowsL[] = { &rowL0, &rowL1 };
const uint8_t ROWS_L_COUNT = sizeof(ptrsRowsL)/sizeof(ptrsRowsL[0]);
c_Matrix_MCP23018 matrixL(ptrsRowsL, ROWS_L_COUNT);

//matrixR
c_Row_Ex* const ptrsRowsR[] = { &rowR0, &rowR1 };
const uint8_t ROWS_R_COUNT = sizeof(ptrsRowsR)/sizeof(ptrsRowsR[0]);
c_Matrix_Teensy2 matrixR(ptrsRowsR, ROWS_R_COUNT);

c_RowWait rowWait(ROWS_L_COUNT + ROWS_R_COUNT, 10);
c_RowWait& c_Row_Ex::refRowWait = rowWait;

//********** KEYBOARD ***********
c_Matrix* const ptrsMatrices[] = { &matrixL, &matrixR };
c_Keybrd keybrd(ptrsMatrices, 2);

//********** MANAGERS ***********
l_Code_Shift* const ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager(NORMAL);
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ********** RUN ***********
void setup() { keybrd.begin(); }
void loop() { keybrd.scan(); }
