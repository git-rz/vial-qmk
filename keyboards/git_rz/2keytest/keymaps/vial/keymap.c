#include QMK_KEYBOARD_H

enum custom_keycodes {
  LED_TOG = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_1x2(
    LED_TOG, LED_TOG
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case LED_TOG:
      rgb_matrix_toggle_noeeprom();
      return false;
    default:
      return true;
  }
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable_noeeprom();

  /* Solid white */
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(0, 0, 255);
}
