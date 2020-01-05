/* Copyright 2020 marksard
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
#include "keymap_jp.h"
#include "./common/oled_helper.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NUMPAD,
  KANJI,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST
};

enum tapdances{
  TD_CODO = 0,
  // TD_MNUB,
};

// Layer Mode aliases
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_DLNP NUMPAD //DF(_NUMPAD)
#define KC_DLBS BASE //DF(_BASE)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_ZSFT  LSFT_T(KC_Z)
#define KC_MNSF  LSFT_T(KC_MINS)
#define KC_ESCT  LCTL_T(KC_ESC)
#define KC_TBAL  LALT_T(KC_TAB)
#define KC_11SF  LSFT_T(KC_F11)
#define KC_ALAP  LALT_T(KC_APP)
#define KC_JEQL  LSFT(KC_MINS)
#define KC_WLCK  LALT(KC_L)
#define KC_SFEQ  LSFT(KC_MINS)
#define KC_SFPL  LSFT(KC_SCLN)
#define KC_SFAS  LSFT(KC_QUOT)

#define KC_CODO  TD(TD_CODO)
// #define KC_MNUB  TD(TD_MNUB)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
  // [TD_MNUB] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_RO)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,\
  //|------+------+------+------+------|------+------+------+------+------|
          A,     S,     D,     F,     G,     H,     J,     K,     L,   ENT,\
  //|------+------+------+------+------|------+------+------+------+------|
       ZSFT,     X,     C,     V,     B,     N,     M,  CODO,    UP,  MNSF,\
  //|------+------+------+------+------|------+------+------+------+------|
       ESCT,  TBAL,  LGUI, LOWER,  BSPC,   SPC, RAISE,  LEFT,  DOWN,  RGHT \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_NUMPAD] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         P7,    P8,    P9,  PAST,  NLCK,    P7,    P8,    P9,  PAST,  NLCK,\
  //|------+------+------+------+------|------+------+------+------+------|
         P4,    P5,    P6,  PMNS,  PSLS,    P4,    P5,    P6,  PMNS,  PSLS,\
  //|------+------+------+------+------|------+------+------+------+------|
         P1,    P2,    P3,  PPLS,  QUOT,    P1,    P2,    P3,  PPLS,  QUOT,\
  //|------+------+------+------+------|------+------+------+------+------|
       DLBS,    P0,  PDOT,  SFEQ,  BSPC,  DLBS,    P0,  PDOT,  SFEQ,  BSPC \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  LBRC,  RBRC,  BSLS,\
  //|------+------+------+------+------|------+------+------+------+------|
         F6,    F7,    F8,    F9,   F10, XXXXX, XXXXX, XXXXX,  SCLN,  QUOT,\
  //|------+------+------+------+------|------+------+------+------+------|
       11SF,   F12,  DLNP, KANJI,   ENT, XXXXX, XXXXX,  COMM,   DOT,   GRV,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,   DEL, _____, _____, _____, _____, _____ \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_RAISE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          1,     2,     3,     4,     5,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------|------+------+------+------+------|
       EXLM,    AT,  HASH,   DLR,  PERC,  CIRC, AMPR,   ASTR,  LPRN,  RPRN,\
  //|------+------+------+------+------|------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  PGUP, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, _____, _____, _____,  BSPC,  WLCK, _____,  HOME,  PGDN,   END \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP,  CAPS, XXXXX,  WH_L,  WH_U,  HOME,  PGUP,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI,  SLCK, XXXXX,  WH_R,  WH_D,   END,  PGDN,\
  //|------+------+------+------+------|------+------+------+------+------|
      LMOD,  LHUD,  LSAD,  LVAD,  NLCK, XXXXX,  BTN1,  BTN2,  MS_U, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
       LSFT, _____, _____, _____, XXXXX, XXXXX, _____,  MS_L,  MS_D,  MS_R \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};

#define L_BASE _BASE
#define L_NUMPAD (1<<_NUMPAD)
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#include <string.h>

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 6
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_NUMPAD, "Numpad"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(void) {

  oled_write(layer_status_buf, false);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()

static inline void render_status(void) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS();
  render_keymap_status();
  UPDATE_LOCK_STATUS();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void oled_task_user(void) {

  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
}

#else

#define UPDATE_KEYMAP_STATUS()

#endif

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        default_layer_set(L_BASE);
      }
      break;
    case NUMPAD:
      if (record->event.pressed) {
        default_layer_set(L_NUMPAD);
      }
      break;
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            rgblight_mode(0);
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  UPDATE_KEYMAP_STATUS();
  return result;
}
