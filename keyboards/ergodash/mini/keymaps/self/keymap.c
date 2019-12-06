#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// layers
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
//#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  //  ADJUST,
  RAMEN
};

enum {
  // once CLEAR, twice RESET
  CLRE_DANCE,
  // once i, twice *
  ASTR_DANCE,
  // once -, twice _
  MINS_DANCE,
  // once =, twice +
  EQL_DANCE,
  // once \, twice |
  BSLS_DANCE,
  // once ', twice "
  QUOT_DANCE,
  // once ;, twice :
  SCLN_DANCE,
  // once [, twice {, thrice (
  LPRN_DANCE,
  // once ], twice }, thrice )
  RPRN_DANCE
};

void dance_CLRE_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // clear Modifiers, Keys, Macros and Layers
    clear_keyboard();
    // clear OSM
    clear_oneshot_mods();
  } else {
    reset_keyboard();
  }
}

// Double Tap Dance
void dance_DP_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
  case TD(ASTR_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_8);
    } else {
      register_code(KC_I);
    }
    break;
  case TD(MINS_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_MINS);
    } else {
      register_code(KC_MINS);
    }
    break;
  case TD(EQL_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_EQL);
    } else {
      register_code(KC_EQL);
    }
    break;
  case TD(BSLS_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_BSLS);
    } else {
      register_code(KC_BSLS);
    }
    break;
  case TD(QUOT_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_QUOT);
    } else {
      register_code(KC_QUOT);
    }
    break;
  case TD(SCLN_DANCE):
    if (state->count == 2) {
      register_code(KC_LSFT);
      register_code(KC_SCLN);
    } else {
      register_code(KC_SCLN);
    }
    break;
  }
}

void dance_DP_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->keycode) {
  case TD(ASTR_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_8);
    } else {
      unregister_code(KC_I);
    }
    break;
  case TD(MINS_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_MINS);
    } else {
      unregister_code(KC_MINS);
    }
    break;
  case TD(EQL_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_EQL);
    } else {
      unregister_code(KC_EQL);
    }
    break;
  case TD(BSLS_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_BSLS);
    } else {
      unregister_code(KC_BSLS);
    }
    break;
  case TD(QUOT_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_QUOT);
    } else {
      unregister_code(KC_QUOT);
    }
    break;
  case TD(SCLN_DANCE):
    if (state->count == 2) {
      unregister_code(KC_LSFT);
      unregister_code(KC_SCLN);
    } else {
      unregister_code(KC_SCLN);
    }
    break;
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

// rarely taps TD
#define RARELY_TD_TIME 120
// sometimes taps TD
#define SOMETIMES_TD_TIME 140
// often taps TD
#define OFTEN_TD_TIME 170
// usually taps TD
#define USUALLY_TD_TIME 200
// triple tap dance
#define TRIPLE_TD_TIME 160

// All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  // Double Tap Dance
  [CLRE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_CLRE_finished, NULL, USUALLY_TD_TIME),
  [ASTR_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, RARELY_TD_TIME),
  [MINS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME),
  [EQL_DANCE]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME),
  [BSLS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, OFTEN_TD_TIME),
  [QUOT_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME),
  [SCLN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dance_DP_finished, dance_DP_reset, USUALLY_TD_TIME),
  // Triple Tap Dance
  [LPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME),
  [RPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME)
};

#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT CTL_T(KC_ENT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSL_LOW OSL(_LOWER)
#define OSL_RAI OSL(_RAISE)
#define OSL_QWE OSL(_QWERTY)
#define TD_CLRE TD(CLRE_DANCE)
#define TD_ASTR TD(ASTR_DANCE)
#define TD_MINS TD(MINS_DANCE)
#define TD_EQL  TD(EQL_DANCE)
#define TD_BSLS TD(BSLS_DANCE)
#define TD_QUOT TD(QUOT_DANCE)
#define TD_SCLN TD(SCLN_DANCE)
#define TD_LPRN TD(LPRN_DANCE)
#define TD_RPRN TD(RPRN_DANCE)

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
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Esc |                    |  BSC |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Clear| Ramen|  Alt |  Cmd |||||||| Shift| Lower| Space|||||||| Enter| Raise|  Alt |||||||| Left | Down |  Up  | Right|
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, TD_MINS,                    TD_EQL,    KC_Y,    KC_U, TD_ASTR,    KC_O,    KC_P, TD_BSLS, \
    OSM_CTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, TD_LPRN,                   TD_RPRN,    KC_H,    KC_J,    KC_K,    KC_L, TD_SCLN, TD_QUOT, \
    OSM_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,                   KC_BSPC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, \
    TD_CLRE,   RAMEN, OSM_ALT, KC_LCMD,          OSM_SFT, OSL_LOW, CTL_SPC, CTL_ENT, OSL_RAI, OSM_ALT,          KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  |   1  |   2  |   3  |   4  |   5  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |  ESC |                    |  BSC |   6  |   7  |   8  |   9  |   0  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |  Alt |  Cmd |||||||| Shift| QWER | Space|||||||| Enter| QWER |  Alt ||||||||      |      |      |      |
   * |      |      |      |      ||||||||      |      | Ctrl |||||||| Ctrl |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
     KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_UNDS,                   KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_LCBR,                   KC_RCBR,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_DQT, \
    OSM_SFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_ESC,                   KC_BSPC,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RSFT, \
    _______, _______, OSM_ALT, KC_LCMD,          OSM_SFT, OSL_QWE, CTL_SPC, CTL_ENT, OSL_QWE, OSM_ALT,          _______, _______, _______, _______  \
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
     KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_UNDS,                   KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_LCBR,                   KC_RCBR, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COLN,  KC_DQT, \
    OSM_SFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_ESC,                   KC_BSPC,    KC_N,    KC_M,   KC_LT,   KC_GT, KC_QUES, KC_RSFT, \
    _______,  KC_F11,  KC_F12, KC_LCMD,          OSM_SFT, OSL_QWE, CTL_SPC, CTL_ENT, OSL_QWE, OSM_ALT,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case RAMEN:
    // print string
    // TODO: ramen emoji
    SEND_STRING("ramen is perfect food.");
    return false;
  case LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
    } else {
      layer_off(_LOWER);
    }
    return false;
  case RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
    } else {
      layer_off(_RAISE);
    }
    return false;
  }
  return true;
}

// TAPPING_TERM for each keycode
// Tap Dances settings are in tap_dance_actions[]
uint16_t get_tapping_term(uint16_t keycode){
  switch(keycode){
  case CTL_SPC:
  case CTL_ENT:
    return 200;
  // 通常キーは80
  default:
    return TAPPING_TERM;
  }
}
