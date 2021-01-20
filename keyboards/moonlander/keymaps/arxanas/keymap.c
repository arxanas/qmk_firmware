#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_DELETE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    KC_TAB,         KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           TG(1),                                          TG(1),          KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_EQUAL,
    LCTL_T(KC_ESCAPE),KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_LBRACKET,                                                                    KC_RBRACKET,    KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           LT(1,KC_MINUS),
    KC_LSHIFT,      KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_RSHIFT,
    KC_GRAVE,       WEBUSB_PAIR,    KC_TRANSPARENT, KC_HOME,        KC_END,         KC_LGUI,                                                                                                        KC_LALT,        KC_PGUP,        KC_PGDOWN,      KC_TRANSPARENT, KC_SLASH,       KC_SLASH,
    KC_BSPACE,      LALT(KC_BSPACE),KC_LGUI,                        KC_LALT,        KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MU_MOD,         KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
// clang-format on

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {{69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230},
           {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 1:
            set_layer_color(1);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
