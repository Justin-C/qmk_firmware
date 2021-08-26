#include "gamepad.h"

#define _MACRO 0
#define _QWERTY 1
#define _NUMPAD 2
#define _RESET 3

static bool one_down   = false;
static bool three_down = false;
static int  layer      = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MACRO] = KEYMAP(M(1), KC_1, KC_2, KC_3, KC_SLEP, LCTL(LALT(KC_O)), LCTL(LALT(KC_P)), LCTL(LALT(KC_LEFT_CURLY_BRACE)), LCTL(LALT(KC_RIGHT_CURLY_BRACE)), LCTL(LALT(KC_N)), LCTL(KC_T), LCTL(LSFT(KC_T)), LCTL(KC_TAB), LCTL(KC_R), M(0), KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT, KC_J, KC_K, KC_L, LCTL(KC_W)),

    [_QWERTY] = KEYMAP(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_B, KC_A, KC_S, KC_D, KC_F, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_LCTL, KC_G, KC_LALT, KC_SPC),

    [_NUMPAD] = KEYMAP(KC_ESCAPE, KC_1, KC_2, KC_3, KC_BSPACE, KC_TAB, KC_KP_7, KC_KP_8, KC_KP_9, M(2), KC_NUMLOCK, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS, KC_KP_DOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_PLUS, KC_KP_0, KC_KP_0, KC_KP_0, KC_KP_ENTER),

    [_RESET] = KEYMAP(RESET, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_K, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

    // KEYMAP(
    // 	M(1), TO(0), TO(1), TO(2), KC_SLEP,
    // 	LCTL(LALT(KC_O)), LCTL(LALT(KC_P)), LCTL(LALT(KC_LEFT_CURLY_BRACE)), LCTL(LALT(KC_RIGHT_CURLY_BRACE)), LCTL(LALT(KC_N)),
    // 	LCTL(KC_T), LCTL(LSFT(KC_T)), LCTL(KC_TAB), LCTL(KC_R), M(0),
    // 	KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT,
    // 	KC_J, KC_K, KC_L, LCTL(KC_W)),

    // KEYMAP(
    // 	KC_ESC, KC_1, KC_2, KC_3, TO(0),
    // 	KC_TAB, KC_Q, KC_W, KC_E, KC_R,
    // 	KC_CAPS, KC_A, KC_S, KC_D, KC_F,
    // 	KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
    // 	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC),

    // KEYMAP(
    // 	RESET, KC_NO, KC_NO, KC_NO, TO(0),
    // 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // 	KC_NO, KC_NO, KC_NO, KC_NO),

    // KEYMAP(
    // 	KC_ESC, KC_1, KC_2, KC_3, TO(1),
    // 	KC_TAB, KC_Q, KC_W, KC_E, KC_R,
    // 	KC_CAPS, KC_A, KC_S, KC_D, KC_F,
    // 	KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
    // 	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC),

    // KEYMAP(
    // 	KC_NO, LCTL(KC_LEFT), KC_NO, LCTL(KC_RGHT), TO(2),
    // 	KC_NO, LCTL(KC_T), LCTL(KC_W), LCTL(LSFT(KC_T)), LCTL(KC_R),
    // 	KC_MPRV, KC_VOLD, KC_MPLY, KC_VOLU, KC_MNXT,
    // 	KC_NO, LCTL(KC_Z), LCTL(KC_C), LCTL(KC_X), LCTL(KC_V),
    // 	M(0), KC_NO, KC_NO, KC_SLEP),

    // KEYMAP(
    // 	RESET, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
    // 	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS,
    // 	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS,
    // 	KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS,
    // 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case 0:
            if (event.pressed) {
                SEND_STRING("Justin.cai101@gmail.com");
                return false;
            }
            break;
        case 1:
            if (event.pressed) {
                SEND_STRING("https://imgur.com/a/QaImmX0");
                return false;
            }

        case 2:
            if (event.pressed) {
                SEND_STRING("jucai@visa.com");
                return false;
            }
    }
    return MACRO_NONE;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1:
            if (record->event.pressed) {
                if (three_down) {
                    if (layer == 0) {
                        layer_on(_QWERTY);
                        layer_off(_MACRO);
                        layer++;
                    } else if (layer == 1) {
                        layer_on(_NUMPAD);
                        layer_off(_QWERTY);
                        layer++;
                    } else if (layer == 2) {
                        layer_on(_RESET);
                        layer_off(_NUMPAD);
                        layer++;
                    } else if (layer == 3) {
                        layer_on(_MACRO);
                        layer_off(_RESET);
                        layer = 0;
                    }

                } else {
                    register_code(KC_1);
                }
                one_down = true;
            } else {
                unregister_code(KC_1);
                one_down = false;
            }
            return false;
            break;
        case KC_3:
            if (record->event.pressed) {
              if(one_down){
                if (layer == 0) {
                    layer_on(_QWERTY);
                    layer_off(_MACRO);
                    layer++;
                } else if (layer == 1) {
                    layer_on(_NUMPAD);
                    layer_off(_QWERTY);
                    layer++;
                } else if (layer == 2) {
                    layer_on(_RESET);
                    layer_off(_NUMPAD);
                    layer++;
                } else if (layer == 3) {
                    layer_on(_MACRO);
                    layer_off(_RESET);
                    layer = 0;
                }
            
            } else {
                register_code(KC_3);
            }
            three_down = true;
    } else {
        unregister_code(KC_3);
        three_down = false;
    }
    return false;
    break;
}
return true;
}
