/* Copyright 2019 eswai
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   SYMBOL,
//   NAVI,
//   FUNC
// };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

enum keymap_layers {
  _QWERTY,
  _SYMBOL,
  _NAVI,
  _MFUNC
};

#define _____   KC_TRNS
#define XXXXX   KC_NO
#define SYMBOL  MO(_SYMBOL)
#define NAVI    MO(_NAVI)
#define MFUNC   MO(_MFUNC)
#define CRGHT   C(KC_RGHT)
#define CLEFT   C(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXX,   XXXXX,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXX,   XXXXX,   KC_H,    KC_J,    KC_K,    KC_UP,   KC_L,    KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXX,   XXXXX,   KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT,   NAVI, \
    KC_LCTL, KC_LALT, KC_LALT, MFUNC,   KC_LCTL, SYMBOL,  MFUNC,   KC_RSFT, KC_SPC,  KC_RGUI, MFUNC,   KC_RALT, KC_RCTL, KC_RGUI \
  ),

  [_SYMBOL] = LAYOUT( \
    KC_ESC,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_4,    KC_5,    KC_6,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_GRV,  KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT, \
    KC_LSFT, KC_1,    KC_2,    KC_3,    XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_COMM, KC_DOT,  KC_SLSH, _____, \
    KC_LCTL, KC_LALT, KC_LALT, _____,   KC_LCTL, _____,   _____,   KC_RSFT, KC_SPC,  KC_RGUI, _____,   KC_RALT, KC_RCTL, KC_RGUI \
  ),

  [_NAVI] = LAYOUT( \
    KC_ESC,  XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_PSCR, KC_INS,  KC_DEL,  KC_BSPC, \
    KC_TAB,  XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_ENT, \
    KC_LSFT, XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_PGDN, CLEFT,   KC_DOWN, CRGHT,   _____, \
    KC_LCTL, KC_LALT, KC_LALT, _____,   KC_LCTL, _____,   _____,   KC_RSFT, KC_SPC,  KC_RGUI, _____,   KC_RALT, KC_RCTL, KC_RGUI \
  ),

  [_MFUNC] = LAYOUT( \
    RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_BSPC, \
    KC_TAB,  RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   KC_ENT, \
    KC_LSFT, RGB_M_P, RGB_M_B, RGB_M_K, RGB_M_G, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____, \
    KC_LCTL, KC_LALT, KC_LALT, _____,   KC_LCTL, _____,   _____,   KC_RSFT, KC_SPC,  KC_RGUI, _____,   KC_RALT, KC_RCTL, KC_RGUI \
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        // SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        // SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}