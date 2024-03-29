/* test 2 - keybrd_multi-layer_2223_bb_Teensy2_PCA9655E_ActiveHigh.ino layout:
      Left Matrix             Rigth Matrix
      -----------------       -----------------
      capsLck_L   b @         c #    d $    capsLck_R
      alpha       sym         00     null   shift

letter b should print lowercase "b" even when shift is pressed
letter d should print uppercase "D" even when shift is not pressed
*/
// ################# GLOBAL ####################
// ================ INCLUDES ===================
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <l_Code_Shift>
#include <l_ShiftManager.h>

#include <l_Code_SNS.h>
#include <l_Code_SS.h>
#include <l_Code_SNS_00.h>
#include <l_Code_LckLED.h>
#include <objects_scancode.h>

#include <l_Key_1.h>
#include <l_Key_Layered.h>

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

// ============= STATIC MEMBERS ================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

l_Code_Shift* ptrsShifts[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShifts, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager;
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ################## MAIN #####################
void setup() {}
void loop()
{
// ================= CODES =====================
// --------------- SCAN CODES ------------------
l_Code_SNS sns_b(KEY_B);                        //scancode not shifted
l_Code_SS  ss_d(KEY_D);                         //scancode shifted
l_Code_SNS_00 sns_00;                           //double zero

// -------------- LAYER CODES ------------------
l_Code_Layer l_alpha(0);
l_Code_Layer l_sym(1);

// ================== LEFT =====================
// ------------- LEFT ROW PORTS ----------------
c_IOExpanderPort port0_L(0x20, 0);
c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0_L, 1<<0 | 1<<1 );

// ------------- LEFT COL PORTS ----------------
c_IOExpanderPort port1_L(0x20, 1);
c_ColPort_PCA9655E_ActiveHigh colPort1_L(port1_L, 1<<0 | 1<<1 );

// ------------- LEFT LED CODES ----------------
c_LED_PCA9655E capsLck_LED_L(port0_L, 1<<7);
l_Code_LckLED l_capsLck_L(KEY_CAPS_LOCK, capsLck_LED_L);

// --------------- LEFT KEYS -------------------
//row_L0                   {alpha        sym    };
l_Key_1 k_L00(&l_capsLck_L);

l_Code * prtsCodes_L01[] = {&sns_b,      &s_at  };
l_Key_Layered k_L01(prtsCodes_L01);

//row_L1
l_Key_1 k_L10(&l_alpha);

l_Key_1 k_L11(&l_sym);

// --------------- LEFT ROWS -------------------
//row_L0
c_Key* ptrKey_L0[] = { &k_L00, &k_L01 };
uint8_t KEYS_L0_COUNT = sizeof(ptrKey_L0)/sizeof(ptrKey_L0[0]);
c_Row row_L0(ptrKey_L0, KEYS_L0_COUNT);

//row_L1
c_Key* ptrKey_L1[] = { &k_L10, &k_L11 };
uint8_t KEYS_L1_COUNT = sizeof(ptrKey_L1)/sizeof(ptrKey_L1[0]);
c_Row row_L1(ptrKey_L1, KEYS_L1_COUNT);

// -------------- LEFT MATRIX ------------------
c_RowPort* ptrsRowPorts_L[] = { &rowPort0_L };
c_ColPort* ptrsColPorts_L[] = { &colPort1_L };
c_Row* ptrsRows_L[] = { &row_L0, &row_L1 };
c_Matrix matrix_L(ptrsRowPorts_L, 1, ptrsColPorts_L, 1, ptrsRows_L, 2);

// ================= RIGHT =====================
// ------------ RIGHT ROW PORTS ----------------
c_RowPort_AVR_ActiveHigh rowPortF_R(DDRF, PORTF, 1<<0 | 1<<1 );

// ------------ RIGHT COL PORTS ----------------
c_ColPort_AVR_ActiveHigh colPortC_R(DDRC, PORTC, PINC, 1<<7 );
c_ColPort_AVR_ActiveHigh colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// ------------ RIGHT LED CODES ----------------
c_LED_AVR capsLck_LED_R(PORTB, 1<<3);
l_Code_LckLED l_capsLck_R(KEY_CAPS_LOCK, capsLck_LED_R);

// -------------- RIGHT KEYS -------------------
//row_R0                   {alpha       sym        };
l_Code * prtsCodes_R00[] = {&s_c,       &s_number  };
l_Key_Layered k_R00(prtsCodes_R00);

l_Code * prtsCodes_R01[] = {&ss_d,      &s_dollar  };
l_Key_Layered k_R01(prtsCodes_R01);

l_Key_1 k_R02(&l_capsLck_R);

//row_R1
l_Key_1 k_R10(&sns_00);
l_Key_1 k_R11(&code_null);
l_Key_1 k_R12(&s_shift);

// -------------- RIGHT ROWS -------------------
//row_R0
c_Key* ptrKey_R0[] = { &k_R00, &k_R01, &k_R02 };
uint8_t KEYS_R0_COUNT = sizeof(ptrKey_R0)/sizeof(ptrKey_R0[0]);
c_Row row_R0(ptrKey_R0, KEYS_R0_COUNT);

//row_R1
c_Key* ptrKey_R1[] = { &k_R10, &k_R11, &k_R12 };
uint8_t KEYS_R1_COUNT = sizeof(ptrKey_R1)/sizeof(ptrKey_R1[0]);
c_Row row_R1(ptrKey_R1, KEYS_R1_COUNT);

// ------------- RIGHT MATRIX ------------------
c_RowPort* ptrsRowPorts_R[] = { &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortC_R, &colPortB_R };
c_Row* ptrsRows_R[] = { &row_R0, &row_R1 };
c_Matrix matrix_R(ptrsRowPorts_R, 1, ptrsColPorts_R, 2, ptrsRows_R, 2);

// =============== KEYBOARD ====================
c_Matrix* ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

// ================== RUN ======================
    keybrd.begin();

    while (true)
    {
        keybrd.scan();
    }
}
