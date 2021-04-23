/* Copyright 2020 @toastedmangoes
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

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_UP,    KC_L,     KC_ENT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_LEFT,  KC_DOWN,  KC_RGHT,  MO(2),
    KC_LCTL,   MO(1),    KC_LALT,  KC_SPC,   KC_RGUI
  ),

  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_7,     KC_8,     KC_9,     KC_0,      XXXXXXX,            XXXXXXX,  KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL,   _______,
    _______,  KC_4,     KC_5,     KC_6,     XXXXXXX,   RGB_TOG,            XXXXXXX,  KC_GRV,   KC_SCLN,  KC_QUOT,  KC_BSLS,  _______,
    _______,  KC_1,     KC_2,     KC_3,     XXXXXXX,   RGB_MOD,            XXXXXXX,  XXXXXXX,  KC_COMM,  KC_DOT,   KC_SLSH,  _______,
    _______,   _______,  _______,  _______,  _______
  ),

  [_RAISE] = LAYOUT_reviung41(
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_PSCR,            KC_MUTE,  XXXXXXX,  KC_MPRV, KC_MPLY, KC_MNXT,  _______,
    _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,     KC_DEL,             KC_VOLU,  XXXXXXX,  KC_HOME,  _______,  KC_END,   _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_INS,             KC_VOLD, XXXXXXX, C(KC_LEFT), _______, C(KC_RGHT), _______,
    _______,   _______,  _______,  _______,  _______
  ),
};

