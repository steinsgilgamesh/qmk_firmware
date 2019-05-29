/*
Copyright 2019 marksard

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xDFA6
#define DEVICE_VER      0x0010
#define MANUFACTURER    marksard
#define PRODUCT         stoneaxe
#define DESCRIPTION     Minimal Ortholinear 30-Key Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define DIRECT_PINS { \
    { B5, B4, D7, D6, D4 }, \
    { F1, F4, D5, D1, D3 }, \
    { B0, B1, B2, B3, B7 }  \
}
#define UNUSED_PINS

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
// #define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

#if !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for stoneaxe keyboard
//  120  RGBoff
//  330  RGB 6
//  300  RGB 32
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* Serial settings */
#define USE_SERIAL
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2
