/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "xd75.h"

/* Fillers to make layering more clear */
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

/* Layer shorthand */

enum layers {
  _QWERTY = 0,  /* Qwerty mapping */
  _LOWER, /* Lower layer, where top line has symbols !@#$%^&*() */
  _RAISE, /* Raised layer, where top line has digits 1234567890 */
  _ADJUST, /* Special Adjust layer coming via tri-placement */
  _FUNCTION /* Function key layer */  
};


/* Macros need to be uniquely identified; using an enum to do this
   automatically
 */

enum macro_id {
  M_LED = 0,
  M_USERNAME,
  M_RANDDIGIT,
  M_RANDLETTER,
  M_VERSION,
  MACRO_UPPER,
  MACRO_LOWER,
};

/* I want some short forms for keycodes so that they fit into
   limited-width cells */

#define M_LOWER M(MACRO_LOWER)
#define M_UPPER M(MACRO_UPPER)
#define ROT_LED M(M_LED)   /* Rotate LED */
#define QWERTY DF(_QWERTY)   /* Switch to QWERTY layout */
#define QCENT2 DF(_QCENT2)   /* Switch to QWERTY-with-centre layout */
#define USERNAME M(M_USERNAME) /* shortcut for username */
#define RANDDIG M(M_RANDDIGIT)
#define RANDALP M(M_RANDLETTER)
#define CTLENTER MT(MOD_RCTL, KC_ENT)
#define SHIFTQUOTE MT(MOD_RSFT, KC_QUOT)
#define ALTRIGHT MT(MOD_LALT, KC_RGHT)
#define MVERSION M(M_VERSION)
#define ALTSLASH LALT(KC_SLSH)
#define FUNCTION MO(_FUNCTION)
#define MRAISE MO(_RAISE)
#define MLOWER MO(_LOWER)
#define ALTBSP ALT_T(KC_BSPC)

/* More modifiers for QCENT2... */
#define PALT MT(KC_RALT, KC_P)
#define SCTL MT(KC_RCTL, KC_SCLN)
#define SSHF MT(KC_RSFT, KC_SLSH)
  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* layout for centred keypad + qwerty...

|ESC| 1 | 2 | 3 | 4 | 5 | ? | ? | ? | ? | 6 | 7 | 8 | 9 | 0 |
|TAB| q | w | e | r | t | ? | ? | ? | ? | y | u | i | o | p |
|CTL| a | s | d | f | g | ? | ? | ? | ? | h | j | k | l | ; |
|SHF| z | x | c | v | b | ? | ? | ? | ? | n | m | , | . | / |
|ALT|LED|   |   |   |   |   |   |   |   |   |   |   |   |   |




keys needing to be assigned:
11 - KC_TAB - tab
52 - ROT_LED - rotate LED
15 - KC_LALT - Left ALT
   - KC_LGUI  - this is the windows/command key, which I think I do not use...
   - M_LOWER - switch to LOWER layer 
   - KC_SPC - space
   - M_UPPER - switch to UPPER layer, maybe unneeded for 15x5
   - KC_LEFT - famous arrows
   - KC_DOWN - famous arrows
   - KC_UP - famous arrows
   - KC_RIGHT - famous arrows
   - KC_ENT - enter
   - KC_GRV - leftwards quote
   - KC_QUOT - rightwards quote
   - KC_BSPC - backspace
   - KC_ESC

Missing still...  
   KC_LBRC and KC_LCBR
   KC_RBRC and KC_RCBR

  */  
   [_QWERTY] = { /* QWERTY, with keypad in the centre */
     { KC_ESC,  KC_1,     KC_2,    KC_3,      KC_4,    KC_5,    KC_ESC,   KC_INS,   KC_DEL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_PGUP },
     { KC_GRV,  KC_Q,     KC_W,    KC_E,      KC_R,    KC_T,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_PGDN },
     { KC_CAPS, KC_A,     KC_S,    KC_D,      KC_F,    KC_G,    KC_TAB,   KC_SCLN,  KC_BSPC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_ENTER, KC_QUOT },
     { KC_LSFT, KC_Z,     KC_X,    KC_C,      KC_V,    KC_B,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_N,    KC_M,    KC_HOME, KC_UP,   KC_END,   KC_RCTL },
     { KC_LALT, KC_INS,   KC_EQL,  KC_MINS,   KC_LCTL, KC_SPC,  MRAISE,   KC_LGUI,  MLOWER,   KC_SPC,  KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT,  KC_RALT }
   },
  
/* LOWER
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      |        |        |        | INS    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | _      | +      | {      | }      | |      | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        | XXXXXX .        |        |        |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_LOWER] = { /* LOWERED */
  // { ___T___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 },
  //{ ___T___, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_INS   },
  // { ___T___, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______ },
  // { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, ___T___, ___T___, _______ },
  //{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

/* RAISED
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      |        |        |        | INS    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | -      | =      | [      | ]      | \      | XXXXXX .        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |        | XXXXXX .        |        |        |
 * |--------+--------+--------+--------+--------+- 2u ------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | XXXXXX .        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_RAISE] = { /* RAISED */
  { BL_TOGG,   KC_F1,     KC_F2,    KC_F3,   KC_F4,   KC_F5,   _______, KC_F12, KC_F11,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  RGB_TOG },
  { BL_ON,   _______,   _______,  KC_7,    KC_8,    KC_9,    _______, _______, _______,    _______,    _______,    _______, _______, _______, RGB_MOD  },
  { BL_OFF,   _______,   _______,  KC_4,    KC_5,    KC_6,   _______, _______, _______, _______,  _______, _______, _______, ___T___, ___T___ },
  { BL_INC,   _______,   _______,  KC_1,    KC_2,    KC_3,  _______, _______, _______, _______, _______, ___T___, ___T___, _______, _______  },
  { BL_DEC,   _______,   _______,  KC_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },
 
/* FUNCTION
 * .---------------------------------------------------------------------------------------------------------------------- 2u ------------.
 * | NUM LK | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | XXXXXX .        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | SCR LK | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | F24    | PAUSE  | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------+--------|
 * | CAP LK | MS BT5 | MS BT4 | MS BT3 | MS BT2 | SLOW M | FAST M | NEXT   | VOL+   | VOL-   | PLAY   |        | XXXXXX .        | WHEEL+ |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ---------------------+--------|
 * | RGB TG | RGB MD | RGB HI | RGB HD | RGB SI | RGB SD | RGB VI | RGB VD | BL TOG | BL INC | BL DEC | XXXXXX .        | MOUS Un | WHEEL- |
 * |--------+--------+--------+--------+--------+-- 2u -----------+--------+--------+--------+--------+-----------------+--------+--------|
 * | RESET  |        | QWERTY | COLEMK | DVORAK | XXXXXX . MS BT1 |        |        |        |        |        | MOUS L | MOUS D | MOUS R |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 
 [_FUNCTION] = { /* FUNCTION */
  { KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___T___, ___T___  },
  { KC_SLCK, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PAUS, KC_PSCR  },
  { KC_CAPS, KC_BTN5, KC_BTN4, KC_BTN3, KC_BTN2, KC_ACL0, KC_ACL2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, ___T___, ___T___, KC_WH_U  },
  { RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_TOGG, BL_INC,  BL_DEC,   ___T___, ___T___, KC_MS_U, KC_WH_D  },
  { RESET  , _______, DF(_QWERTY), DF(_QWERTY), DF(_QWERTY), KC_BTN1, KC_BTN1, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R  },
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

/* This bit of logic seeds a wee linear congruential random number generator */
/* lots of prime numbers everywhere... */
static uint16_t random_value = 157;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  uint8_t clockbyte=0;
  clockbyte = TCNT1 % 256;
  uint8_t rval;
  /* MACRODOWN only works in this function */
  switch(id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
      backlight_step();
#endif
    } else {
      unregister_code(KC_RSFT);
    }
    break;
  case M_USERNAME:
    if (record->event.pressed) {
      SEND_STRING("cbbrowne");
    }
    break;
  case M_VERSION:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@");
      //      SEND_STRING(QMK_VERSION "@" QMK_BUILDDATE);
    }
    break;
  case M_RANDDIGIT:
    /* Generate, based on random number generator, a keystroke for
       a numeric digit chosen at random */
    random_value = ((random_value + randadd) * randmul) % randmod;
    if (record->event.pressed) {
      /* Here, we mix the LCRNG with low bits from one of the system
         clocks via XOR in the theory that this may be more random
         than either separately */ 
      rval = (random_value ^ clockbyte) % 10;
      /* Note that KC_1 thru KC_0 are a contiguous range */
      register_code (KC_1 + rval);
      unregister_code (KC_1 + rval);
    }
    break;
  case M_RANDLETTER:
    /* Generate, based on random number generator, a keystroke for
       a letter chosen at random */
    /* Here, we mix the LCRNG with low bits from one of the system
       clocks via XOR in the theory that this may be more random
       than either separately */ 
    random_value = ((random_value + randadd) * randmul) % randmod;
    if (record->event.pressed) {
      rval = (random_value ^ clockbyte) % 26;
      register_code (KC_A + rval);
      unregister_code (KC_A + rval);
    }
    break;
  case MACRO_UPPER:
    if (record->event.pressed)
      {
  layer_on(_RAISE);
#ifdef BACKLIGHT_ENABLE
  breathing_period_set(2);
  breathing_pulse();
#endif
  update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    else
      {
  layer_off(_RAISE);
  update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    break;
  case MACRO_LOWER:
    if (record->event.pressed)
      {
  layer_on(_LOWER);
#ifdef BACKLIGHT_ENABLE
  breathing_period_set(2);
  breathing_pulse();
#endif
  update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    else
      {
  layer_off(_LOWER);
  update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
    break;
  }
  return MACRO_NONE;
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        capslock_led_on();
    } else {
        capslock_led_off();
    }
    /*
    if (some_custom_state) {
      gp100_led_on();
    }
    else {
      gp100_led_off();
    }
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MRAISE:
      if (record->event.pressed)
      {
        gp100_led_on();
      } else {
        gp100_led_off();
      }
      return true;
    case MLOWER:
      if (record->event.pressed) {
        keycaps_led_on();
      } else {
        keycaps_led_off();
      }
      return true;
    /*
    case FOO:
      if (record->event.pressed) {
        // Do something when pressed
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case KC_ENTER:
      // Play a tone when enter is pressed
      if (record->event.pressed) {
        PLAY_NOTE_ARRAY(tone_qwerty);
      }
      return true; // Let QMK send the enter press/release events
      */
    default:
      return true; // Process all other keycodes normally
  }
};