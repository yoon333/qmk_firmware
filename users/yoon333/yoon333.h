#pragma once

//layer enums
enum custom_layer {
  _QWERTY,
  _COLEMAK,
  _NAV,
  _NUMBER,
  _SYMBOL,
  _ADJUST
};

// common key definitions
#define ___________________ALL_NO__________________       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO

#define _________________QWERTY_L1_________________       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
#define _________________QWERTY_L2_________________       LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G
#define _________________QWERTY_L3_________________       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B

#define _________________QWERTY_R1_________________       KC_Y,         KC_U,         KC_I,         KC_O,         KC_P
#define _________________QWERTY_R2_________________       KC_H,         RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN)
#define _________________QWERTY_R3_________________       KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH
 

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B
#define ______________COLEMAK_MOD_DH_L2____________       LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,         KC_X,         KC_C,         KC_D,         KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,         KC_L,         KC_U,         KC_Y,         KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,         RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O)   
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLASH

#define __________________ALPHA_L4_________________       LT(_NAV, KC_ESC), LT(_NUMBER, KC_TAB), KC_SPC
#define __________________ALPHA_R4_________________       KC_BSPC,          LT(_SYMBOL, KC_ENT), LT(_NAV, KC_DEL)

#define ___________________NAV_L1__________________       KC_NO,        KC_INS,       KC_PGUP,      KC_DEL,       KC_NO
#define ___________________NAV_L2__________________       KC_NO,        KC_HOME,      KC_PGDN,      KC_END,       KC_NO
#define ___________________NAV_L3__________________       ___________________ALL_NO__________________

#define ___________________NAV_R1__________________       KC_NO,        KC_NO,        KC_UP,        KC_NO,        KC_NO
#define ___________________NAV_R2__________________       KC_NO,        KC_LEFT,      KC_DOWN,      KC_RIGHT,     KC_NO
#define ___________________NAV_R3__________________       ___________________ALL_NO__________________

#define ___________________NAV_L4__________________       _______,      KC_HANJ,      KC_NO
#define ___________________NAV_R4__________________       KC_NO,        KC_HAEN,      _______


#define _________________NUMBER_L1_________________       KC_1,         KC_2,         KC_3,         KC_4,         KC_5
#define _________________NUMBER_L2_________________       KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5   
#define _________________NUMBER_L3_________________       KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_F11

#define _________________NUMBER_R1_________________       KC_6,         KC_7,         KC_8,         KC_9,         KC_0
#define _________________NUMBER_R2_________________       KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10   
#define _________________NUMBER_R3_________________       KC_F12,       KC_NO,        KC_NO,        KC_NO,        KC_NO

#define _________________NUMBER_L4_________________       KC_NO,        _______,      KC_NO
#define _________________NUMBER_R4_________________       KC_NO,        MO(_ADJUST),  KC_NO


#define _________________SYMBOL_L1_________________       KC_EXLM,      KC_QUES,      KC_UNDS,      KC_AT,        KC_HASH
#define _________________SYMBOL_L2_________________       KC_GRV,       KC_LT,        KC_LBRC,      KC_LCBR,      KC_LPRN
#define _________________SYMBOL_L3_________________       KC_EQL,       KC_PLUS,      KC_MINS,      KC_ASTR,      KC_SLSH

#define _________________SYMBOL_R1_________________       KC_DLR,       KC_CIRC,      KC_SCLN,      KC_COLN,      KC_DQUO
#define _________________SYMBOL_R2_________________       KC_RPRN,      KC_RCBR,      KC_RBRC,      KC_GT,        KC_QUOT
#define _________________SYMBOL_R3_________________       KC_BSLS,      KC_PERC,      KC_AMPR,     KC_PIPE,      KC_TILD

#define _________________SYMBOL_L4_________________       KC_NO,        MO(_ADJUST),  KC_NO
#define _________________SYMBOL_R4_________________       KC_NO,        _______,      KC_NO


#define _________________ADJUST_R1_________________       KC_NO,        RGB_MOD,      RGB_HUI,      RGB_SAI,      RGB_VAI  
#define _________________ADJUST_R2_________________       KC_NO,        RGB_TOG,      RGB_HUD,      RGB_SAD,      RGB_VAD 
#define _________________ADJUST_R3_________________       KC_NO,        KC_NO,        KC_NO,        DF(_COLEMAK), DF(_QWERTY)

#define _________________ADJUST_L4_________________       RESET,        _______,      KC_NO
#define _________________ADJUST_R4_________________       KC_NO,        _______,      DEBUG

