#include QMK_KEYBOARD_H
#include "keymap_jp.h"

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
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  LOWER,
  RAISE,
  KANJI,
};

// enum tapdances{
//   TD_CODO = 0,
//   TD_SLRO,
// };

// Layer Mode aliases
// #define KC_LOWER LOWER
// #define KC_RAISE RAISE
// #define KC_MLLO  MO(_LOWER)
// #define KC_MLRA  MO(_RAISE)
#define KC_MLAD  MO(_ADJUST)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

// Adjust layer keys
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

// Base layer mod tap
#define KC_A_SF  LSFT_T(KC_A)
#define KC_Z_CT  LCTL_T(KC_Z)
#define KC_X_AL  LALT_T(KC_X)
#define KC_C_GU  LGUI_T(KC_C)
#define KC_SSCT  LCTL_T(KC_SLSH)
#define KC_ENSF  LSFT_T(KC_ENT)

// Lower layer mod tap
#define KC_F6SF  LSFT_T(KC_F6)
#define KC_BSSF  LSFT_T(KC_BSLS)
#define KC_11CT  LCTL_T(KC_F11)
#define KC_12AL  LALT_T(KC_F12)

// Layer tap
#define KC_BSLO  LT(_LOWER, KC_BSPC)
#define KC_SPRA  LT(_RAISE, KC_SPC)

// Tap dance
// #define KC_CODO  TD(TD_CODO)
// #define KC_SLRO  TD(TD_SLRO)

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
//   [TD_SLRO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RO),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P, \
  //|------+------+------+------+------+------+------+------+------+------|
       A_SF,     S,     D,     F,     G,     H,     J,     K,     L,  ENSF, \
  //|------+------+------+------+------+------+------+------+------+------|
       Z_CT,  X_AL,  C_GU,     V,     B,     N,     M,  COMM,   DOT,  SSCT, \
  //`------+------+------+------+------+------+------+------+------+------'
                                   BSLO,  SPRA \
  //                            `------|------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
         F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  JYEN,  LBRC,  RBRC,\
  //|------+------+------+------+------+------+------+------+------+------|
       F6SF,    F7,    F8,    F9,   F10, XXXXX, XXXXX,  SCLN,  QUOT,  BSSF,\
  //|------+------+------+------+------+------+------+------+------+------|
       11CT,  12AL,   ESC,   TAB, KANJI,   DEL, XXXXX, XXXXX, XXXXX,    RO,\
  //`------+------+------+------+------+------+------+------+------+------'
                                  _____,  MLAD \
  //                            `------|------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
          1,     2,     3,     4,     5,     6,     7,     8,     9,     0,\
  //|------+------+------+------+------+------+------+------+------+------|
       LSFT, XXXXX, XXXXX, XXXXX, XXXXX,  LEFT,  DOWN,    UP,  RGHT,  LSFT,\
  //|------+------+------+------+------+------+------+------+------+------|
       LCTL,  LALT,  LGUI, XXXXX, XXXXX,  MINS,    RO,  COMM,   DOT,  SSCT,\
  //`------+------+------+------+------+------+------+------+------+------'
                                  _____, _____ \
  //                            `------|------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------+------+------+------|
       LTOG,  LHUI,  LSAI,  LVAI, XXXXX,  MS_L,  MS_D,  MS_U,  MS_R, XXXXX,\
  //|------+------+------+------+------+------+------+------+------+------|
       LMOD,  LHUD,  LSAD,  LVAD, XXXXX,  BTN1,  BTN2, XXXXX, XXXXX, XXXXX,\
  //`------+------+------+------+------+------+------+------+------+------'
                                  _____, _____ \
  //                            `------|------'
  )
};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case KC_BSLO:
      return TAPPING_LAYER_TERM;
    case KC_SPRA:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}
