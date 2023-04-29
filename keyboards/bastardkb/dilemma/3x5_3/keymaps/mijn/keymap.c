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
#define _CTL(X) LT(_CONTROL, X)

const uint16_t PROGMEM test_combo1[] = {MT_C(KC_F), MT_C(KC_J), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, CW_TOGG)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
  // ╭────────────────────────────────────────────────────╮     ╭─────────────────────────────────────────────────────────╮
      KC_Q,             KC_W,       KC_E,       KC_R, KC_T,      KC_Y,        KC_U,       KC_I,       KC_O,    KC_P,
  // ├────────────────────────────────────────────────────┤     ├─────────────────────────────────────────────────────────┤
      _CTL(KC_A), MT_G(KC_S), MT_S(KC_D), MT_C(KC_F), KC_G,      KC_H,  MT_C(KC_J), MT_S(KC_K), MT_G(KC_L),  _CTL(KC_SCLN),
  // ├────────────────────────────────────────────────────┤     ├─────────────────────────────────────────────────────────┤
      KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_N,        KC_M,    KC_COMM,     KC_DOT, KC_SLSH,
  //              ────────────────────────────────────────┤     ├────────────────────────────────────────
                KC_MUTE,  MT_G(KC_ESC), LT(_LOWER,KC_BSPC),      LT(_RAISE,KC_SPC),  MT(KC_RALT,KC_ENTER), KC_MUTE
  ),

  [_RAISE] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮          ╭─────────────────────────────────────────────╮
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
       KC_GRV, KC_MINS, KC_EQL,  KC_BSLS, KC_DQT,             KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,KC_QUOTE,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
      KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤          ├─────────────────────────────────────────────╯
         KC_MUTE,  MT_G(KC_ESC), LT(_LOWER,KC_BSPC),           LT(_RAISE,KC_SPC),  MT(KC_RALT,KC_ENTER), KC_MUTE
  //                    ───────────────────────────╯          ╰──────────────────────────
  ),

  [_LOWER] = LAYOUT_split_3x5_3(                                
  // ╭─────────────────────────────────────────────╮          ╭─────────────────────────────────────────────╮
      KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
      KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,              KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,KC_QUOTE,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS,
  // ╰─────────────────────────────────────────────┤          ├─────────────────────────────────────────────╯
         KC_MUTE,  MT_G(KC_ESC), LT(_LOWER,KC_BSPC),           LT(_RAISE,KC_SPC),  MT(KC_RALT,KC_ENTER), KC_MUTE
  //                    ───────────────────────────╯          ╰──────────────────────────
  ),

  [_ADJUST] = LAYOUT_split_3x5_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,  KC_F11,     KC_F12, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                            KC_A, _______, KC_LSFT,     KC_SPC, _______,    KC_A
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

  [_CONTROL] = LAYOUT_split_3x5_3(                                
  // ╭─────────────────────────────────────────────╮          ╭─────────────────────────────────────────────╮
      KC_GRV, KC_TRNS, KC_TRNS, KC_BTN2, KC_PGUP,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
      KC_TAB, KC_TRNS, KC_TRNS, KC_BTN1, KC_PGDN,               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
  // ├─────────────────────────────────────────────┤          ├─────────────────────────────────────────────┤
      KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  // ╰─────────────────────────────────────────────┤          ├─────────────────────────────────────────────╯
         KC_MUTE,  MT_G(KC_ESC), LT(_LOWER,KC_BSPC),           LT(_RAISE,KC_SPC),  MT(KC_RALT,KC_ENTER), KC_MUTE
  //                    ───────────────────────────╯          ╰──────────────────────────
  ),

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (!clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) {
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    return false;
}
