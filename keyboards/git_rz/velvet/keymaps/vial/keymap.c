#include QMK_KEYBOARD_H

enum custom_keycodes {
      KC_MY_COPY = QK_KB_0,
      KC_MY_PASTE,
      KC_MY_UNDO,
      KC_MY_REDO,
      KC_MY_CUT,
      KC_MY_WORD,
      KC_MY_ALL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,              LGUI_T(KC_W),      KC_E,              KC_R,              KC_T,                   KC_Y,              KC_U,              KC_I,              RGUI_T(KC_O),      KC_P,
    LSFT_T(KC_A),      LCTL_T(KC_S),      LALT_T(KC_D),      LT(4,KC_F),        LT(8,KC_G),             LT(8,KC_H),        LT(4,KC_J),        RALT_T(KC_K),      RCTL_T(KC_L),      RSFT_T(KC_SCLN),
    LCTL_T(KC_Z),      KC_X,              LT(6,KC_C),        LT(1,KC_V),        LT(7,KC_B),             LT(7,KC_N),        LT(1,KC_M),        LT(6,KC_COMMA),    KC_DOT,            RCTL_T(KC_SLASH),
                       KC_ESCAPE,         KC_DELETE,         LT(2,KC_TAB),      LT(3,KC_SPACE),         LT(3,KC_ENTER),    LT(2,KC_MINUS),    KC_PSCR,           KC_APP
  ),

  [1] = LAYOUT(
    KC_ESCAPE,     KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_MY_REDO,    KC_PGUP,       KC_INSERT,     KC_HOME,       KC_BSPC,
    TD(0),         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_LEFT,       KC_DOWN,       KC_UP,         KC_RIGHT,      KC_PAUSE,
    KC_MY_UNDO,    KC_MY_CUT,     KC_MY_COPY,    KC_MY_PASTE,   KC_TRNS,            KC_END,        KC_PGDN,       KC_DELETE,     KC_END,        KC_SCRL,
                   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,            KC_ESCAPE,     KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [2] = LAYOUT(
    KC_1,              KC_2,              KC_3,              KC_4,              KC_5,                   LSFT(KC_GRAVE),    LSFT(KC_BSLS),   LSFT(KC_QUOTE),    LSFT(KC_LBRC), LSFT(KC_RBRC),
    LSFT(KC_1),        LSFT(KC_2),        LSFT(KC_3),        LSFT(KC_4),        LSFT(KC_5),             LSFT(KC_6),        LSFT(KC_7),        LSFT(KC_8),        LSFT(KC_9),    LSFT(KC_0),
    KC_6,              KC_7,              KC_8,              KC_9,              KC_0,                   KC_GRAVE,          KC_BSLS,         KC_QUOTE,          KC_LBRC,       KC_RBRC,
                       KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,                KC_ESCAPE,         KC_TRNS,           KC_TRNS,           KC_TRNS
  ),

  [3] = LAYOUT(
    KC_ESCAPE,           KC_TRNS,             KC_TRNS,             KC_TRNS,             TO(0),                    KC_KP_MINUS,         KC_KP_7,             KC_KP_8,             KC_KP_9,             KC_KP_PLUS,
    KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_NUM_LOCK,              KC_EQL,              KC_KP_4,             KC_KP_5,             KC_KP_6,             RSFT_T(KC_KP_ENTER),
    LCTL_T(KC_TAB),      KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_B,                     KC_KP_ASTERISK,      KC_KP_1,             KC_KP_2,             KC_KP_3,             RCTL_T(KC_KP_SLASH),
                         KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_BSPC,                KC_KP_0,             KC_KP_DOT,           KC_KP_0,             KC_KP_DOT
  ),

  [4] = LAYOUT(
    KC_F16,               KC_F17,              KC_F18,              KC_F19,              KC_F20,                   KC_F13,              KC_F7,               KC_F8,               KC_F9,               KC_F10,
    LSFT_T(KC_CAPS_LOCK), KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS,                  KC_F14,              KC_F4,               KC_F5,               KC_F6,               KC_F11,
    KC_F21,               KC_F22,              KC_F23,              KC_F24,              KC_TRNS,                  KC_F15,              KC_F1,               KC_F2,               KC_F3,               KC_F12,
                          KC_TRNS,              KC_TRNS,             KC_TRNS,             KC_TRNS,                  KC_TRNS,             KC_TRNS,             KC_TRNS,             KC_TRNS
  ),

  [5] = LAYOUT(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                   KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
    KC_A,              KC_S,              KC_D,              KC_F,              KC_G,                   KC_H,              KC_J,              KC_K,              KC_L,              RSFT_T(KC_SCLN),
    KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,                   KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,
                       KC_ESCAPE,         KC_LSFT,           KC_TAB,            KC_SPACE,               KC_ENTER,          LT(6,KC_BSPC),   KC_MINS,           TO(0)
  ),

  [6] = LAYOUT(
    KC_MUTE,    KC_VOLD,    KC_VOLU,    QK_REBOOT,  TO(3),           TO(5),      KC_TRNS,    KC_WH_U,    KC_TRNS,    KC_PSCR,
    RGB_TOG,    KC_MSTP,    KC_MPRV,    KC_MNXT,    KC_MPLY,         KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_ACL0,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(0),           KC_TRNS,    KC_TRNS,    KC_WH_D,    KC_ACL1,    KC_ACL2,
                KC_TRNS,    KC_BTN5,    KC_BTN4,    KC_BTN1,         KC_BTN2,    KC_BTN3,    RM_NEXT,    RM_PREV
  ),

  [7] = LAYOUT(
    DM_REC1,  DM_REC2,  KC_TRNS,         KC_TRNS,         (QK_MACRO_0 + 8),                   DM_PLY1, DM_PLY2, KC_TRNS,         KC_TRNS,         KC_TRNS,
    (QK_MACRO_0 + 0),              (QK_MACRO_0 + 2),              (QK_MACRO_0 + 3),              KC_TRNS,         KC_TRNS,              (QK_MACRO_0 + 5),              (QK_MACRO_0 + 6),              (QK_MACRO_0 + 7),              (QK_MACRO_0 + 8),              KC_TRNS,
    (QK_MACRO_0 + 1),              KC_TRNS,         KC_TRNS,         (QK_MACRO_0 + 4),              KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,
    KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
  ),

  [8] = LAYOUT(
    QK_BOOT,         KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         QK_BOOT,
    QK_CLEAR_EEPROM, KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         QK_CLEAR_EEPROM,
    QK_REBOOT,       KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,         QK_REBOOT,
                     KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,              KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS
  ),
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
