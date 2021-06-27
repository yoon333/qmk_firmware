/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

//TODO: get RGB per layer working with customized key code RGB_LYR
enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};
enum layers {
  _ZERO,
  _ONE,
  SL_RGB, //special layer triggered by tap dance
};

enum {
  TD_EEP_MO0,
  TD_MO1_RGB,
};

void td_eep_mo0_reset(qk_tap_dance_state_t *state, void *user_data);
void td_mo1_rgb_finished(qk_tap_dance_state_t *state, void *user_data);
void td_mo1_rgb_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_EEP_MO0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, NULL, td_eep_mo0_reset),
  [TD_MO1_RGB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mo1_rgb_finished, td_mo1_rgb_reset),
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Media Next/Prev |          | Knob 2:  Vol Up/Dn |
        | Press: Media Play/Pause | Home     | Press:        Mute |
        |                Numpad 1 | Numpad 2 |           Numpad 3 |
        |                Numpad 4 | Numpad 5 |           Numpad 6 |
     */
    [_ZERO] = LAYOUT(
        KC_MPLY, TD(TD_MO1_RGB), KC_MUTE,
        KC_KP_1,        KC_KP_2, KC_KP_3,
        KC_KP_4,        KC_KP_5, KC_KP_6
    ),
    /*
        | Knob 1: Media FF/RW |          | Knob 2: Media Vol Up/Dn |
        | Press:   Media Stop |      N/A | Press:       Media Mute |
        |            Numpad 7 | Numpad 8 |                Numpad 9 |
        |            Numpad 0 | Numpad + |                Numpad - |
     */
    [_ONE] = LAYOUT(
        KC_MSTP, TD(TD_MO1_RGB),     KC_STOP,
        KC_KP_7,        KC_KP_8,     KC_KP_9,
        KC_KP_0,     KC_KP_PLUS, KC_KP_MINUS
    ),
    /*
        | Knob 1: RGB Mode +/- |            | Knob 2: RGB Sat Inc/Dec |
        | Press:    RGB Toggle |  EEP Reset | Press:        RGB Layer |
        |             RGB Hue+ |   RGB Sat+ |		    RGB Val+ |
        |             RGB Hue- |   RGB Sat- |                RGB Val- |
     */
    [SL_RGB] = LAYOUT(
         RGB_TOG, TD(TD_EEP_MO0),  KC_NO,
         RGB_HUI,       RGB_SAI, RGB_VAI,
         RGB_HUD,       RGB_SAD, RGB_VAD
    ),

};

const uint16_t PROGMEM encoders[][2][2] = {
    [_ZERO] =   {{KC_MNXT, KC_MPRV}, {KC_VOLU, KC_VOLD}},
    [_ONE]  =   {{KC_MFFD, KC_MRWD}, {KC_VOLU, KC_VOLD}},
    [SL_RGB]  = {{RGB_MOD, RGB_RMOD}, {KC_VOLU, KC_VOLD}},
    // RGB defined in encoder_update_user()
};

void td_eep_mo0_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
	tap_code16(EEP_RST);
    } else {
        layer_off(SL_RGB);
    }
}


void td_mo1_rgb_finished(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        layer_on(_ONE);
    }
}

void td_mo1_rgb_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1) {
        layer_off(_ONE);
    } else {
	layer_on(SL_RGB);
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    switch(layer) {
    case SL_RGB:
        if(index == _LEFT) {
            if(clockwise) {
#ifdef RGB_LIGHT_ENABLE
                rgblight_increase();
#elif RGB_MATRIX_ENABLE
		rgb_matrix_step();
#endif
            } else {
#ifdef RGB_LIGHT_ENABLE
                rgblight_decrease();
#elif RGB_MATRIX_ENABLE
		rgb_matrix_step_reverse();
#endif
            }
        } else if (index == _RIGHT) {
           //TODO: handle RGB layer knobs
            tap_code16(pgm_read_word(&encoders[layer][index][clockwise]));
        }
        break;
    default:
        tap_code16(pgm_read_word(&encoders[layer][index][clockwise]));
    }
}
