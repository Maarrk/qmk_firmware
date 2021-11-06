#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_LALT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, TT(2), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_LCTL, KC_LSFT, KC_SPC, KC_ENT, TT(1), KC_RALT),
	[1] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_HOME, KC_WH_D, KC_WH_U, KC_END, KC_BSLS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_MINS, KC_EQL, KC_TRNS, KC_GRV, KC_QUOT, KC_LBRC, KC_RBRC, KC_APP, KC_LGUI, KC_SCLN, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_split_3x6_3(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, UC_MOD, KC_PGDN, KC_PGUP, KC_BTN1, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_F11, KC_F12, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_BTN2, KC_PSCR, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_ALT, KC_BSPACE, KC_DELETE);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM combo_rA[] = {KC_RALT, KC_R, KC_A, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_ra[] = {KC_RALT, KC_R, KC_A, COMBO_END};
const uint16_t PROGMEM combo_rE[] = {KC_RALT, KC_R, KC_E, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_re[] = {KC_RALT, KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_tE[] = {KC_RALT, KC_T, KC_E, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_te[] = {KC_RALT, KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rI[] = {KC_RALT, KC_R, KC_I, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_ri[] = {KC_RALT, KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM combo_rO[] = {KC_RALT, KC_R, KC_O, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_ro[] = {KC_RALT, KC_R, KC_O, COMBO_END};
const uint16_t PROGMEM combo_rU[] = {KC_RALT, KC_R, KC_U, KC_LSHIFT, COMBO_END};
const uint16_t PROGMEM combo_ru[] = {KC_RALT, KC_R, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_rA, UC(0xC0)),
    COMBO(combo_ra, UC(0xE0)),
    COMBO(combo_rE, UC(0xC8)),
    COMBO(combo_re, UC(0xE8)),
    COMBO(combo_tE, UC(0xC9)),
    COMBO(combo_te, UC(0xE9)),
    COMBO(combo_rI, UC(0xCC)),
    COMBO(combo_ri, UC(0xEC)),
    COMBO(combo_rO, UC(0xD2)),
    COMBO(combo_ro, UC(0xF2)),
    COMBO(combo_rU, UC(0xD9)),
    COMBO(combo_ru, UC(0xF9)),
};
