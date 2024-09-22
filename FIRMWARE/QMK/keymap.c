/* Copyright Juarendra Ramadhani 2024
* With permission from mattdibi, the original maintainer of the Redox hardware.
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

#include QMK_KEYBOARD_H
#include "oled.c"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#undef LAYOUT
#define LAYOUT( \
  k00, k01, k02, k03, k04, k05,                          k08, k09, k10, k11, k12, k13, \
  k14, k15, k16, k17, k18, k19, k06,                k07, k22, k23, k24, k25, k26, k27, \
  k28, k29, k30, k31, k32, k33, k20,                k21, k36, k37, k38, k39, k40, k41, \
  k42, k43, k44, k45, k46, k47, k34, k48,      k49, k35, k50, k51, k52, k53, k54, k55, \
  k56, k57, k58, k59, k60, k61, k62,           k63, k64, k65, k66, k67, k68, k69,  \
  k70, k71, k72,                                                        k73, k74, k75  \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k14, k15, k16, k17, k18, k19, k20 }, \
    { k28, k29, k30, k31, k32, k33, k34 }, \
    { k42, k43, k44, k45, k46, k47, k48 }, \
    { k56, k57, k58, k59, k60, k61, k62 }, \
    { k70, k71, k72, KC_NO, KC_NO, KC_NO, KC_NO },  \
    { k13, k12, k11, k10, k09, k08, k07 }, \
    { k27, k26, k25, k24, k23, k22, k21 }, \
    { k41, k40, k39, k38, k37, k36, k35 }, \
    { k55, k54, k53, k52, k51, k50, k49 }, \
    { k69, k68, k67, k66, k65, k64, k63 },  \
    { k75, k74, k73, KC_NO, KC_NO, KC_NO, KC_NO },  \
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    QK_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,                                                           KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
    KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,XXXXXXX,                                                KC_F9,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLS,
    KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,MO(2),                                                 KC_F10,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,                       XXXXXXX,XXXXXXX,        XXXXXXX,XXXXXXX,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENT,
    KC_LCTL,KC_LALT,KC_LGUI,OSM(MOD_LSFT|MOD_LALT|MOD_LCTL),MO(1),KC_SPC,KC_ENT,    KC_ENT,KC_SPC,MO(1),        _______,_______,_______,_______,
    KC_MUTE,XXXXXXX,XXXXXXX,                                                                                    XXXXXXX,XXXXXXX,KC_MPLY
),
[1] = LAYOUT(
    KC_GRV,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,                                                   KC_F6,KC_F7,KC_F8,KC_MINS,KC_EQL,KC_DEL,
    _______,_______,_______,_______,_______,_______,KC_F11,                         _______,KC_LBRC,KC_RBRC,_______,KC_LBRC,KC_RBRC,_______,
    _______,_______,_______,_______,_______,_______,KC_F12,                         _______,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,_______,
    _______,_______,_______,_______,_______,_______,QK_BOOT,EE_CLR,         EE_CLR,QK_BOOT,_______,_______,_______,_______,KC_RALT,KC_RSFT,
    _______,_______,_______,_______,        _______,_______,_______,        _______,_______,_______,        KC_RGUI,_______,_______,_______,
    _______,_______,_______,                                                                                _______,_______,_______ 
),
[2] = LAYOUT(
    _______,_______,_______,_______,_______,_______,                                        _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,                        _______,KC_BTN1,KC_BTN2,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,                        _______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,       _______,_______,KC_WH_U,KC_WH_D,_______,_______,_______,_______ ,
    _______,_______,_______,_______,        _______,_______,_______,       _______,_______,_______,        KC_ACL0,KC_ACL1,KC_ACL2,_______,
    _______,_______,_______,                                                                                _______,_______,_______
),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLD, MS_WHLU)  },
};
#endif
