// fork of Quantum project canonical layout

#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWERTY,
  _NUM,
  _SYMBOL
};

enum ferris_tap_dances {
  TD_Q_ESC,
  TD_ENT_TAB
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)
#define KC_GUSC GUI_T(KC_SCLN)
#define KC_ALTP LALT_T(KC_P)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    TD(TD_Q_ESC), KC_W,      KC_E,    KC_R,       KC_T,              KC_Y,    KC_U,  KC_I,    KC_O,   KC_ALTP,
    KC_CTLA,      KC_S,      KC_D,    KC_F,       KC_G,              KC_H,    KC_J,  KC_K,    KC_L,   KC_GUSC,
    KC_LSHZ,      KC_X,      KC_C,    KC_V,       KC_B,              KC_N,    KC_M,  KC_COMM, KC_DOT, KC_RLSH,
                                      KC_BSPC,    KC_SPC,            MO(_NUM),MO(_SYMBOL)
  ),

  [_NUM] = LAYOUT( /* [> NUM <] */
    KC_1,           KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS,        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
                                      KC_TAB,  KC_ENT,          KC_TRNS, KC_TRNS 
  ),

  [_SYMBOL] = LAYOUT( /* [> SYMBOL <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_GRV,          KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_VOLD, KC_VOLU, KC_MRWD, KC_MFFD,         KC_UNDS, KC_PLUS, KC_LPRN, KC_RPRN, KC_TRNS,
                               KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    // Tap once for enter, twice for tab
    [TD_ENT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_TAB)
};  