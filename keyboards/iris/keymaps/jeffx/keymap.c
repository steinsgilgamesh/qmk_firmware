#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LW 1
#define _RS 2
#define _FN 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LSHIFT | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LCTRL  | Z      | X      | C      | V      | B      | PLAY   |    | ????   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | LOWER  | RAISE  | ?????  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_QWERTY] = LAYOUT( 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  ,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      KC_MNXT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
                                        KC_LGUI, KC_LALT, KC_SPC,       MO(_LW), MO(_RS), MO(_FN)
 ),


  /* LOWER 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LSHIFT | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LCTRL  | Z      | X      | C      | V      | B      | PLAY   |    | ????   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | LOWER  | RAISE  | ?????  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_LW] = LAYOUT( 
    _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, KC_MINS, KC_EQL,  _______ ,  
    _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, KC_MINS, KC_EQL,  _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_MINS, KC_EQL,  _______ ,  
    _______, _______, _______, _______, _______, _______, _______       _______, _______, _______, _______, KC_MINS, KC_EQL,  _______ ,  
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______ 








    _______, _______, _______, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  ,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      KC_MNXT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
                                        KC_LGUI, KC_LALT, KC_SPC,       MO(_LW), MO(_RS), MO(_FN)
 ),

  [_LW] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL ,    ,LEFT,RGHT, UP ,LBRC,               RBRC, P4 , P5 , P6 ,PLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     RPRN,RCBR, P1 , P2 , P3 ,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,DEL ,         DEL ,    , P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_RS] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,VOLU,PGUP,UNDS,               EQL ,HOME,    ,    ,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,MINS,    ,         ,PLUS,END ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_FN] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RTOG,RMOD,RHUI,RSAI,RVAI,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,DBUG,RHUD,RSAD,RVAD,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,RST ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};
