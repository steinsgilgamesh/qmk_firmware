#include "kb.h"

//--keymap-start
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 	KC_PSCR, 	KC_NO, 	KC_F7, 	KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 
		KC_ESC, 	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 	KC_NO, 		KC_NO, 	KC_Y, 	KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_BSPC, 
		KC_TAB, 	KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_G, 	KC_LALT, 	KC_INS, KC_H, 	KC_J, 		KC_K, 		KC_UP,		KC_L, 		KC_ENT, 
		KC_LSFT,	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 										KC_N, 	KC_M, 		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 	MO(2), 
												KC_LGUI,	KC_LALT, 	KC_LCTL,	MO(1), 										KC_SPC, KC_RGUI,	KC_PGUP, 	KC_PGDN),

	KEYMAP(
		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 	KC_NO, 		KC_NO, 	KC_NO, 		KC_NO, 		KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 
		KC_ESC,   KC_7,    	KC_8,    	KC_9,    	KC_0,   	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 		KC_LBRC, 	KC_RBRC, 	KC_MINS, 	KC_EQL, 	KC_TRNS, 
		KC_TAB,   KC_4,    	KC_5,    	KC_6, 		KC_NO, 		KC_NO, 	KC_LALT, 	KC_NO, 	KC_NO,		KC_GRV, 	KC_SCLN, 	KC_QUOT, 	KC_BSLS,  KC_TRNS, 
		KC_LSFT,  KC_1,    	KC_2,    	KC_3, 		KC_NO, 		KC_NO,										KC_NO, 		KC_NO,		KC_COMM,  KC_DOT, 	KC_SLSH, 	KC_TRNS,
												KC_LGUI,	KC_LALT, 	KC_LCTL,	KC_TRNS,									KC_SPC, 	KC_RGUI, 	KC_INS, 	KC_DEL),

	KEYMAP(
		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 	KC_NO, 		KC_NO, 	KC_NO, 		KC_NO, 		KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 
		KC_ESC,   KC_F9,  	KC_F10,  	KC_F11,  	KC_F12, 	KC_NO,	KC_NO, 		KC_NO, 	KC_NO, 		KC_NO, 		KC_RBRC, 	KC_MINS, 	KC_EQL, 	KC_TRNS, 
		KC_TAB,   KC_F5,   	KC_F6,   	KC_F7,   	KC_F8,  	KC_NO, 	KC_LALT, 	KC_NO, 	KC_NO,		KC_NO, 		KC_HOME, 	_______, 	KC_END,  	KC_TRNS, 
		KC_LSFT,  KC_F1,   	KC_F2,   	KC_F3,   	KC_F4,  	KC_NO,										KC_NO, 		KC_NO,		C(KC_LEFT),_______,C(KC_RGHT), KC_TRNS,
												KC_LGUI,	KC_LALT, 	KC_LCTL,	KC_TRNS,									KC_SPC, 	KC_RGUI, 	KC_PGUP, 	KC_PGDN),

	// KEYMAP(
	// 	KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_TRNS, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F6, KC_TRNS, KC_TRNS, KC_F7, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


};
//--keymap-end

//--macro-start
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}
//--macro-end

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}