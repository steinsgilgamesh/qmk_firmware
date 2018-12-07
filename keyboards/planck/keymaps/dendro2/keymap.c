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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  //_COLEMAK,
  //_DVORAK,
  _NUMPAD,
  _LOWER,
  _RAISE,
  //_PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  //COLEMAK,
  //DVORAK,
  //PLOVER,
  NUMPAD,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   *
  [_QWERTY] = {
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
    {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },*/

  [_QWERTY] = {
    {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_GRV,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
    {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,  KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT},
    {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_CAPS, KC_RGUI, KC_N,    KC_M,    KC_HOME, KC_UP,   KC_END},
    {KC_LSFT, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, LOWER,   RAISE,   KC_SPC,  NUMPAD,  KC_LEFT, KC_DOWN, KC_RGHT}
  },


  /* Colemak
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   *
  [_COLEMAK] = {
    {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
    {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  */
  /* Dvorak
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   *
  [_DVORAK] = {
    {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
    {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
    {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
    {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  },
  */

  /* NUMPAD
  */
  [_NUMPAD] = {
    {_______, _______,    KC_7,    KC_8,    KC_9,    KC_ESC,  KC_GRV,   _______,  _______,  _______,  _______,  _______},
    {_______, _______,    KC_4,    KC_5,    KC_6,    KC_TAB,  KC_BSPC,  _______,  _______,  _______,  _______,  _______},
    {_______, _______,    KC_1,    KC_2,    KC_3,    KC_CAPS, KC_RGUI,  _______,  _______,  _______,  KC_PGUP,  _______},
    {KC_LSFT, KC_LALT,    KC_LGUI, KC_0,    KC_LCTL, _______, _______,  KC_SPC,   _______,  _______,  KC_PGDN,  _______}
  },


  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */

  /*
  [_RAISE] = {
    {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN},
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_DEL,  KC_COLN, KC_DQT,  KC_LCBR,  KC_RCBR,  KC_PIPE},
    {KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, S(KC_NUHS), S(KC_NUBS), KC_LT, KC_GT,  KC_QUES},
    {KC_LSFT, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______, _______, KC_SPC, KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY}
  },

  */
  /*
  [_RAISE] = {
    {_______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_F7,    KC_F8,    _______,  KC_LCBR,  KC_RCBR,  KC_PIPE,   _______},
    {KC_TAB,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_F9,    KC_F10,   KC_COLN,  KC_DQT,   KC_UNDS,  KC_PLUS,   KC_BSPC},
    {_______, _______, KC_ASTR, KC_LPRN, KC_RPRN, KC_F11,   KC_F12,   KC_LT,    KC_GT,    KC_QUES,  KC_VOLU,   KC_MPLY },
    {KC_LSFT, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______,  _______,  KC_SPC,   KC_MUTE,  KC_MPRV,  KC_VOLD,   KC_MNXT}
  },
  */

  [_RAISE] = {
    {_______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F7,    KC_F8,    KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_PLUS,  _______},
    {KC_TAB,  KC_DLR,  KC_PERC, KC_CIRC, _______, KC_F9,    KC_F10,   _______,  KC_COLN,  KC_DQT,   KC_PIPE,  KC_BSPC},
    {_______, KC_EXLM, KC_AT,   KC_HASH, _______, KC_F11,   KC_F12,   _______,  KC_LT,    KC_GT,    KC_QUES,  KC_MUTE},
    {KC_LSFT, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, _______,  _______,  KC_SPC,   _______,  KC_MPRV,  KC_MPLY,  KC_MNXT}
  },


  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  /*
  [_LOWER] = {
    {_______, KC_1,     KC_2,    KC_3,    _______,  KC_F1,    KC_F2,    _______,  KC_LBRC,  KC_RBRC,  KC_BSLS, _______},
    {KC_TAB,  KC_4,     KC_5,    KC_6,    KC_7,     KC_F3,    KC_F4,    KC_SCLN,  KC_QUOT,  KC_MINS, KC_EQL,   KC_DEL},
    {_______, _______,  KC_8,    KC_9,    KC_0,     KC_F5,    KC_F6,    KC_COMM,  KC_DOT,   KC_SLSH, KC_PGUP,  KC_INS},
    {KC_LSFT, KC_LALT,  KC_LGUI, KC_LSFT, KC_LCTL,  _______,  _______,  KC_SPC,   KC_PSCR,  KC_SLCK, KC_PGDN,  KC_PAUS}
  },
  */

  [_LOWER] = {
    {_______, KC_7,     KC_8,    KC_9,    KC_0,     KC_F1,    KC_F2,    KC_LBRC,  KC_RBRC,  KC_MINS, KC_EQL,   _______},
    {KC_TAB,  KC_4,     KC_5,    KC_6,    _______,  KC_F3,    KC_F4,    _______,  KC_SCLN,  KC_QUOT, KC_BSLS,  KC_DEL},
    {_______, KC_1,     KC_2,    KC_3,    _______,  KC_F5,    KC_F6,    _______,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_INS},
    {KC_LSFT, KC_LALT,  KC_LGUI, KC_LSFT, KC_LCTL,  _______,  _______,  KC_SPC,   _______,  KC_PSCR,  KC_SLCK, KC_PAUS}
  },

  /* Plover layer (http://opensteno.org)
   * ,-----------------------------------------------------------------------------------.
   * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
   * `-----------------------------------------------------------------------------------'
   *

  [_PLOVER] = {
    {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
    {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
    {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
  },*/

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   *
  [_ADJUST] = {
    {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
    {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
    {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }*/
  [_ADJUST] = {
    {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
    {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______},
    {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
    {BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }

};

#ifdef AUDIO_ENABLE
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      print("mode just switched to qwerty and this is a huge string\n");
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  /*case COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;
    break;
  case DVORAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_DVORAK);
    }
    return false;
    break;*/
  case NUMPAD:
    if (record->event.pressed) {
      layer_on(_NUMPAD);
      //backlight_level(128);
    } else {
      //backlight_level(0);
      layer_off(_NUMPAD);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      //backlight_level(64);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      //backlight_level(0);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      //backlight_level(32);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      //backlight_level(0);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case BACKLIT:
    if (record->event.pressed) {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
      PORTE &= ~(1 << 6);
    } else {
      unregister_code(KC_RSFT);
      PORTE |= (1 << 6);
    }
    return false;
    break;
    /*
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
      */
  }
  return true;
}

/*
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        keycaps_led_on();
    } else {
        keycaps_led_off();
    }
    if (some_custom_state) {
      gp100_led_on();
    }
    else {
      gp100_led_off();
    }
};
*/