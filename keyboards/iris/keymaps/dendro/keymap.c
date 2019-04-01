#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "pincontrol.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  , BSPC,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  , DEL ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  , SCLN, QUOT,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    LSFT, Z  , X  , C  , V  , B  , SPC ,     ENT , N  , M  , COMM, DOT , SLSH, RGHT,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
    LCTL, LOWR, SPC ,         ENT , LGUI, LALT
    //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    TILD, EXLM, AT , HASH, DLR , PERC,               CIRC, AMPR, ASTR, LPRN, RPRN, BSPC,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    RST , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    DEL ,    , LEFT, RGHT, UP , LBRC,               RBRC, P4 , P5 , P6 , PLUS, PIPE,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    BL_S,    ,    ,    , DOWN, LCBR, LPRN,     RPRN, RCBR, P1 , P2 , P3 , MINS,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
    ,    , DEL ,         DEL ,    , P0
    //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 , F10 , F11 ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    , EXLM, AT , HASH, DLR , PERC,               CIRC, AMPR, ASTR, LPRN, RPRN,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
    , MPRV, MNXT, VOLU, PGUP, UNDS,               EQL , HOME,    ,    ,    , BSLS,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
    MUTE, MSTP, MPLY, VOLD, PGDN, MINS,    ,         , PLUS, END ,    ,    ,    ,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
    ,    ,    ,             ,    ,
    //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = KEYMAP(
    //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
    _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
    _______, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
    BL_STEP, RESET  , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
    _______, _______, _______,                  _______, _______, _______
    //                                `--------+--------+--------'                `--------+--------+--------'
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(tone_qwerty);
#endif
      persistent_default_layer_set(1UL << _QWERTY);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    } else {
      layer_off(_ADJUST);
    }
    return false;
    break;
  }
  return true;
}



#define ENC_RD  PINF  //encoder port read
#define ENC_CTL DDRF  //encoder port control
#define ENC_WR  PORTF //encoder port write  
#define ENC_PIN_A PF4  // 
#define ENC_PIN_B PF5  //


void matrix_init_user(void) {

  pinMode(ENC_PIN_A, PinDirectionInput);
  pinMode(ENC_PIN_B, PinDirectionInput);

  //turn on pullups
  ENC_WR |= (( 1 << ENC_PIN_A ) | ( 1 << ENC_PIN_B ));

}
int encA, encB;
int oldencA = 0;
int oldencB = 0;
int encCCW = 0;
int encCW = 0;
int counts = 0;
int pulsesPerStep = 1;

static uint8_t prevState = 0;

uint8_t cwRotorState[4] = {0x10, 0x00, 0x11, 0x01};
uint8_t ccwRotorState[4] = {0x01, 0x11, 0x00, 0x10};

uint8_t State (void) {
  return (((PINF >> ENC_PIN_B) & 0x01) | (((PINF >> ENC_PIN_A) & 0x01) << 1));
}

int enc_read(void) {
// returns change in encoder state (-1: ccw, 0: no change, 1: cw)
  int result = 0;
  static int bufferedCounts = 0;
  uint8_t startState = State(); // Get current state
  //_delay_ms(5); // Wait safety bounce time
  uint8_t stopState = State(); // Get current state
  if ((startState == stopState) && (stopState != prevState)) { // check if the previous state was stable
    if (stopState == cwRotorState[prevState]) {
      bufferedCounts++;
    } else if (stopState == ccwRotorState[prevState]) {
      bufferedCounts--;
    }
    prevState = stopState; // Record state for next pulse interpretation
    if (abs(bufferedCounts) == pulsesPerStep) {
      result = (bufferedCounts / pulsesPerStep);
      bufferedCounts = 0;
    }
  }
  return (result);
}


void matrix_scan_user(void) {

  int encoder = enc_read();
  if (encoder) {
    counts += encoder;
  }

  while (counts < 0) {
    register_code(KC_DOWN);
    unregister_code(KC_DOWN);
    counts++;
  }
  while (counts > 0) {
    register_code(KC_UP);
    unregister_code(KC_UP);
    --counts;
  }
}


