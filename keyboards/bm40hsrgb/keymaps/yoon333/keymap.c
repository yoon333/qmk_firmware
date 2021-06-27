/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "muse.h"
#include "yoon333.h"
#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

#define SYMBOL MO(_SYMBOL)
#define NUMBER MO(_NUMBER)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
                   _________________QWERTY_L1_________________, KC_NO, KC_NO, _________________QWERTY_R1_________________,
                   _________________QWERTY_L2_________________, KC_NO, KC_NO, _________________QWERTY_R2_________________,
                   _________________QWERTY_L3_________________, KC_NO, KC_NO, _________________QWERTY_R3_________________,
     KC_NO, KC_NO, __________________ALPHA_L4_________________,     KC_NO,    __________________ALPHA_R4_________________, KC_NO, KC_NO
  ),
  [_COLEMAK] = LAYOUT_wrapper(
                   ______________COLEMAK_MOD_DH_L1____________, KC_NO, KC_NO, ______________COLEMAK_MOD_DH_R1____________,
                   ______________COLEMAK_MOD_DH_L2____________, KC_NO, KC_NO, ______________COLEMAK_MOD_DH_R2____________,
                   ______________COLEMAK_MOD_DH_L3____________, KC_NO, KC_NO, ______________COLEMAK_MOD_DH_R3____________,
     KC_NO, KC_NO, __________________ALPHA_L4_________________,     KC_NO,    __________________ALPHA_R4_________________, KC_NO, KC_NO
  ),
  [_NAV] = LAYOUT_wrapper(
		   ___________________NAV_L1__________________, KC_NO, KC_NO, ___________________NAV_R1__________________,
     		   ___________________NAV_L2__________________, KC_NO, KC_NO, ___________________NAV_R2__________________,
     		   ___________________NAV_L3__________________, KC_NO, KC_NO, ___________________NAV_R3__________________,
     KC_NO, KC_NO, ___________________NAV_L4__________________,     KC_NO,    ___________________NAV_R4__________________, KC_NO, KC_NO
  ),
  [_NUMBER] = LAYOUT_wrapper(
                   _________________NUMBER_L1_________________, KC_NO, KC_NO, _________________NUMBER_R1_________________,
                   _________________NUMBER_L2_________________, KC_NO, KC_NO, _________________NUMBER_R2_________________,
                   _________________NUMBER_L3_________________, KC_NO, KC_NO, _________________NUMBER_R3_________________,
     KC_NO, KC_NO, _________________NUMBER_L4_________________,     KC_NO,    _________________NUMBER_R4_________________, KC_NO, KC_NO
  ),
  [_SYMBOL] = LAYOUT_wrapper(
                   _________________SYMBOL_L1_________________, KC_NO, KC_NO, _________________SYMBOL_R1_________________,
                   _________________SYMBOL_L2_________________, KC_NO, KC_NO, _________________SYMBOL_R2_________________,
                   _________________SYMBOL_L3_________________, KC_NO, KC_NO, _________________SYMBOL_R3_________________,
     KC_NO, KC_NO, _________________SYMBOL_L4_________________,     KC_NO,    _________________SYMBOL_R4_________________, KC_NO, KC_NO
  ),
  [_ADJUST] = LAYOUT_wrapper(
		   ___________________ALL_NO__________________, KC_NO, KC_NO, _________________ADJUST_R1_________________,
     		   ___________________ALL_NO__________________, KC_NO, KC_NO, _________________ADJUST_R2_________________,
     		   ___________________ALL_NO__________________, KC_NO, KC_NO, _________________ADJUST_R3_________________,
     KC_NO, KC_NO, _________________ADJUST_L4_________________,     KC_NO,    _________________ADJUST_R4_________________, KC_NO, KC_NO
  )
};

