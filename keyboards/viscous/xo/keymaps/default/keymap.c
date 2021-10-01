// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _MAC 1
#define _LOWER 2
#define _RAISE 3
#define _GAME 4
#define _RESET 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS ,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_MUTE,               KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_RGUI,   KC_GRV,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
    KC_LCTL,  KC_LGUI, KC_LALT, TO(_MAC), KC_LCTL, LSFT_T(KC_ENT), KC_LALT,   LT(_LOWER, KC_DEL),   KC_SPC,  LT(_RAISE, KC_BSPC),  KC_BSLS, KC_EQL, KC_BSLS,  KC_RGUI
  ),

    [_MAC] = LAYOUT( /* mac qwerty */
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS ,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_MUTE,               KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_RGUI,   KC_GRV,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL ,
    KC_LCTL,  KC_LGUI, KC_LALT, TO(_DEFAULT), KC_LGUI, LSFT_T(KC_ENT), KC_LALT,   LT(_LOWER, KC_DEL),   KC_SPC,  LT(_RAISE, KC_BSPC),  KC_BSLS, KC_EQL, KC_BSLS,  KC_RGUI
  ),

  [_LOWER] = LAYOUT(
    KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_F12,  KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS ,
    TO(_RESET),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT(
    KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  ,
    KC_SLEP,       KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS,                     KC_F12,  KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,               KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS ,
    TO(_RESET),    KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS, KC_MPRV , KC_MPLY , KC_MNXT, KC_TRNS, KC_TRNS ,
    TO(_GAME),       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_GAME] = LAYOUT(
    KC_ESC,  KC_NO  , KC_1  , KC_2  , KC_3  , KC_4  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TO(_DEFAULT)   ,
    KC_TAB,   KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  ,                     KC_NO  , KC_NO  , KC_I  , KC_NO  , KC_NO  , KC_NO   ,
    KC_LSFT,   KC_LSFT,  KC_A,    KC_S,    KC_D, KC_F  ,   KC_NO,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_LSFT,   KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,   KC_SPC,  KC_NO  , KC_M  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_LCTL, KC_LCTL,  KC_LGUI, KC_LALT, KC_LCTL  , KC_SPC  , KC_SPC  ,  KC_SPC  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
  ),


  [_RESET] = LAYOUT(
    TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,   KC_C,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_A,   KC_B,                   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET
  )

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
