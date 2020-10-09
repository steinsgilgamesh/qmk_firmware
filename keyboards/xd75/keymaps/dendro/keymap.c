/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QW 0
#define _SY 1
#define _NV 2
#define _FN 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_MUTE, _______,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, KC_VOLU, _______,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MPRV, KC_MPLY, KC_MNXT,   KC_H,    KC_J,    KC_K,    KC_UP,   KC_L,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, KC_VOLD, _______,   KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT, MO(_NV),
    KC_LCTL, KC_LGUI, KC_LALT, _______, KC_LCTL, MO(_SY), KC_LSFT, MO(_FN), MO(_NV),   KC_SPC,  KC_RGUI, _______, KC_RALT, KC_RCTL, KC_RGUI
  ),


  [_SY] = LAYOUT_ortho_5x15( /* SYMBOLS */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, KC_GRV,  KC_SCLN, KC_QUOT, KC_BSLS, _______,
    _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, KC_LCTL, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
  ),

  [_NV] = LAYOUT_ortho_5x15( /* NAVIGATION */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, KC_HOME, _______, KC_END,  _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______,C(KC_LEFT),_______,C(KC_RGHT),_______,
    _______, _______, _______, _______, _______, KC_LCTL, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
  ),

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTIONS */
    _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_RMOD,RGB_HUD, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_LCTL, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QMKBEST:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      SEND_STRING("QMK is the best thing ever!");
    } else {
      // when keycode QMKBEST is released
    }
    break;
  case QMKURL:
    if (record->event.pressed) {
      // when keycode QMKURL is pressed
      SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
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
