#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q,         KC_W,    KC_E,    KC_R,         KC_T,              KC_Y,   KC_U,           KC_I,    KC_O,    KC_P,
        LSFT_T(KC_A), KC_S,    KC_D,    KC_F,         KC_G,              KC_H,   KC_J,           KC_K,    KC_L,    RSFT_T(KC_ENTER),
        KC_Z,         KC_X,    KC_C,    KC_V,         KC_B,              KC_N,   KC_M,           KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                      KC_LGUI, KC_LALT, LT(2,KC_TAB), LT(1,KC_SPACE),    KC_ENT, LT(2,KC_SPACE), KC_RALT, KC_RGUI
    ),

    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        RM_TOGG, RM_NEXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

enum custom_keycodes {
  KC_MY_COPY = QK_KB_0,
  KC_MY_PASTE,
  KC_MY_UNDO,
  KC_MY_REDO,
  KC_MY_CUT,
  KC_MY_WORD,
  KC_MY_ALL,
};

static inline bool is_macos(void) {
  return detected_host_os() == OS_MACOS;
}

static bool send_my_shortcut(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }
  if (is_macos()) {
    tap_code16(G(KC_NO) | keycode);  // Cmd + key
  } else {
    tap_code16(C(KC_NO) | keycode);  // Ctrl + key
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MY_ALL:
      return send_my_shortcut(KC_A, record);

    case KC_MY_COPY:
      return send_my_shortcut(KC_C, record);

    case KC_MY_PASTE:
      return send_my_shortcut(KC_V, record);

    case KC_MY_UNDO:
      return send_my_shortcut(KC_Z, record);

    case KC_MY_REDO:
      return send_my_shortcut(KC_Y, record);

    case KC_MY_CUT:
      return send_my_shortcut(KC_X, record);

    case KC_MY_WORD:
      if (record->event.pressed) {
        if (is_macos()) {
          register_mods(MOD_BIT(KC_LALT));
        } else {
          register_mods(MOD_BIT(KC_LCTL));
        }
      } else {
        if (is_macos()) {
          unregister_mods(MOD_BIT(KC_LALT));
        } else {
          unregister_mods(MOD_BIT(KC_LCTL));
        }
      }
      return false;
  }

  return true;
}
