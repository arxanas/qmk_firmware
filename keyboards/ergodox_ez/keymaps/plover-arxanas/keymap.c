#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define PLVR 3 // Plover layer

#define MACRO_PLOVER_ON  0
#define MACRO_PLOVER_OFF 1

#define M_PLON M(MACRO_PLOVER_ON)
#define M_PLOF M(MACRO_PLOVER_OFF)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer (Dvorak)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | \    | |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | '  " | ,  < | .  > |   P  |   Y  | ~ L1 |           |  L3  |   F  |   G  |   C  |   R  |   L  | =    + |
 * |--------+------+------+------+------+------|Symbol|           |Plover|------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | - / L2 |
 * |--------+------+------+------+------+------|  Cmd |           | LAlt |------+------+------+------+------+--------|
 * |LShift/(| ;  : |   Q  |   J  |   K  |   X  |(LGui)|           |      |   B  |   M  |   W  |   V  |   Z  |RShift/)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `  ~ |      |      |      | [  { |                                       | ]  } |      |      |      | /  ? |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |  Del |      |       |      |        |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Bksp | Alt+ |------|       |------| Enter  |Space |
 *                                 |      | Bksp |  End |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_NO,          KC_1,     KC_2,     KC_3,    KC_4,     KC_5,  KC_NO,
        KC_TAB,         KC_QUOT,  KC_COMM,  KC_DOT,  KC_P,     KC_Y,  KC_FN21,
        CTL_T(KC_ESC),  KC_A,     KC_O,     KC_E,    KC_U,     KC_I,
        KC_LSFT,        KC_SCLN,  KC_Q,     KC_J,    KC_K,     KC_X,  KC_LGUI,
        KC_GRV,         KC_NO,    KC_NO,    KC_NO,   KC_LBRC,
                                                     KC_DEL,   KC_NO,
                                                               KC_HOME,
                                     KC_BSPC,  LALT(KC_BSPC),  KC_END,
        // right hand
             KC_RGHT,  KC_6,  KC_7,     KC_8,   KC_9,   KC_0,   KC_BSLS,
             M_PLON,   KC_F,  KC_G,     KC_C,   KC_R,   KC_L,   KC_EQL,
                       KC_D,  KC_H,     KC_T,   KC_N,   KC_S,   LT(MDIA, KC_MINS),
             KC_LALT,  KC_B,  KC_M,     KC_W,   KC_V,   KC_Z,   KC_RSFT,
                              KC_RBRC,  KC_NO,  KC_NO,  KC_NO,  KC_SLSH,
             KC_NO,    KC_NO,
             KC_PGUP,
             KC_PGDN,  KC_ENT,  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | TEENSY |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
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
       RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |------|           |------|      |MsLeft|MsDown|MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Play | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Fwd   |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),

/* Keymap 3: Steno for Plover from https://github.com/shayneholmes/tmk_keyboard/commit/11290f8489013018f778627db725160c745e75bd
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |Plover|  6   |  7   |   8  |   9  |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   q  |   w  |   e  |   r  |   t  |------|           |------|  y   |  u   |   i  |   o  |  p   |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   a  |   s  |   d  |   f  |   g  |      |           |      |  h   |  j   |   k  |   l  |  ;   |   '    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   c  |   v  |------|       |------|  n   |  m   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PLVR] = KEYMAP(  // layout: layer 3: Steno for Plover
        // left hand
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
        KC_TRNS,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TRNS,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
        KC_TRNS,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_TRNS,
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                          KC_TRNS,  KC_TRNS,
                                                    KC_TRNS,
                                      KC_C,  KC_V,  KC_TRNS,
        // right hand
             KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
             M_PLOF,   KC_6,   KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
                       KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,
             KC_TRNS,  KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_N,  KC_M
),
};

const uint16_t PROGMEM fn_actions[] = {
    [21] = ACTION_LAYER_TAP_TOGGLE(SYMB), // FN21 - Momentary layer 1 (Symbols)
    [22] = ACTION_LAYER_TAP_TOGGLE(MDIA), // FN22 - Momentary layer 2 (Media)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
    case MACRO_PLOVER_ON:
        if (record->event.pressed) {
            layer_on(PLVR);
            // Send the PHROPB stroke to enable Plover.
            // (Note that you must have this command in your dictionary for it
            // to actually do anything.)
            return MACRO(D(E), D(R), D(F), D(V), D(I), D(K),
                         WAIT(50),
                         U(E), U(R), U(F), U(V), U(I), U(K),
                         END);
        }
        break;

    case MACRO_PLOVER_OFF:
        if (record->event.pressed) {
            layer_off(PLVR);
            // Send the PHROF stroke to disable Plover.
            return MACRO(D(E), D(R), D(F), D(V), D(U),
                         WAIT(50),
                         U(E), U(R), U(F), U(V), U(U),
                         END);
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
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        case PLVR:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
