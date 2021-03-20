/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

enum torn_layers { _QWERTY, _SYMBOL, _NAVI };

// #define S_BSPC LSFT_T(KC_BSPC)
// #define R_DEL LT(_RAISE, KC_DEL)
// #define G_ENT LGUI_T(KC_ENT)
// #define L_SPC LT(_LOWER, KC_SPC)

#define SYMBOL MO(_SYMBOL)
#define NAVI MO(_NAVI)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_split_3x6_4(
  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
  KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_UP,   KC_L,    KC_ENT, 
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT, NAVI, 
                      KC_LALT, KC_LCTL, SYMBOL,  KC_SPC,    KC_CAPS, KC_SPC,  KC_RGUI, KC_RCTL
),

[_SYMBOL] = LAYOUT_split_3x6_4(
  KC_ESC,    KC_7,   KC_8,    KC_9,    KC_0,    XXXXXXX,    XXXXXXX, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSPC, 
  KC_TAB,    KC_4,   KC_5,    KC_6,    XXXXXXX, XXXXXXX,    XXXXXXX, KC_GRV,  KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT, 
  KC_LSFT,   KC_1,   KC_2,    KC_3,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, _______, 
                    KC_LALT,  KC_LCTL, SYMBOL,  KC_SPC,     KC_CAPS, KC_SPC,  KC_RGUI, KC_RCTL
),

[_NAVI] = LAYOUT_split_3x6_4(
  KC_ESC,    KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR,    XXXXXXX, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,  KC_BSPC, 
  KC_TAB,    KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_DEL,     XXXXXXX, KC_VOLD, KC_HOME, _______, KC_END,   KC_ENT, 
  KC_LSFT,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_INS,     XXXXXXX, XXXXXXX,C(KC_LEFT),_______,C(KC_RGHT),_______, 
                     KC_LALT, KC_LCTL, SYMBOL,  KC_SPC,     KC_MUTE, KC_SPC,  KC_RGUI, KC_RCTL
)

};

const uint16_t PROGMEM encoder_keymaps[][2][2] = {
    [_QWERTY] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_PGDN,      KC_PGUP } },
    [_SYMBOL]  =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC_PGDN,      KC_PGUP } },
    [_NAVI]  =  { { KC_TRNS,      KC_TRNS },       { KC_VOLD,      KC_VOLU } },
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _SYMBOL));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _NAVI));
    return state;
}
