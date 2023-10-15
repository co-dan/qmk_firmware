#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _CONTROL,
    _ADJUST
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
    COMBO(test_combo1, CAPS_WORD)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_Q,   KC_W,       KC_E,       KC_R,       KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,                         KC_P,
    KC_A,   MT_G(KC_S), MT_S(KC_D), MT_C(KC_F), KC_G,    KC_H,    MT_C(KC_J), MT_S(KC_K), MT_G(KC_L),  LT(_CONTROL, KC_SCLN),
    KC_Z,   KC_X,       KC_C,       KC_V,       KC_B,    KC_N,    KC_M,       KC_COMM,    KC_DOT,                    KC_SLSH,
                 MT_G(KC_ESC),  LT(_LOWER,KC_BSPC),  LT(_RAISE,KC_SPACE), MT(KC_RALT,KC_ENTER)
  ),

  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_9,     KC_0,
    KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT, KC_LEFT, KC_DOWN,    KC_UP,   KC_RIGHT, KC_QUOTE,
    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_BACKSLASH,
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ), 

  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL,
    KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,  KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_QUOTE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BACKSLASH,
                  KC_TRNS,             KC_TRNS,          KC_TRNS,                KC_TRNS
  ),
  [_CONTROL] = LAYOUT(
    KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS,             KC_TRNS,          KC_TRNS,                KC_TRNS
  ),
  [_ADJUST] = LAYOUT(
    QK_BOOT,   KC_2,       KC_3,       KC_4,       KC_5,    KC_6,    KC_7,       KC_8,       KC_9,             KC_0,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                  KC_TRNS,             KC_TRNS,          KC_TRNS,                KC_TRNS
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



// Liatris specific stuff

/* void keyboard_post_init_user(void) { */
/*   // Initialize RGB to static black */
/*   rgblight_enable_noeeprom(); */
/*   rgblight_sethsv_noeeprom(HSV_BLACK); */
/*   rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
/* } */

/* void housekeeping_task_user(void) { */
/*   switch (get_highest_layer(layer_state | default_layer_state)) { */
/*   case 0: */
/*     rgblight_setrgb_at(RGB_WHITE, 0); */
/*     break; */
/*   case 1: */
/*     rgblight_setrgb_at(10,10,200, 0); */
/*     break; */
/*   case 2: */
/*     rgblight_setrgb_at(10,200,10, 0); */
/*     break; */
/*   default: */
/*     rgblight_setrgb_at(200,10,10, 0); */
/*   } */
/* } */
