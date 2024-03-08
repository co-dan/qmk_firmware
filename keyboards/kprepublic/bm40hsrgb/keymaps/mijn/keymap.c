// Copyright 2021 Taeyoon Kim (@partrita)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _CONTROL,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define KC_MTCT MT(MOD_LCTL, KC_TAB) 
#define MT_C(X) MT(MOD_LCTL, X)
#define MT_A(X) MT(MOD_LALT, X)
#define MT_G(X) MT(MOD_LGUI, X)
#define MT_S(X) MT(MOD_LSFT, X)


const uint16_t PROGMEM test_combo1[] = {MT_C(KC_F), MT_C(KC_J), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, CW_TOGG)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
     KC_Q,       KC_W,       KC_E,       KC_R, KC_T,                KC_PGUP, KC_VOLU,     KC_Y,        KC_U,       KC_I,       KC_O,    KC_P, 
     LT(_CONTROL,KC_A), MT_G(KC_S), MT_S(KC_D), MT_C(KC_F), KC_G,   KC_PGDN, KC_VOLD,     KC_H,  MT_C(KC_J), MT_S(KC_K), MT_G(KC_L), LT(_CONTROL, KC_SCLN),
     KC_Z,       KC_X,       KC_C,       KC_V, KC_B,                KC_END,   KC_DEL,     KC_N,        KC_M,    KC_COMM,     KC_DOT, KC_SLSH,
     KC_NO, KC_NO, KC_NO, MT_G(KC_ESC), LT(_LOWER,KC_BSPC), KC_SPC, LT(_RAISE,KC_SPC),  MT(KC_RALT,KC_ENTER), KC_NO, KC_NO, KC_NO
      ),
  [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
     KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,   KC_NO, KC_NO,     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, 
     KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,    KC_NO, KC_NO,     KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,KC_DQT,
     _______, _______, _______, _______, _______,   KC_NO, KC_NO,     KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS,
     _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______
      ),
  [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_NO, KC_NO,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
     KC_GRV, KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT, KC_NO, KC_NO,    KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,KC_QUOTE,
     KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN, KC_NO, KC_NO, _______, _______, _______, _______, _______, 
     _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______
      ),
  [_CONTROL] = LAYOUT_ortho_4x12_1x2uC(
     KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,  _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______
      ),
  [_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
     QK_BOOT, _______, RGB_HUI, RGB_MOD, RGB_TOG, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
     _______, _______, _______, _______, _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
     _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______,
     _______, _______, _______, _______, _______,      _______,       _______, _______, _______, _______, _______
      ),
};

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



// color by layer
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _QWERTY:
            rgblight_mode_noeeprom(RGB_MATRIX_RAINBOW_BEACON);
            rgblight_setrgb(200,10,10);
            break;
        case _LOWER:
            rgblight_setrgb(10,10,200);
            rgblight_mode_noeeprom(RGB_MATRIX_HUE_PENDULUM);
            break;
        case _RAISE:
            rgblight_setrgb(10,200,10);
            rgblight_mode_noeeprom(RGB_MATRIX_HUE_PENDULUM);
            break;
        default:
          rgblight_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_WIDE);
          break;
    }  
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);;
}

/*void housekeeping_task_user(void) {
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case _QWERTY:
          //rgblight_setrgb(200,10,10);
            rgblight_mode(RGB_MATRIX_RAINBOW_BEACON);
            break;
        case _LOWER:
          //rgblight_setrgb(10,10,200);
            rgblight_mode(RGB_MATRIX_HUE_PENDULUM);
            break;
        case _RAISE:
          //rgblight_setrgb(10,200,10);
            rgblight_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
            break;
        default:
          rgblight_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
          break;
    }
    return;
    }*/
