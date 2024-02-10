// Copyright 2021 Taeyoon Kim (@partrita)
// SPDX-License-Identifier: GPL-2.0-or-later
// /*
//   Set any config.h overrides for your specific keymap here.
//   See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
// */
#pragma once

#define RGBLIGHT_LAYERS 

#define NO_AUTO_SHIFT_ALPHA 1

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define LONG_TAPPING_TERM 490
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

#define COMBO_COUNT 1

//disable broken animations
#ifdef RGB_MATRIX_ENABLE
#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_BREATHING
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_VAL
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_CYCLE_ALL
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    undef RGB_MATRIX_DEFAULT_MODE
// #    define RGBLIGHT_HUE_STEP 20
#endif
