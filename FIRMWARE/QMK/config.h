/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

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

/* Select hand configuration */
// #define MASTER_RIGHT
#define MASTER_LEFT
#define EE_HANDS
#define SPLIT_USB_DETECT
#define USE_SERIAL_PD2
// #define SERIAL_USE_MULTI_TRANSACTION

/* key matrix size */
// Rows are doubled-up
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B0}
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }


#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */

#undef SOFT_SERIAL_PIN
#define DEBOUNCE 5
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2
#define SERIAL_USE_MULTI_TRANSACTION

// prevent backtick to become §
#undef VENDOR_ID
#undef PRODUCT_ID
#define VENDOR_ID      0x4649
#define PRODUCT_ID      0xB060

/* ws2812 RGB LED */
// #undef RGBLED_NUM
// #undef RGBLIGHT_LED_COUNT
// #define RGB_DI_PIN D3
// #define RGBLED_NUM 14    // Number of LEDs
// #define RGBLIGHT_SPLIT   // sync LEDs between RIGHT and LEFT hand
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_ALTERNATING

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODER_RESOLUTION { 4 }
#define ENCODERS_PAD_A_RIGHT { B5 }
#define ENCODERS_PAD_B_RIGHT { F4 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }
