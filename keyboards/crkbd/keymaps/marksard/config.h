/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT

#define SSD1306OLED

#define USE_SERIAL_PD2

#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 225
#define PREVENT_STUCK_MODIFIERS
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef MOUSEKEY_ENABLE
  #undef MOUSEKEY_INTERVAL
  #define MOUSEKEY_INTERVAL 1

  #undef MOUSEKEY_TIME_TO_MAX
  #define MOUSEKEY_TIME_TO_MAX 150

  #undef MOUSEKEY_MAX_SPEED
  #define MOUSEKEY_MAX_SPEED 3

  #undef MOUSEKEY_MOVE_DELTA
  #define MOUSEKEY_MOVE_DELTA 4

  #undef MOUSEKEY_DELAY
  #define MOUSEKEY_DELAY 0
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
//   #define RGBLIGHT_ANIMATIONS
  #define RGBLED_NUM 27
  #define RGBLIGHT_LIMIT_VAL 150
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8

// Selection of RGBLIGHT MODE to use.
  //#define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  //#define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  //#define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  //#define RGBLIGHT_EFFECT_RGB_TEST
  //#define RGBLIGHT_EFFECT_ALTERNATING
#endif

#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
  // #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
  // #define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
  // #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
  // #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
  #define RGB_MATRIX_HUE_STEP 8
  #define RGB_MATRIX_SAT_STEP 8
  #define RGB_MATRIX_VAL_STEP 8
  #define RGB_MATRIX_SPD_STEP 10

//   #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_BAND_SAT
//   #define DISABLE_RGB_MATRIX_BAND_VAL
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//   #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//   #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  // #define DISABLE_RGB_MATRIX_CYCLE_ALL
//   #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//   #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
//   #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
  // #define DISABLE_RGB_MATRIX_DUAL_BEACONzasd
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//   #define DISABLE_RGB_MATRIX_RAINDROPS
//   #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

//   #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  // #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
  #define DISABLE_RGB_MATRIX_DIGITAL_RAIN

  #define RGB_MATRIX_KEYPRESSES  // reacts to keypresses

  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

  // #define DISABLE_RGB_MATRIX_SPLASH
  #define DISABLE_RGB_MATRIX_MULTISPLASH
  #define DISABLE_RGB_MATRIX_SOLID_SPLASH
  #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

//   #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP
#endif