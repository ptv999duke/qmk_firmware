#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMPAD 2
#define MDIA 3 // media keys
#define EPRM M(1) // Macro 1: Reset EEPROM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.             ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  | ~L3  |             | Caps |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|             |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Home |             | PgUp |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |             |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|             |------|   H  |   J  |   K  |   L  |   ;  |  Ctrl  |
 * |--------+------+------+------+------+------| End  |             | PgDn |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |             |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'             `-------------+------+------+------+------+--------'
 *   |~L1   |  '"  |  Alt | Left | Right|                                         |  Up  | Down |   [  |   ]  |   ~L2  |
 *   `----------------------------------'                                         `------------------------------------'
 *                                        ,----------------.        ,-----------------.
 *                                        | LGui |   App   |        | Alt     |  Esc  |
 *                                 ,------|------|---------|        |---------+-------|------.
 *                                 |      |      | CtrlShf |        | Insert  |       |      |
 *                                 | Space|Backsp|---------|        |---------|  Del  |Enter |
 *                                 |      |ace   | AltShf  |        | CtrlAlt |       |      |
 *                                 `-----------------------'        `------------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,    KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_FN3,
        KC_TAB,    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_HOME,
        KC_LCTRL,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,
        KC_LSFT,   KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,    KC_END,
        KC_FN1,    KC_QUOT,  KC_LALT,  KC_LEFT, KC_RGHT,

                                                        KC_LGUI,  ALT_T(KC_APP),  
                                                                  LCTL(KC_LSFT),
                                               KC_SPC,  KC_BSPC,  LALT(KC_LSFT),
        // right hand
        KC_CAPS,  KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_PGUP,  KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS,
                  KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_LCTRL,
        KC_PGDN,  KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                          KC_UP,  KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_FN2,
             
        KC_RALT,        KC_ESC,
        KC_INS,
        LCTL(KC_LALT),KC_DELT, KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  Grv |  '"  |   *  |   ^  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           |      |   (  |   )  |   -  |   _  |   =  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |  Up  |      |      |------|           |------|   {  |   }  |   &  |   %  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |      |           |      |   [  |   ]  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,KC_F6,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
       KC_TRNS,KC_F11, KC_F12,   KC_UP,    KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                       KC_TRNS,KC_TRNS,
                                                               KC_TRNS,
                                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_GRV,  KC_QUOT,  KC_ASTR,  KC_CIRC,        KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_LPRN, KC_RPRN,  KC_MINS,  KC_UNDERSCORE,  KC_EQL,   KC_TRNS,
                KC_LCBR, KC_RCBR,  KC_AMPR,  KC_PERC,        KC_SCLN,  KC_TRNS,
       KC_TRNS, KC_LBRC, KC_RBRC,  KC_COMM,  KC_DOT,         KC_SLSH,  KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |  9   |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   4  |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   1  |  2   |  3   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   0  |  .   |  ,   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NUMPAD] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_4,    KC_5,    KC_6, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_1,    KC_2,    KC_3, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_0,    KC_COMM, KC_DOT, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(NUMPAD),
    [3] = ACTION_LAYER_TAP_TOGGLE(MDIA),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
