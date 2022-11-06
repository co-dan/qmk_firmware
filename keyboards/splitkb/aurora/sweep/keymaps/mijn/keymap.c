#include QMK_KEYBOARD_H

const uint16_t PROGMEM caps_word_combo[] = {LCTL_T(KC_F), RCTL_T(KC_J), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_word_combo, CAPS_WORD),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
                     KC_Q, KC_W,         KC_E,         KC_R,         KC_T,     KC_Y, KC_U,         KC_I,         KC_O,         KC_P,
                     KC_A, LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,     KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RGUI_T(KC_L), LT(4,KC_SCLN),
                     KC_Z, KC_X,         KC_C,         KC_V,         KC_B,     KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                            LGUI_T(KC_ESC), LT(1,KC_BSPC),     LT(2,KC_SPC), RALT_T(KC_ENT)),
	[1] = LAYOUT(
                     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,
                     KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,               KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOTE,
                     KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON,             KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC,  KC_BSLS,
                                                 KC_TRNS, KC_TRNS,             LT(3,KC_ENT), KC_DEL),
	[2] = LAYOUT(
                     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
                     KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT,              KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOTE,
                     KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLON,             KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC,  KC_BSLS,
                                           KC_LCTL, LT(3,KC_BSPC),             KC_TRNS, KC_DEL),
	[3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, RGB_MOD),
	[4] = LAYOUT(
                     KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                     KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDOWN,             KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                  KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_S):
        case LSFT_T(KC_D):
        case LCTL_T(KC_F):
        case RCTL_T(KC_J):
        case RSFT_T(KC_K):
        case RGUI_T(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

