// fork of Quantum project canonical layout

#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWERTY,
  _NUM,
  _SYMBOL
};

enum ferris_tap_dances {
  TD_Q_ESC,
};

#define KC_CTLP RCTL_T(KC_P)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_LSH0 LSFT_T(KC_0)
#define KC_LSHB LSFT_T(KC_BSLS)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_GUSC GUI_T(KC_SCLN)
#define KC_ALTD LALT_T(KC_DOT)
#define KC_RSHF RSFT_T(KC_F4)
#define KC_RSHE RSFT_T(KC_END)
#define KC_RSHH RSFT_T(KC_HOME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    TD(TD_Q_ESC), KC_W,      KC_E,    KC_R,       KC_T,              KC_Y,    KC_U,  KC_I,    KC_O,   KC_CTLP,
    KC_A,         KC_S,      KC_D,    KC_F,       KC_G,              KC_H,    KC_J,  KC_K,    KC_L,   KC_GUSC,
    KC_LSHZ,      KC_X,      KC_C,    KC_V,       KC_B,              KC_N,    KC_M,  KC_COMM, KC_ALTD, KC_RLSH,
                                      KC_BSPC,    KC_SPC,            MO(_NUM),MO(_SYMBOL)
  ),

  [_NUM] = LAYOUT( /* [> NUM <] */
    KC_1,           KC_2,    KC_3,    KC_4,       KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_RSHE,
                                      KC_TRNS,    KC_TRNS,      KC_TRNS, KC_TRNS 
  ),

  [_SYMBOL] = LAYOUT( /* [> SYMBOL <] */
    KC_GRV,        KC_LBRC,KC_RBRC, KC_TRNS, KC_TRNS,         KC_TRNS, KC_F9, KC_F10,KC_F11,KC_F12,
    KC_QUOT,       KC_LPRN,KC_RPRN, KC_MINS, KC_EQL,          KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8,
    KC_LSHB,       KC_LCBR,KC_RCBR, KC_UNDS, KC_PLUS,         KC_TRNS, KC_F1, KC_F2, KC_F3, KC_RSHF,
                                    KC_TAB,  KC_ENT,          KC_TRNS, KC_TRNS 
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};  
