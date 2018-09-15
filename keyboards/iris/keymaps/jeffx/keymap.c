#include QMK_KEYBOARD_H
#include "pincontrol.h"

extern keymap_config_t keymap_config;

#define _QW 0
#define _GM 1
#define _LW 2
#define _RS 3
#define _GF 4
#define _FN 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

//Tap Dance Declarations
enum {
  TD_HOME= 0,
  TD_GAME= 1
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_HOME]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_RGUI, _QW),
  [TD_GAME]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_RGUI, _GM)
// Other declarations would go here, separated by commas, if you have them
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define LM_FNOS LM(_FN, MOD_BIT(KC_LGUI))
#define ALT_FN LM(_FN, MOD_BIT(KC_LALT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY // Default layer - occasionally 'swaps' with Gaming layer
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PLAY   |    | FUNC   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS/FN  | ALT    | SPACE  |    | LOWER  | RAISE  | OS/_GM |
 *                                     '--------------------------'    '--------------------------'
 */

 [_QW] = LAYOUT( 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  ,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      MO(_FN), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
                                        KC_LGUI, ALT_FN,  KC_SPC,       MO(_LW), MO(_RS), TD(TD_GAME) 
 ),


  /* GAMING // This keyboard has number keys so it doesn't really need a gaming layer, but a left-handed FN key is useful here.
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      |                      | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PLAY   |    | FUNC   | N      | M      | ,      | .      | /      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | FUNC   | ALT    | SPACE  |    | LOWER  | RAISE  | OS/_QW |
 *                                     '--------------------------'    '--------------------------'
 */

 [_GM] = LAYOUT( 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC ,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL  ,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT  ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MPLY,      MO(_FN), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
                                        MO(_GF), KC_LALT, KC_SPC,       MO(_LW), MO(_RS), TD(TD_HOME) 
 ),

  /* LOWER 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      |                      | H      | -      | =      | L      | '      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PLAY   |    | FUNC   | N      | M      | [      | ]      | \      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | LOWER  | RAISE  | ?????  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_LW] = LAYOUT( 
    KC_GRV,  _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, KC_MINS, KC_EQL,  _______, KC_QUOT, _______ ,  
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 ),
 
 
  /* RAISE 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * | GRAVE  | 1      | 2      | 3      | 4      | 5      |                      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |                      | Y      | U      | I      | O      | P      | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      |                      | H      | _      | +      | L      | ""     | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PLAY   |    | FUNC   | N      | M      | {      | }      | |      | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     | OS     | ALT    | SPACE  |    | LOWER  | RAISE  | ?????  |
 *                                     '--------------------------'    '--------------------------'
 */

 [_RS] = LAYOUT( 
    KC_TILD, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, KC_UNDS, KC_PLUS, _______, KC_DQUO, _______ ,  
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 ),


  /* GAMING FUNCTION 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |                      |        |        |        |        |        | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * |        |        | W      |        |        |        |                      |        | PGDN   | PGUP   |        |        | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * |        | A      | S      | D      |        |        |                      | LEFT   | DOWN   | UP     | RIGHT  |        | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |    |        |        |        |        |        |        | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     |        |        |        |    |        |        |        |
 *                                     '--------------------------'    '--------------------------'
 */

 [_GF] = LAYOUT( 
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          _______, _______, _______, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        _______, KC_PGDN, KC_PGUP, _______, _______, _______ ,  
    _______, _______, _______, _______, _______, _______,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ ,  
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 ),


  /* FUNCTION 
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |                      |        |        |        |        |        | BACKSP |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+-----------------|
 * |        | F6     | F7     | F8     | F9     | F10    |                      |        | PGDN   | PGUP   |        |        | DEL    |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+-----------------+--------|
 * |        |        |        |        | F11    | F12    |                      | LEFT   | DOWN   | UP     | RIGHT  |        | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |    |        |        |        |        |        |        | RSHIFT |
 * '-----------------------------------+--------+--------+--------|    |--------+--------+--------+-----------------------------------'
 *                                     |        |        |        |    |        |        |        |
 *                                     '--------------------------'    '--------------------------'
 */

 [_FN] = LAYOUT( 
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          _______, _______, _______, _______, _______, _______ ,  
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                         _______, KC_PGDN, KC_PGUP, _______, _______, _______ ,  
    _______, RGB_MOD, RGB_HUI, RGB_SAI, KC_F11,  KC_F12,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ ,  
    _______, BL_STEP, RGB_VAI, RGB_VAD, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______ ,  
                                        _______, _______, _______,      _______, _______, _______ 
 )


};

#define ENC_RD	PINF	//encoder port read
#define ENC_CTL	DDRF	//encoder port control
#define ENC_WR	PORTF	//encoder port write	
#define ENC_PIN_A PF4  // 
#define ENC_PIN_B PF5  //

 
void matrix_init_user(void) {

  pinMode(ENC_PIN_A, PinDirectionInput);
  pinMode(ENC_PIN_B, PinDirectionInput);

  //turn on pullups
  ENC_WR |= (( 1<<ENC_PIN_A )|( 1<<ENC_PIN_B ));

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
	return(((PINF >> ENC_PIN_B) & 0x01) | (((PINF >> ENC_PIN_A) & 0x01) << 1));
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
		}
		else if (stopState == ccwRotorState[prevState]) {
			bufferedCounts--; 
		}
		prevState = stopState; // Record state for next pulse interpretation
		if (abs(bufferedCounts) == pulsesPerStep) {
			result = (bufferedCounts / pulsesPerStep);
			bufferedCounts = 0;
		}
	}
	return(result);
}


void matrix_scan_user(void) {

	int encoder = enc_read();
	if (encoder) {
		counts += encoder;
	} 

    while (counts < 0)
    {
  register_code(KC_DOWN);
  unregister_code(KC_DOWN);
  counts++;
    }
    while (counts > 0)
    {
  register_code(KC_UP);
  unregister_code(KC_UP);
  --counts;
    }
  }




