#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
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
    COMBO(test_combo1, QK_CAPS_WORD_TOGGLE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,       KC_Q,   KC_W,       KC_E,       KC_R,       KC_T,          KC_TRNS, KC_Y,    KC_U,       KC_I,       KC_O,             KC_P,             KC_BSPC,
    MT_G(KC_TAB), KC_A,   MT_G(KC_S), MT_S(KC_D), MT_C(KC_F), KC_G,  KC_MUTE,KC_TRNS, KC_H,    MT_C(KC_J), MT_S(KC_K), MT_G(KC_L),  LT(_CONTROL, KC_SCLN), KC_ENTER,
    KC_LSFT,      KC_Z,   KC_X,       KC_C,       KC_V,       KC_B,          KC_TRNS, KC_N,    KC_M,       KC_COMM,    KC_DOT,         KC_SLSH,            KC_BSLS,
    KC_MUTE,     MT_G(KC_ESC), LT(_LOWER,KC_BSPC), LT(_CONTROL,KC_BSPC),     KC_TRNS,KC_TRNS,KC_TRNS,   KC_SPACE, LT(_RAISE,KC_SPACE), MT(KC_RALT,KC_ENTER),         KC_MPLY
  ),
  [_RAISE] = LAYOUT(                                                 
    KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_A,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,      
    KC_TRNS,    KC_GRV,  KC_MINS, KC_EQL,  KC_BSLS, KC_QUOT,     KC_TRNS,KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_QUOTE, KC_TRNS,
    KC_TRNS,    KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_COLN,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BACKSLASH, KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS            
  ),                                                                                                                 
  [_LOWER] = LAYOUT(                                                                                                 
    KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_DQT,           KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_QUOTE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BACKSLASH, KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS            
  ),                                                                                                                 
  [_ADJUST] = LAYOUT(                                                                                                
    QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_TRNS,
    KC_TRNS,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, RGB_RMOD, RGB_TOG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, RGB_MOD,  KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  ),
  [_CONTROL] = LAYOUT(                                                                                                
    KC_GRV,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_PGUP,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_MS_BTN2, KC_MS_BTN1, KC_PGDN,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS,          DPI_FINE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][4][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(DPI_UP, DPI_DN)    },
    [_RAISE] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END)   },
    [_ADJUST] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_CONTROL] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
};
#endif

/* void pointing_device_init_user(void) { */
/*     set_auto_mouse_layer(_MOUSE); */
/*     set_auto_mouse_enable(true); */
/* } */

bool led_update_user(led_t led_state) { return false; }

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


layer_state_t layer_state_set_user(layer_state_t state) {
    bool res =  update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    switch (get_highest_layer(state)) {
        case _ADJUST:
            writePinHigh(B12);
            writePinLow(B13);
            writePinLow(B14);
            break;      
        case _RAISE:
            writePinLow(B12);
            writePinHigh(B13);
            writePinLow(B14);
            break;
        case _LOWER:
            writePinLow(B12);
            writePinLow(B13);
            writePinHigh(B14);
            break;
        default:
            writePinLow(B12);
            writePinLow(B13);
            writePinLow(B14);
            break;
    }
    return res;
}
