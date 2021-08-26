/*
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

#include "config_common.h"


#define PRODUCT         Dactyl-Manuform (5x6)

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
// jrc left side D2, right side F7 for 2nd row (bad trace)
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { F6, D2, B1, B3, B2, B6 }

// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D3
#define RGBLED_NUM 12

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

// add rotary encoder support
// #define ENCODERS_PAD_A { F4 }
// #define ENCODERS_PAD_B { F5 }
// add rotary encoder support for both halves
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODERS_PAD_A_RIGHT { D1 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
// flip to match wiring on xo board
#define DIODE_DIRECTION COL2ROW

#define USE_SERIAL
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
// Rows are doubled-up
