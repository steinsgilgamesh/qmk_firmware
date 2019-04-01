
// Default ECO Layout
// KLE here : http://www.keyboard-layout-editor.com/#/gists/0733eca6b4cb88ff9d7de746803f4039

#include "eco.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN1 2
#define _FN2 3
#define _FN3 4

enum eco_keycodes {
  QWERTY = SAFE_RANGE
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP(
  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,     KC_MINS,  KC_ESC,   KC_GRV,  KC_EQL,  KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,     KC_TAB,   KC_SCLN,  KC_QUOT, KC_BSPC, KC_H,     KC_J,    KC_K,    KC_L,    KC_ENT,
  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,     KC_LBRC,  KC_RBRC,  KC_COMM, KC_DOT,  KC_N,     KC_M,    KC_HOME, KC_UP,   KC_END,
  KC_LSFT, KC_LALT,KC_LGUI, KC_BSLS, KC_LCTL, MO(_FN1), KC_LSFT,  KC_RGUI, MO(_FN2),KC_SPC,   KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
),

[_FN1] = KEYMAP(
  _______, KC_7,     KC_8,    KC_9,    KC_0,    _______, KC_7,     KC_8,   KC_9,    KC_LBRC,  KC_RBRC,  KC_MINS, KC_EQL,   _______,
  KC_TAB,  KC_4,     KC_5,    KC_6,    _______, _______, KC_4,     KC_5,   KC_6,    _______,  KC_SCLN,  KC_QUOT, KC_BSLS,  KC_DEL,  
  _______, KC_1,     KC_2,    KC_3,    _______, _______, KC_1,     KC_2,   KC_3,    _______,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_INS,
  KC_LSFT, KC_LALT,KC_LGUI, _______, _______, _______, KC_0,     _______,_______, _______,   _______, _______, _______, _______
),


[_FN2] = KEYMAP(
  _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_PLUS,  _______,
  KC_TAB,  KC_DLR,  KC_PERC, KC_CIRC, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,    _______,  KC_COLN,  KC_DQT,   KC_PIPE,  KC_BSPC,
  _______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,  KC_LT,    KC_GT,    KC_QUES,  KC_MUTE,
  KC_LSFT, KC_LALT,KC_LGUI, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),


[_FN3] = KEYMAP(
  _______, KC_7,    KC_8,     KC_9,     _______, _______, _______,  _______, _______, _______, _______, KC_PAUS, KC_INS,  KC_PGUP,
  _______, KC_4,    KC_5,     KC_6,     _______, _______, _______,  _______, _______, _______, _______, KC_PSCR, KC_DEL,  KC_PGDN,
  _______, KC_1,    KC_2,     KC_3,     _______, _______, _______,  _______, _______, _______, _______, _______, KC_VOLU, KC_MPLY,
  _______, KC_0,    _______,  _______,  _______, _______, _______,  _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

