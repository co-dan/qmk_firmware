// Copyright 2022 Takuya Urakawa @hsgw (dm9records.com, 5z6p.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  CONF
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Tap Dance declarations
enum {
  TD_CTRL_TAB,
  TD_SHIFT_CAPS
};

enum custom_keycodes { LED_EN = SAFE_RANGE, ALT_TAB };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

bool is_alt_tab_active = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_GESC,         KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,    KC_PGUP,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        MT(MOD_LCTL, KC_TAB), KC_A,  KC_S,  KC_D,  KC_F,    KC_G,    KC_PGDN,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENTER,
        TD(TD_SHIFT_CAPS),         KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,         KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BACKSLASH,
        KC_TAB,                   KC_LALT, KC_LGUI,  LT(LOWER, KC_BSPC), KC_RCTRL,  KC_SPC, LT(RAISE, KC_SPC), KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT
    ),
    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC, KC_LPRN,   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,  KC_DEL,
        ALT_TAB, _______, _______, _______, _______, _______, KC_RPRN,   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_QUOTE, KC_GRV,
        _______, _______, _______, _______, _______, _______,            KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_SLSH,  _______,
        _______,                   _______, _______, _______, _______,   KC_ENTER, _______, _______, KC_PGDN, KC_PGUP, _______
    ),
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,   KC_6,      KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
        KC_TAB,  _______, KC_MINS, KC_EQL,  KC_BACKSLASH, KC_QUOT, KC_RBRC,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_QUOTE, KC_GRV,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN,            KC_COLN, _______, _______, _______, _______,  KC_BACKSLASH,
        _______,                   _______, _______, _______,  KC_BSPC, _______, _______, _______, KC_VOLD, KC_VOLU,  _______
    ),
    [CONF] = LAYOUT(
        QK_BOOT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        LED_EN,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LED_EN:
            if (record->event.pressed) {
                 lain_enable_leds_toggle();
            }
            return false;
       case ALT_TAB:
           if (record->event.pressed) {
             if (!is_alt_tab_active) {
                 is_alt_tab_active = true;
                 register_code(KC_LGUI);
             }
             register_code(KC_TAB);
           } else {
             unregister_code(KC_TAB);
           }
           break;
        default:
           break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t computed = update_tri_layer_state(state, _LOWER, _RAISE, CONF);
    switch (get_highest_layer(computed)) {
        case _RAISE:
            lain_set_led(1, 1);
            lain_set_led(2, 0);
            break;
        case _LOWER:
            lain_set_led(1, 0);
            lain_set_led(2, 1);
            break;
        case CONF:
            lain_set_led(1, 1);
            lain_set_led(2, 1);
            break;
        default:
            lain_set_led(1, 0);
            lain_set_led(2, 0);
            break;
    }
    return computed;
}

bool led_update_user(led_t led_state) {
    lain_set_led(0, led_state.caps_lock);
    return false;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active && IS_LAYER_OFF(_LOWER)) {
    unregister_code(KC_LGUI);
    is_alt_tab_active = false;
  }
}
