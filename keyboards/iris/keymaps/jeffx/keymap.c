#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QW 0
#define _LW 1
#define _RS 2
#define _FN 3 

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

//Tap Dance Declarations
enum {
  TD_TEST= 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_TEST]  = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT)
// Other declarations would go here, separated by commas, if you have them
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define LM_FNOS LM(_FN, MOD_BIT(KC_LGUI))

bool fn_held;
void dance_layers(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->pressed)
  {
    layer_on(_LW);
    fn_held = true;
  }
  switch (state->count)
  {
  case 1: //off all layers, just base on
    if (!state->pressed)
    {
      layer_off(_LW);
      layer_off(_FN);
      fn_held = false;
    }
    break;
  case 2: //function layer on
    layer_on(_FN);
    layer_off(_LW);
    break;
  }
}
void dance_layers_finish(qk_tap_dance_state_t *state, void *user_data)
{
  if (fn_held)
  {
    layer_off(_LW);
    fn_held = false;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PLAY   |    | ????   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS/FN  | ALT    | SPACE  |    | LOWER  | RAISE  | FUNC   |
 *                                     '--------------------------'    '--------------------------'
 */

 [_QW] = LAYOUT( 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  ,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      KC_MNXT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
                                        LM_FNOS, KC_LALT, KC_SPC,       MO(_LW), MO(_RS), TG(_FN) 
 ),


  /* LOWER 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | -      |                      | =      | -      | K      | '      | \      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | [      | PLAY   |    | ????   | ]      | =      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | FN     | LOWER  | RAISE  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_LW] = LAYOUT( 
    KC_GRV,  _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, KC_MINS,                        KC_EQL,  KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS, _______ ,  
    _______, _______, _______, _______, _______, KC_LBRC, _______,      _______, KC_RBRC, KC_EQL,  KC_LBRC, KC_RBRC, KC_SLSH, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 ),
 
 
  /* RAISE 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | _      |                      | +      | J      | K      | ""     | |      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | {      | PLAY   |    | ????   | }      | M      | <      | >      | ?      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | FN     | LOWER  | RAISE  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_RS] = LAYOUT( 
    KC_TIL,  _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, KC_UNDS,                        KC_PLUS, KC_UNDS, KC_PLUS, KC_DQUO, KC_PIPE, _______ ,  
    _______, _______, _______, _______, _______, KC_LCBR, _______,      _______, KC_RCBR, _______, KC_LCBR, KC_RCBR, KC_QUES, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 ),


  /* FUNCTION 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | F1     | F2     | F3     | F4     | F5     |                      | Y      | PGDN   | PGUP   |        |        | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | F6     | F7     | F8     | F9     | F10    |                      | LEFT   | DOWN   | UP     | RIGHT  |        | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | F11    | F12    | PLAY   |    | ????   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | FN     | LOWER  | RAISE  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_FN] = LAYOUT( 
    _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                        _______, _______, _______, KC_UNDS, KC_PLUS, _______ ,  
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          _______, KC_PGDN, KC_PGUP, KC_LCBR, KC_RCBR, _______ ,  
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                         KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PIPE, _______ ,  
    _______, BL_TOGG, BL_STEP, RGB_TOG, KC_F11,  KC_F12,  _______,      _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 )
 
};
