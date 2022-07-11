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
};

enum custom_keycodes { LED_EN = SAFE_RANGE };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
  [TD_CTRL_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_TAB),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
        KC_GESC,         KC_Q,  KC_W,  KC_E,  KC_R,    KC_T,    KC_LBRC,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        TD(TD_CTRL_TAB), KC_A,  KC_S,  KC_D,  KC_F,    KC_G,    KC_RBRC,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENTER,
        KC_LSFT,         KC_Z,  KC_X,  KC_C,  KC_V,    KC_B,               KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_BACKSLASH,
        KC_LCTL,                   KC_LALT, KC_LGUI,  LOWER, KC_SPC,    KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT
    ),
    [_LOWER] = LAYOUT(
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DEL,
        _______, LED_EN,  _______, _______, _______, _______, _______,   _______, _______, KC_LBRACKET, KC_RBRACKET, KC_QUOTE, _______,
        _______, QK_BOOT, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______,
        _______,                   _______, _______, _______, _______,   _______, _______, _______, KC_PGDN, KC_PGUP, _______
    ),
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, KC_LBRACKET, KC_RBRACKET, KC_QUOTE, _______,
        _______, _______, _______, _______, _______, _______,            KC_PSCR, _______, _______, _______, _______,  _______,
        _______,                   _______, _______, _______, _______,   _______, _______, _______, KC_VOLD, KC_VOLU,  _______
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
        default:
            break;
    }
    return true;
}

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t computed = update_tri_layer_state(state, _LOWER, _RAISE, CONF);
    switch (get_highest_layer(computed)) {
        case _RAISE:
            lain_set_led(1, 1);
            lain_set_led(2, 0);
            break;b
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

/* bool led_update_user(led_t led_state) { */
/*     lain_set_led(0, led_state.caps_lock); */
/*     return false; */
/* } */
