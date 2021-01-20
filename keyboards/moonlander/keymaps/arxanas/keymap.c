#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_steno.h"
#include "wpm.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_DELETE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
    KC_TAB,         KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           TG(1),                                          TG(2),          KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_EQUAL,
    LCTL_T(KC_ESCAPE),KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_LSPO,                                                                        KC_RSPC,        KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           LT(1,KC_MINUS),
    KC_LSHIFT,      KC_SCOLON,      KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_RSHIFT,
    KC_GRAVE,       WEBUSB_PAIR,    KC_HOME,        KC_END,         KC_LBRACKET,    KC_LGUI,                                                                                                        KC_LALT,        KC_RBRACKET,    KC_PGUP,        KC_PGDOWN,      KC_SLASH,       KC_SLASH,
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
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          STN_NUM,        STN_NUM,        STN_NUM,        STN_NUM,        STN_NUM,        KC_NO,                                          KC_TRANSPARENT, STN_NUM,        STN_NUM,        STN_NUM,        STN_NUM,        STN_NUM,        STN_NUM,
    KC_NO,          STN_SL,         STN_TL,         STN_PL,         STN_HL,         STN_STR,        KC_NO,                                                                          KC_NO,          STN_STR,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,
    KC_NO,          STN_SL,         STN_KL,         STN_WL,         STN_RL,         STN_STR,                                                                                                        STN_STR,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    STN_A,          STN_O,          KC_NO,                          KC_NO,          STN_E,          STN_U
  ),
};
// clang-format on

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {{69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230},
           {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}, {69, 145, 230}},
    [2] = {{135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255},
           {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}, {135, 255, 255}},
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
            // Steno layer.
            if (layer == 2) {
                int wpm = get_current_wpm();
                hsv.v   = wpm > 200 ? UINT8_MAX : UINT8_MAX * ((float)wpm / 200);
            }
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
        case 2:
            set_layer_color(2);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

static uint8_t     current_wpm   = 0;
static uint8_t     latest_wpm    = 0;
static uint16_t    wpm_timer     = 0;
static const float wpm_smoothing = 0.0487;

bool process_steno_user(uint16_t _keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        if (wpm_timer > 0) {
            latest_wpm  = 60000 / timer_elapsed(wpm_timer) * 1.0;
            current_wpm = (latest_wpm - current_wpm) * wpm_smoothing + current_wpm;
            set_current_wpm(current_wpm);
        }
        wpm_timer = timer_read();
    }
    return true;
}
