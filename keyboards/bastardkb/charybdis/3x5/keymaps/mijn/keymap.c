/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _CONTROL,
    /* LAYER_BASE = 0, */
    /* LAYER_FUNCTION, */
    /* LAYER_NAVIGATION, */
    /* LAYER_MEDIA, */
    LAYER_POINTER,
    /* LAYER_NUMERAL, */
    /* LAYER_SYMBOLS, */
};

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define KC_MTCT MT(MOD_LCTL, KC_TAB) 
#define MT_C(X) MT(MOD_LCTL, X)
#define MT_A(X) MT(MOD_LALT, X)
#define MT_G(X) MT(MOD_LGUI, X)
#define MT_S(X) MT(MOD_LSFT, X)
#define _CTL(X) LT(_CONTROL, X)
#define _L_PTR(KC) LT(LAYER_POINTER, KC)

#define SPC_RAISE LT(_RAISE, KC_SPC)
#define BSP_LOWER LT(_LOWER, KC_BSPC)

const uint16_t PROGMEM test_combo1[] = {MT_C(KC_F), MT_C(KC_J), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, CW_TOGG)
};



#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
             MT_G(KC_ESC), BSP_LOWER, BSP_LOWER, MT(KC_RALT,KC_ENTER), SPC_RAISE

/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ XXXXXXX, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_RCTL, KC_RSFT, KC_RGUI, XXXXXXX



#define LAYOUT_LAYER_LOWER                                                                      \
    KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR,  KC_MINS, KC_EQL, \
    KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,    KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_DQT, \
    _______________DEAD_HALF_ROW_______________,   KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS, \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX

#define LAYOUT_LAYER_RAISE                                                                        \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     \
    KC_GRV, KC_MINS, KC_EQL,  KC_BSLS,  KC_DQT,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOTE, \
    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN,   _______________DEAD_HALF_ROW_______________,   \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX

#define LAYOUT_LAYER_CONTROL                                                                    \
    KC_GRV, KC_TRNS, KC_TRNS, KC_BTN3,  KC_PGUP,   _______________DEAD_HALF_ROW_______________, \
    KC_TAB, KC_TRNS, KC_BTN2, KC_BTN1,  KC_PGDN,   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,   _______________DEAD_HALF_ROW_______________, \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX


/** \brief Mouse emulation and pointer functions. */
#define LAYOUT_LAYER_POINTER                                                                  \
    XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD, S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, \
    ______________HOME_ROW_GACS_L______________, ______________HOME_ROW_GACS_R______________, \
    _______, DRGSCRL, SNIPING,  EE_CLR, QK_BOOT, QK_BOOT,  EE_CLR, SNIPING, DRGSCRL, _______, \
                      KC_BTN2, KC_BTN1, KC_BTN3, KC_BTN3, KC_BTN1


/**
 * \brief Add Home Row mod to a layout.
 *
 * Expects a 10-key per row layout.  Adds support for GACS (Gui, Alt, Ctl, Shift)
 * home row.  The layout passed in parameter must contain at least 20 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     HOME_ROW_MOD_GACS(LAYER_ALPHAS_QWERTY)
 */
#define _HOME_ROW_MOD_GACS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
      _CTL(L10), MT_G(L11), MT_S(L12), MT_C(L13),        L14,  \
             R15,  MT_C(R16), MT_S(R17), MT_G(R18), _CTL(R19), \
      __VA_ARGS__
#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)

/**
 * \brief Add pointer layer keys to a layout.
 *
 * Expects a 10-key per row layout.  The layout passed in parameter must contain
 * at least 30 keycodes.
 *
 * This is meant to be used with `LAYER_ALPHAS_QWERTY` defined above, eg.:
 *
 *     POINTER_MOD(LAYER_ALPHAS_QWERTY)
 */
#define _POINTER_MOD(                                                  \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                  \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                  \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,                  \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04,  \
             R05,         R06,         R07,         R08,         R09,  \
             L10,         L11,         L12,         L13,         L14,  \
             R15,         R16,         R17,         R18,         R19,  \
      _L_PTR(L20),        L21,         L22,         L23,         L24,  \
             R25,         R26,         R27,         R28,  _L_PTR(R29), \
      __VA_ARGS__
#define POINTER_MOD(...) _POINTER_MOD(__VA_ARGS__)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))
  ),
  [_LOWER] = LAYOUT_wrapper(LAYOUT_LAYER_LOWER),
  [_RAISE] = LAYOUT_wrapper(LAYOUT_LAYER_RAISE),
  [_CONTROL] = LAYOUT_wrapper(LAYOUT_LAYER_CONTROL),
  [LAYER_POINTER] = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_G(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case MT_S(KC_D):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case MT_C(KC_F):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case MT_C(KC_J):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case MT_S(KC_K):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case MT_G(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}


#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
