#pragma once

#define ENCODER_DIRECTION_FLIP

#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING // Only have Breathing Animation

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#endif
#define TAPPING_TERM 175
