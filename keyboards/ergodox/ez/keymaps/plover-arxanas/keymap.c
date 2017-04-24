#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "sendchar.h"
#include "virtser.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define PLVR 3 // Plover layer

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
             TG(PLVR), KC_F,  KC_G,     KC_C,   KC_R,   KC_L,   KC_EQL,
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

// TX Bolt codes -- see https://github.com/qmk/qmk_firmware/blob/master/keyboards/ergodox/ez/keymaps/steno/keymap.c
#define Sl 0b00000001
#define Tl 0b00000010
#define Kl 0b00000100
#define Pl 0b00001000
#define Wl 0b00010000
#define Hl 0b00100000
#define Rl 0b01000001
#define Al 0b01000010
#define Ol 0b01000100
#define X  0b01001000
#define Er 0b01010000
#define Ur 0b01100000
#define Fr 0b10000001
#define Rr 0b10000010
#define Pr 0b10000100
#define Br 0b10001000
#define Lr 0b10010000
#define Gr 0b10100000
#define Tr 0b11000001
#define Sr 0b11000010
#define Dr 0b11000100
#define Zr 0b11001000
#define NM 0b11010000
#define GRPMASK 0b11000000
#define GRP0 0b00000000
#define GRP1 0b01000000
#define GRP2 0b10000000
#define GRP3 0b11000000

/* Keymap 3: Steno for Plover from https://github.com/shayneholmes/tmk_keyboard/commit/11290f8489013018f778627db725160c745e75bd
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |Plover|  #   |  #   |   #  |   #  |  #   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|  *   |  F   |   P  |   L  |  T   |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |  *   |  R   |   B  |   N  |  S   |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|  E   |  U   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PLVR] = KEYMAP(  // layout: layer 3: Steno for Plover
        // left hand
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,
        KC_TRNS,  M(NM),  M(NM),  M(NM),  M(NM),  M(NM),  KC_TRNS,
        KC_TRNS,  M(Sl),  M(Tl),  M(Pl),  M(Hl),  M(X),
        KC_TRNS,  M(Sl),  M(Kl),  M(Wl),  M(Rl),  M(X),   KC_TRNS,
        KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                          KC_TRNS,  KC_TRNS,
                                                    KC_TRNS,
                                      M(Al), M(Ol), KC_TRNS,
        // right hand
             KC_TRNS,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
             KC_TRNS,  M(NM),  M(NM),    M(NM),    M(NM),    M(NM),    KC_TRNS,
                       M(X),   M(Fr),    M(Pr),    M(Lr),    M(Tr),    M(Dr),
             KC_TRNS,  M(X),   M(Rr),    M(Br),    M(Gr),    M(Sr),    M(Zr),
                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, M(Er), M(Ur)
),
};

const uint16_t PROGMEM fn_actions[] = {
    [21] = ACTION_LAYER_TAP_TOGGLE(SYMB), // FN21 - Momentary layer 1 (Symbols)
    [22] = ACTION_LAYER_TAP_TOGGLE(MDIA), // FN22 - Momentary layer 2 (Media)
};

uint8_t chord[4] = {0, 0, 0, 0};
uint8_t pressed_count = 0;

void send_chord(void)
{
    for (uint8_t i = 0; i < 4; i++) {
        if (chord[i]) {
            virtser_send(chord[i]);
        }
    }
    virtser_send(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    // We need to track keypresses in all modes, in case the user
    // changes mode whilst pressing other keys.
    if (record->event.pressed) {
        pressed_count++;
    } else {
        pressed_count--;
    }
    return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
        uint8_t grp = (id & GRPMASK) >> 6;
        chord[grp] |= id;
    } else {
        if (pressed_count == 0) {
            send_chord();
            chord[0] = chord[1] = chord[2] = chord[3] = 0;
        }
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
