/* keybrd_multi-layer_2223_bb_PCA9655E_ActiveHigh.ino layout:
      Left Matrix             Rigth Matrix
      -----------------       -----------------
      capsLck_L   b @ 7       c # 8       d $ 9
      alpha       sym         fn          capsLck_R
*/
// ========== INCLUDES =========
//Arduino library files
#include <Keyboard.h>
#include <Wire.h>

//keybrd library files
#include <objects_scancode.h>
#include <l_ShiftManager.h>
#include <l_Key_Layered.h>
#include <l_Key_1.h>
#include <c_Row.h>
#include <c_RowPort_AVR_ActiveHigh.h>
#include <c_ColPort_AVR_ActiveHigh.h>
#include <c_RowPort_PCA9655E_ActiveHigh.h>
#include <c_ColPort_PCA9655E_ActiveHigh.h>
#include <c_Matrix_Teensy2.h>
#include <c_Matrix.h>
#include <c_Keybrd.h>

//keybrd_Layers library files
#include <l_Code_Layer.h>
#include <l_LayerManager.h>

#include "c_IOExpanderPort.h"
#include "c_LED_AVR.h"
#include "c_LED_PCA9655E.h"
#include "l_Code_LckLED.h"

// =============== STATIC MEMBERS =====================
c_RowWait rowWait(4, 10);
c_RowWait& c_Row::refRowWait = rowWait;

l_Code_Shift* const ptrsShift[] = { &s_shift };
l_ShiftManager shiftManager(ptrsShift, 1);
l_ShiftManager& l_Code::refShiftManager = shiftManager;

l_LayerManager layerManager;
l_LayerManager&  l_Code_Layer::refLayerManager = layerManager;
l_LayerManager& l_Key_Layered::refLayerManager = layerManager;

// ############### MAIN #####################
void setup() {}
void loop()
{
// ========= CODES ==========
// ------------ LAYER CODES -------------
l_Code_Layer l_alpha(0);
l_Code_Layer l_sym(1);
l_Code_Layer l_fn(2);

// =============== LEFT =====================
// -------- LEFT I/O EXPANDER PORTS ---------
c_IOExpanderPort port0_L(0x20, 0);
c_IOExpanderPort port1_L(0x20, 1);

// --------------- LEFT ROW PORTS -------------
// row: 0   1
// pin: B0  B1

c_RowPort_PCA9655E_ActiveHigh rowPort0_L(port0_L, 1<<0 | 1<<1 );

// --------------- LEFT COL PORTS -------------
// col: 0   1
// pin: A0  A1

c_ColPort_PCA9655E_ActiveHigh colPort1_L(port1_L, 1<<0 | 1<<1 );

// ------------ LEFT LED CODES -------------
c_LED_PCA9655E capsLck_LED_L(port0_L, 1<<7);   //blue top row port
l_Code_LckLED l_capsLck_L(KEY_CAPS_LOCK, capsLck_LED_L);

// ---------- LEFT KEYS -----------
//row_L0                   {alpha        sym             fn    };
//l_Code * prtsCodes_L00[] = {&s_a,        &s_exclamation, &s_6  };
//l_Key_Layered k_L00(prtsCodes_L00);
l_Key_1 k_L00(&l_capsLck_L);

l_Code * prtsCodes_L01[] = {&s_b,        &s_at,          &s_7  };
l_Key_Layered k_L01(prtsCodes_L01);

//row_L1
l_Key_1 k_L10(&l_alpha);

l_Key_1 k_L11(&l_sym);

// ---------- LEFT ROWS ----------
//row_L0
c_Key* const ptrKey_L0[] = { &k_L00, &k_L01 };
const uint8_t KEYS_L0_COUNT = sizeof(ptrKey_L0)/sizeof(ptrKey_L0[0]);
c_Row rowL0(ptrKey_L0, KEYS_L0_COUNT);

//row_L1
c_Key* const ptrKey_L1[] = { &k_L10, &k_L11 };
const uint8_t KEYS_L1_COUNT = sizeof(ptrKey_L1)/sizeof(ptrKey_L1[0]);
c_Row rowL1(ptrKey_L1, KEYS_L1_COUNT);

// ---------- LEFT MATRIX -----------
c_Row* const ptrsRow_L[] = { &rowL0, &rowL1 };
c_RowPort* ptrsRowPorts_L[] = { &rowPort0_L };
c_ColPort* ptrsColPorts_L[] = { &colPort1_L };
c_Matrix matrix_L(ptrsRowPorts_L, 1, ptrsColPorts_L, 1, ptrsRow_L, 2);

// =============== RIGHT ====================
// --------------- RIGHT ROW PORTS -------------
// row: 0   1
// pin: F0  F1

c_RowPort_AVR_ActiveHigh rowPortF_R(DDRF, PORTF, 1<<0 | 1<<1 );

// --------------- RIGHT COL PORTS -------------
// col: 0   1
// pin: B0  B1

c_ColPort_AVR_ActiveHigh colPortB_R(DDRB, PORTB, PINB, 1<<0 | 1<<1 );

// ------------ RIGHT LED CODES -------------
c_LED_AVR capsLck_LED_R(PORTB, 1<<3);
l_Code_LckLED l_capsLck_R(KEY_CAPS_LOCK, capsLck_LED_R);

// ---------- RIGHT KEYS -----------
//row_R0                   {alpha        sym             fn    };
l_Code * prtsCodes_R00[] = {&s_c,        &s_number,      &s_8  };
l_Key_Layered k_R00(prtsCodes_R00);

l_Code * prtsCodes_R01[] = {&s_d,        &s_dollar,      &s_9  };
l_Key_Layered k_R01(prtsCodes_R01);

//row_R1
l_Key_1 k_R10(&l_capsLck_R);
l_Key_1 k_R11(&l_fn);

// ---------- RIGHT ROWS ----------
//row_R0
c_Key* const ptrKey_R0[] = { &k_R00, &k_R01 };
const uint8_t KEYS_R0_COUNT = sizeof(ptrKey_R0)/sizeof(ptrKey_R0[0]);
c_Row rowR0(ptrKey_R0, KEYS_R0_COUNT);

//row_R1
c_Key* const ptrKey_R1[] = { &k_R11, &k_R10 };
const uint8_t KEYS_R1_COUNT = sizeof(ptrKey_R1)/sizeof(ptrKey_R1[0]);
c_Row rowR1(ptrKey_R1, KEYS_R1_COUNT);

// ---------- RIGHT MATRIX -----------
c_Row* const ptrsRow_R[] = { &rowR0, &rowR1 };
c_RowPort* ptrsRowPorts_R[] = { &rowPortF_R };
c_ColPort* ptrsColPorts_R[] = { &colPortB_R };
c_Matrix matrix_R(ptrsRowPorts_R, 1, ptrsColPorts_R, 1, ptrsRow_R, 2);

// ========== KEYBOARD ===========
c_Matrix* const ptrsMatrix[] = { &matrix_L, &matrix_R };
c_Keybrd keybrd(ptrsMatrix, 2);

// ========== RUN ===========
    keybrd.begin();

    while (true)
    {
        keybrd.scan();
    }
}
