/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _SYMBOL,
  _NAVI,
  _FUNC,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SYMBOL,
  NAVI,
  FUNC,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_UP,   KC_L,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_LEFT, KC_DOWN, KC_RGHT, NAVI ,
    KC_LCTL, KC_LGUI, FUNC,    KC_LALT, KC_LCTL, SYMBOL,  KC_SPC,  KC_RGUI, FUNC,    ADJUST,  KC_RALT, KC_RGUI
  ),

  [_SYMBOL] = LAYOUT_planck_grid(
    _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  _______,
    _______, KC_4,    KC_5,    KC_6,    _______, _______, _______, KC_GRV,  KC_SCLN, KC_QUOT, KC_BSLS, _______,
    _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, KC_COMM,  KC_DOT, KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAVI] = LAYOUT_planck_grid(
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, _______, _______, _______, _______, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_DEL,  _______, _______, KC_HOME, _______, KC_END,  _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_INS,  _______, _______, C(KC_LEFT), _______, C(KC_RGHT), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FUNC] = LAYOUT_planck_grid(
    _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
  )

};

#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      print("mode just switched to qwerty and this is a huge string\n");
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
  case SYMBOL:
    if (record->event.pressed) {
      layer_on(_SYMBOL);
    } else { layer_off(_SYMBOL); }
    return false;
  case NAVI:
    if (record->event.pressed) {
      layer_on(_NAVI);
    } else { layer_off(_NAVI); }
    return false;
  case FUNC:
    if (record->event.pressed) {
      layer_on(_FUNC);
    } else { layer_off(_FUNC); }
    return false;
  case ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    } else { layer_off(_ADJUST); }
    return false;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    // if (IS_LAYER_ON(_RAISE)) {
    //   if (clockwise) {
    //     muse_offset++;
    //   } else {
    //     muse_offset--;
    //   }
    // } else {
    //   if (clockwise) {
    //     muse_tempo += 1;
    //   } else {
    //     muse_tempo -= 1;
    //   }
    // }
  } else {
    if (clockwise) {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
#else
      tap_code(KC_PGDN);
#endif
    } else {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
#else
      tap_code(KC_PGUP);
#endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
  case 0: {
#ifdef AUDIO_ENABLE
    static bool play_sound = false;
#endif
    if (active) {
#ifdef AUDIO_ENABLE
      if (play_sound) { PLAY_SONG(plover_song); }
#endif
      layer_on(_ADJUST);
    } else {
#ifdef AUDIO_ENABLE
      if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
      layer_off(_ADJUST);
    }
#ifdef AUDIO_ENABLE
    play_sound = true;
#endif
    break;
  }
  case 1:
    if (active) {
      muse_mode = true;
    } else {
      muse_mode = false;
    }
  }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
  if (muse_mode) {
    if (muse_counter == 0) {
      uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
      if (muse_note != last_muse_note) {
        stop_note(compute_freq_for_midi_note(last_muse_note));
        play_note(compute_freq_for_midi_note(muse_note), 0xF);
        last_muse_note = muse_note;
      }
    }
    muse_counter = (muse_counter + 1) % muse_tempo;
  } else {
    if (muse_counter) {
      stop_all_notes();
      muse_counter = 0;
    }
  }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
  // case RAISE:
  // case LOWER:
  //   return false;
  default:
    return true;
  }
}
