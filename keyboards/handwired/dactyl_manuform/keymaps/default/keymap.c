#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _NAV 1
//#define _NUM 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUM,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,-----------------------------------------,               ,-----------------------------------------,
 * |  esc |   1  |   2  |   3  |   4  |   5  |               |   6  |   7  |   8  |   9  |   0  |   \  |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * |  tab |   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  |   [  |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * |  NAV |   A  |   S  |   D  |   F  |   G  |               |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * | shift|   Z  |   X  |   C  |   V  |   B  |               |   N  |   M  |   ,  |   .  |   /  |   ]  |
 * |-------------+------+------+-------------|               |-------------+------+------+-------------|
 *               |  [   |   ]  |                                           |   -  |   =  |
 *               '------+------'-------------'               '-------------'------+------'
 *                             | bksp | space|               | space|enter |
 *                             |  +   |   +  |               |  +   |  +   |
 *                             | shift| ctrl |               | alt  |shift |
 *                             '------+------'               '------+------'
 *                                    '------+------' '------+------'
 *                                    |  tab | home | | end  |  del |
 *                                    |------+------' '------+------|
 *                                    |\(NAV)|   ~  | | gui  |  /   |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSLS,   \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,   \
  _NAV  ,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,   \
 KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RBRC,   \
                 KC_LBRC, KC_RBRC,                                              KC_MINS,  KC_EQL,                      \
                             SFT_T(KC_BSPC), CTL_T(KC_SPC),  ALT_T(KC_SPC),  SFT_T(KC_ENT),                            \
                                     KC_TAB,       KC_HOME,  KC_END,  KC_DEL,                                          \
                                    KC_BSLS,        KC_GRV,  KC_LGUI, KC_SLASH                                         \
),


/* Navigation layer
 * ,-----------------------------------------,               ,-----------------------------------------,
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * |      |      |      |  mup |      |      |               |      |      |  up  |      |      |      |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * |      |      | mleft| mdown|mright|      |               |      | left | down |right |      |      |
 * |------+------+------+------+------+------|               |-------------+------+------+------+------|
 * |      |      |      |      |      |      |               |      |      |      |      |      |      |
 * |-------------+------+------+-------------|               |-------------+------+------+-------------|
 *               |      |      |                                           | mbtn |mbtn2 |
 *               '------+------'-------------'               '-------------'------+------'
 *                             |      |      |               |      |      |
 *                             |      |      |               |      |      |
 *                             |      |      |               |      |      |
 *                             '------+------'               '------+------'
 *                                    '------+------' '------+------'
 *                                    |  tab | home | | end  |  del |
 *                                    |------+------' '------+------|
 *                                    |\(NAV)|   ~  | | gui  |/(NUM)|
 *                                    '------+------' '------+------'
 */

[_NAV] = LAYOUT( \
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
  KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_MS_UP,    KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,    KC_UP,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
  KC_TRNS,    KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,   KC_TRNS,       KC_TRNS,  KC_LEFT,  KC_DOWN, KC_RIGHT,  KC_TRNS,  KC_TRNS,   \
  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   \
                           KC_TRNS,   KC_TRNS,                                                KC_MS_BTN1,  KC_MS_BTN2,                    \
                                                  KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,                                           \
                                                  KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS,                                           \
                                                  KC_TRNS,    KC_TRNS,       KC_TRNS,  KC_TRNS                                            \

)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

