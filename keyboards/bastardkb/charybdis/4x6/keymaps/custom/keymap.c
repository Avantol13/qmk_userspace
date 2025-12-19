/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

// #ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// #    include "timer.h"
// #endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    L_BASE = 0,
    L_SYMB,
    L_HELP,
    L_HELP2,
    L_GAME,
    L_MISC,
};

// #ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// static uint16_t auto_pointer_layer_timer = 0;

// #    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
// #        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
// #    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

// #    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
// #        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
// #    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
// #endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// #ifndef POINTING_DEVICE_ENABLE
// #    define DRGSCRL KC_NO
// #    define DPI_MOD KC_NO
// #    define S_D_MOD KC_NO
// #    define SNIPING KC_NO
// #endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LSFT, LT(3,KC_A), KC_S, KC_D, KC_F, KC_G,            KC_H, LT(2,KC_J), LT(1,KC_K), KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_LCTL, LT(1,KC_Z), KC_X, KC_C, KC_V, KC_B,            KC_N, KC_M, KC_COMM, KC_DOT, LT(3,KC_SLSH), KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(0), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_SYMB] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  KC_TRNS, KC_NO, KC_BSLS, KC_LBRC, KC_RBRC, S(KC_GRV),         S(KC_6), KC_7, KC_8, KC_9, KC_NO, S(KC_MINS),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  KC_TRNS, KC_NO, S(KC_BSLS), S(KC_9), S(KC_0), KC_GRV,         KC_LBRC, KC_4, KC_5, KC_6, KC_PEQL, S(KC_EQL),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  KC_TRNS, KC_NO, KC_PMNS, S(KC_MINS), S(KC_SCLN), KC_QUOT,     KC_NO, KC_1, KC_2, KC_3, KC_PMNS, KC_PEQL,  
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  KC_TRNS, KC_NO, KC_PEQL, S(KC_LBRC), S(KC_RBRC), S(KC_QUOT),  KC_PAST, KC_0, KC_0, KC_0, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(0), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_HELP] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TRNS, KC_R, KC_Q, KC_UP, KC_E, C(KC_C),             KC_U, DF(L_GAME), DRAGSCROLL_MODE, KC_MS_BTN2, TG(2), DF(0),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TRNS, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, C(KC_V),  KC_I, KC_MS_BTN1, C(KC_D), DRAGSCROLL_MODE, KC_MS_BTN1, DF(2),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TRNS, KC_LCTL, KC_Z, KC_X, KC_V, KC_T,               KC_M, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_F12,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(0), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_HELP2] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_CLEAR_EEPROM,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO, KC_NO, KC_NO, POINTER_DEFAULT_DPI_REVERSE, POINTER_SNIPING_DPI_REVERSE,            POINTER_SNIPING_DPI_FORWARD, POINTER_DEFAULT_DPI_FORWARD, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO, DRAGSCROLL_MODE, SNIPING, SNP_TOG, KC_NO,      KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, SNIPING, DRAGSCROLL_MODE, KC_TRNS, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(0), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [L_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_T, KC_TAB, KC_Q, KC_W, KC_E, KC_R,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_G, KC_LSFT, LT(3,KC_A), KC_S, KC_D, KC_F,            KC_H, LT(2,KC_J), LT(1,KC_K), KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_8, KC_LCTL, LT(1,KC_Z), KC_X, KC_C, KC_V,            KC_N, KC_M, KC_COMM, KC_DOT, LT(3,KC_SLSH), KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(0), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [L_MISC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_T, KC_TAB, KC_Q, KC_W, KC_E, KC_R,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_G, KC_LSFT, LT(3,KC_A), KC_S, KC_D, KC_F,            KC_H, LT(2,KC_J), LT(1,KC_K), KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_8, KC_LCTL, LT(1,KC_Z), KC_X, KC_C, KC_V,            KC_N, KC_M, KC_COMM, KC_DOT, LT(3,KC_SLSH), KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_DEL, KC_ENT,
                                              DF(2), KC_SPC,    KC_BSPC
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  )
};
// clang-format on

// #ifdef POINTING_DEVICE_ENABLE
// #    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
//         if (auto_pointer_layer_timer == 0) {
//             layer_on(L_HELP2);
// #        ifdef RGB_MATRIX_ENABLE
//             rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
//             rgb_matrix_sethsv_noeeprom(HSV_GREEN);
// #        endif // RGB_MATRIX_ENABLE
//         }
//         auto_pointer_layer_timer = timer_read();
//     }
//     return mouse_report;
// }

// void matrix_scan_user(void) {
//     if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(L_HELP2);
// #        ifdef RGB_MATRIX_ENABLE
//         rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
// #        endif // RGB_MATRIX_ENABLE
//     }
// }
// #    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// #    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
// layer_state_t layer_state_set_user(layer_state_t state) {
//     charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
//     return state;
// }
// #    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
// #endif     // POINTING_DEVICE_ENABLE

// #ifdef RGB_MATRIX_ENABLE
// // Forward-declare this helper function since it is defined in rgb_matrix.c.
// void rgb_matrix_update_pwm_buffers(void);
// #endif
