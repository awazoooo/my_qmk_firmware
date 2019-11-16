#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT CTL_T(KC_ENT)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSL_LOWER OSL(_LOWER)
#define OSL_RAISE OSL(_RAISE)
#define OSL_QWERTY OSL(_QWERTY)

enum {
  TD_LBRC_LPRN = 0
};

// Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Esc |                    |  BSC |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Reset|Adjust|  Alt |  Cmd |||||||| Shift| Lower| Space|||||||| Enter| Raise|  Alt |||||||| Left | Down |  Up  | Right|
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,     KC_MINS,                      KC_EQL,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    OSM_LCTL, KC_A,   KC_S,     KC_D,    KC_F,    KC_G,     TD(TD_LBRC_LPRN),                     KC_RBRC,   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    OSM_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_ESC,                      KC_BSPACE, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    RESET,   ADJUST, OSM_LALT, KC_LCMD,          OSM_LSFT, OSL_LOWER, CTL_SPC, CTL_ENT, OSL_RAISE, OSM_RALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  |   1  |   2  |   3  |   4  |   5  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |  ESC |                    |  BSC |   6  |   7  |   8  |   9  |   0  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt | Cmd  |||||||| Shift| QWER | Space|||||||| Enter| QWER |   <  ||||||||   ,  |   .  |   >  |   /  |
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,  KC_UNDS,                     KC_PLUS,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_LCBR,                     KC_RCBR,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DQT, \
    OSM_LSFT, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_ESC,                      KC_BSPACE, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RSFT, \
    KC_NO,   KC_NO,   OSM_LALT, KC_LCMD,          OSM_LSFT, OSL_QWERTY, CTL_SPC, CTL_ENT, OSL_QWERTY, KC_LT,            KC_COMM, KC_DOT,  KC_GT,   KC_SLSH \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |  Esc |                    |  BSC |   N  |   M  |   <  |   >  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Ctrl |  F11 |  F12 | Cmd  |||||||| Shift| QWER | Space|||||||| Enter| QWER |  Alt |||||||| Home |PageDn|PageUp|  End |
  * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,  KC_UNDS,                     KC_PLUS,   KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,    KC_LCBR,                     KC_RCBR,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT, \
    OSM_LSFT, KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,   KC_ESC,                      KC_BSPACE, KC_N,     KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    KC_NO,   KC_F11, KC_F12,  KC_LCMD,         OSM_LSFT, OSL_QWERTY, CTL_SPC, CTL_ENT, OSL_QWERTY, OSM_RALT,          KC_HOME, KC_PGDN, KC_PGUP, KC_END \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

// TAPPING_TERM for each keycode
uint16_t get_tapping_term(uint16_t keycode){
  switch(keycode){
  case CTL_SPC:
    return 150;
  case CTL_ENT:
    return 150;
  default:
    return TAPPING_TERM;
  }
}
