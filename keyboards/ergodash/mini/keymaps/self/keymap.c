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
  RAMEN
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

// Enums defined for all examples: (for tap dance tutorial)
enum {
  // once CLEAR, twice RESET
  CR_DANCE,
  // once [, twice {, thrice (
  LPRN_DANCE,
  // once ], twice }, thrice )
  RPRN_DANCE
};

void dance_CR_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // clear Modifiers, Keys, Macros and Layers
    clear_keyboard();
    // clear OSM
    clear_oneshot_mods();
  } else {
    reset_keyboard();
  }
}

void dance_PRN_tapped (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
  case TD(LPRN_DANCE):
    if (state->count == 1) {
      // input [ during tapping
      register_code(KC_LBRC);
      unregister_code(KC_LBRC);
    }
    break;
  case TD(RPRN_DANCE):
    if (state->count == 1) {
      // input ] during tapping
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
    }
    break;
  }
}

void dance_PRN_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
  case TD(LPRN_DANCE):
    if (state->count % 3 == 2) {
      // delete [ and input {
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
      register_code(KC_LSFT);
      register_code(KC_LBRC);
    } else if (state->count % 3 == 0) {
      // delete [ and input (
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
      register_code(KC_LSFT);
      register_code(KC_9);
    }
    break;
  case TD(RPRN_DANCE):
    if (state->count % 3 == 2) {
      // delete ] and input }
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
      register_code(KC_LSFT);
      register_code(KC_RBRC);
    } else if (state->count % 3 == 0) {
      // delete ] and input )
      register_code (KC_BSPC);
      unregister_code (KC_BSPC);
      register_code(KC_LSFT);
      register_code(KC_0);
    }
    break;
  }
}

void dance_PRN_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
  case TD(LPRN_DANCE):
    if (state->count % 3 == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_LBRC);
    } else if(state->count % 3 == 0) {
      unregister_code(KC_LSFT);
      unregister_code(KC_9);
    }
    break;
  case TD(RPRN_DANCE):
    if (state->count % 3 == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_RBRC);
    } else if (state->count % 3 == 0) {
      unregister_code(KC_LSFT);
      unregister_code(KC_0);
    }
    break;
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [CR_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_CR_finished, NULL),
  [LPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset),
  [RPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset)
};

// for debug
/* void keyboard_post_init_user(void) { */
/*   // Customise these values to desired behaviour */
/*   debug_enable=true; */
/*   debug_matrix=true; */
/*   //debug_keyboard=true; */
/*   //debug_mouse=true; */
/* } */

/* #define DEBUG_ACTION */
/* void matrix_init_user(void) { */
/*   debug_enable = true; */
/* } */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Esc |                    |  BSC |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Clear| Ramen|  Alt |  Cmd |||||||| Shift| Lower| Space|||||||| Enter| Raise|  Alt |||||||| Left | Down |  Up  | Right|
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,     KC_MINS,                      KC_EQL,   KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    OSM_LCTL, KC_A,   KC_S,     KC_D,    KC_F,    KC_G,    TD(LPRN_DANCE),               TD(RPRN_DANCE),   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    OSM_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,     KC_ESC,                      KC_BSPACE, KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    TD(CR_DANCE), RAMEN, OSM_LALT, KC_LCMD,          OSM_LSFT, OSL_LOWER, CTL_SPC, CTL_ENT, OSL_RAISE, OSM_RALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  |   1  |   2  |   3  |   4  |   5  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |  ESC |                    |  BSC |   6  |   7  |   8  |   9  |   0  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |  Alt | Cmd  |||||||| Shift| QWER | Space|||||||| Enter| QWER |   <  ||||||||   ,  |   .  |   >  |   /  |
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,  KC_UNDS,                     KC_PLUS,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,    KC_LCBR,                     KC_RCBR,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DQT, \
    OSM_LSFT, KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_ESC,                      KC_BSPACE, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RSFT, \
    _______,   _______,   OSM_LALT, KC_LCMD,          OSM_LSFT, OSL_QWERTY, CTL_SPC, CTL_ENT, OSL_QWERTY, KC_LT,            KC_COMM, KC_DOT,  KC_GT,   KC_SLSH \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |  Esc |                    |  BSC |   N  |   M  |   <  |   >  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |      |  F11 |  F12 | Cmd  |||||||| Shift| QWER | Space|||||||| Enter| QWER |  Alt |||||||| Home |PageDn|PageUp|  End |
  * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_GRV,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,  KC_UNDS,                     KC_PLUS,   KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,    KC_LCBR,                     KC_RCBR,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT, \
    OSM_LSFT, KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,   KC_ESC,                      KC_BSPACE, KC_N,     KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_RSFT, \
    _______,   KC_F11, KC_F12,  KC_LCMD,         OSM_LSFT, OSL_QWERTY, CTL_SPC, CTL_ENT, OSL_QWERTY, OSM_RALT,          KC_HOME, KC_PGDN, KC_PGUP, KC_END \
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
    case RAMEN:
      // print string
      // TODO: ramen emoji
      SEND_STRING("ramens is perfect food.");
      return false;
      break;
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
