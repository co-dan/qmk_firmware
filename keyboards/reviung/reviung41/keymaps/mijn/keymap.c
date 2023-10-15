/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define KC_MTCT MT(MOD_LCTL, KC_TAB) 
#define MT_C(X) MT(MOD_LCTL, X)
#define MT_A(X) MT(MOD_LALT, X)
#define MT_G(X) MT(MOD_LGUI, X)
#define MT_S(X) MT(MOD_LSFT, X)

//const uint16_t PROGMEM caps_word_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM caps_word_combo[] = {MT_C(KC_F), MT_C(KC_J), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_word_combo, CW_TOGG),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
      QK_GESC,   KC_Q,       KC_W,       KC_E,       KC_R, KC_T,          KC_Y,        KC_U,       KC_I,       KC_O,    KC_P,  KC_BSPC,
      KC_MTCT,   KC_A, MT_G(KC_S), MT_S(KC_D), MT_C(KC_F), KC_G,          KC_H,  MT_C(KC_J), MT_S(KC_K), MT_G(KC_L), KC_SCLN, KC_ENTER,
      KC_LSFT,   KC_Z,       KC_X,       KC_C,       KC_V, KC_B,          KC_N,        KC_M,    KC_COMM,     KC_DOT, KC_SLSH,KC_BACKSLASH,
                                     KC_LGUI,  LT(_LOWER,KC_BSPC), KC_SPC, LT(_RAISE,KC_SPC), KC_RALT
  ),
  
  [_LOWER] = LAYOUT_reviung41(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,                       KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,  KC_DQT, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PGDN, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LGUI,   MO(3),   KC_ENT, _______, KC_RALT
  ),
  
  [_RAISE] = LAYOUT_reviung41(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_MTCT,  KC_GRV, KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,KC_QUOTE,KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_LGUI, KC_BSPC,  _______, _______, KC_RALT
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    QK_BOOT, RGB_VAI, RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MEDIA_PLAY_PAUSE,  XXXXXXX,
    XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

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
