/*
Copyright 2023 Matt F
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

#include QMK_KEYBOARD_H

// Layer shorthand
enum layer_names {
    _BASE,
    _FN,
    _CMK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | ]      | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | F5     | A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ;      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | DEL    | BACKSP | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | `      | ENTER  | SPACE  | SPACE  | SPACE  | LEFT   | '      | LEFT   | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_F5,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_GRV,  KC_ENT,      KC_SPC,       KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TO(_CMK)
    ),

    /* Function Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | `      | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | PRT SC |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        | HOME   | UP     | END    | PGUP   |        | VOL DN | VOL UP | PGUP   | HOME   | UP     | END    |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | F12    | LEFT   | DOWN   | RIGHT  | PGDN   |        |        |        | PGDN   | LEFT   | DOWN   | RIGHT  | '      |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | Reset  |        |        |        |        |        |        |        |        |        |        | UP     | DOWN   |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, KC_VOLD, KC_VOLU, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        KC_F12,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        QK_BOOT, _______, _______, _______, _______, _______,     _______,      _______, _______, _______, KC_UP,   KC_DOWN, _______
    ),

    /* Colemak Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | F      | P      | B      | [      | ]      | J      | P      | U      | Y      | ;      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | F5     | A      | R      | S      | T      | G      |        |        | M      | N      | E      | I      | O      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | D      | V      | DEL    | BACKSP | K      | H      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | `      | ENTER  | SPACE  | SPACE  | SPACE  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_CMK] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_LBRC, KC_RBRC, KC_J,    KC_P,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_F5,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_DEL,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_GRV,  KC_ENT,      KC_SPC,       KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TO(_BASE)
    )
};
