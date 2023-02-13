#include QMK_KEYBOARD_H
#include "keymap_steno.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, LALT_T(KC_GRV), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, TT(2), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_LCTL, KC_LSFT, KC_SPC, KC_ENT, TT(1), RALT_T(KC_CAPS)),
                                                              [1] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_HOME, KC_WH_D, KC_WH_U, KC_END, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MINS, KC_EQL, KC_TRNS, KC_MPLY, KC_MNXT, KC_LBRC, KC_RBRC, KC_APP, KC_LGUI, KC_SCLN, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [2] = LAYOUT_split_3x6_3(TG(3), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL, KC_TRNS, KC_INS, KC_PGDN, KC_PGUP, KC_BTN1, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F11, KC_F12, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_BTN2, KC_PSCR, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [3] = LAYOUT_split_3x6_3(TG(3), STN_NC, STN_NC, STN_N3, STN_N4, STN_N5, STN_N6, STN_NC, STN_N8, STN_N9, STN_NA, STN_NB, STN_N2, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, STN_PWR, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, STN_N1, STN_A, STN_O, STN_E, STN_U, STN_N7)};

void matrix_init_user() { steno_set_mode(STENO_MODE_GEMINI); }

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case 1:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case 2:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case 3:
                oled_write_P(PSTR("Steno\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

        return false;
    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
        return false;
    }
}
#endif

// const uint16_t PROGMEM number_combo1[] = {STN_O, STN_E, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(number_combo1, STN_NC)
// };
