/* Copyright 2020 imchipwood
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER
    /-----------------------------------------------------`
    |             |    7    |    8    |    9    |  Bkspc  |
    |             |---------|---------|---------|---------|
    |             |    4    |    5    |    6    |   Esc   |
    |             |---------|---------|---------|---------|
    |             |    1    |    2    |    3    |   Tab   |
    |-------------|---------|---------|---------|---------|
    | Left mouse  |  TT(1)  |    0    |    .    |  Enter  |
    \-----------------------------------------------------'
    */
    [0] = LAYOUT(
                 KC_BSPC,    KC_ESC,  KC_TAB,         KC_ENTER,
                    KC_9,      KC_6,    KC_3,   LSFT_T(KC_DOT),
                    KC_8,      KC_5,    KC_2,             KC_0,
        KC_BTN1,    KC_7,      KC_4,    KC_1,             TT(1)
    ),
    /*
            SUB LAYER
    /-----------------------------------------------------`
    |             |         |         |         |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    +    |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    -    |
    |-------------|---------|---------|---------|---------|
    |    LOCK     |         |         |         |    =    |
    \-----------------------------------------------------'
    */
    [1] = LAYOUT(
                    _______,     _______,     _______,      RESET,
                    _______,     _______,     _______,      KC_KP_PLUS,
                    _______,     _______,     _______,      KC_KP_MINUS,
        KC_LOCK,    _______,     _______,     _______,      KC_EQL
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
/*
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
*/
    return true;
}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    //debug_enable = true;
    //debug_matrix = true;
    //debug_keyboard = true;
    //debug_mouse = true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {

            default:
                // default - volume up/down
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return true;
}
