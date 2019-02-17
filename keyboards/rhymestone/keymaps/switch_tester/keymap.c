#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "../common/oled_helper.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

bool RGBAnimation = false; //Flag for LED Layer color Refresh.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  ADJUST,
  RGBOFF,
  RGB0,
  RGB1,
  RGB2,
  RGB3
};

// Layer Mode aliases
#define KC_LTAD  LT(_ADJUST, KC_NO)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KC_GRV

#define KC_RST   RESET
// #define KC_LRST  RGBRST
// #define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
// #define KC_LMOD RGB_MOD
// #define KC_KNRM  AG_NORM
// #define KC_KSWP  AG_SWAP

#define KC_ROFF  RGBOFF
#define KC_RGB0  RGB0
#define KC_RGB1  RGB1
#define KC_RGB2  RGB2
#define KC_RGB3  RGB3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       LTAD, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,---------------------------------------------------------------------.
        RST, XXXXX, XXXXX, XXXXX,  RGB0, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
       ROFF,  LHUI,  LSAI,  LVAI,  RGB1, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------|------+------+------+------+------|
      XXXXX,  LHUD,  LSAD,  LVAD,  RGB2, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+-------------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX,  RGB3, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX \
  //|------+------+------+------+-------------+------+------+------+------|
  )
};


#ifdef RGBLIGHT_ENABLE
typedef struct {
  uint8_t col, row;
  uint8_t frame;
}KEY_LIGHT_BUF;
static KEY_LIGHT_BUF keybufs[256];
static uint8_t keybuf_begin, keybuf_end;
#endif

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  #ifdef RGBLIGHT_ENABLE
    int row = record->event.key.row;
    if (record->event.pressed && ((row < 4 && is_master) || (row >= 4 && !is_master))) {
      int end = keybuf_end;
      keybufs[end].col = (char)(record->event.key.col);
      keybufs[end].row = (char)(row % 4);
      keybufs[end].frame = 0;
      keybuf_end++;
    }
  #endif

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      case RGBOFF:
        if (record->event.pressed) {
          rgblight_disable();
        }
        break;
      case RGB0:
        if (record->event.pressed) {
          RGBAnimation = false;
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
        break;
      case RGB1:
        if (record->event.pressed) {
          RGBAnimation = true;
          rgblight_mode(8);
          RGB_current_mode = rgblight_config.mode;
        }
        break;
      case RGB2:
        if (record->event.pressed) {
          RGBAnimation = true;
          rgblight_mode(14);
          RGB_current_mode = rgblight_config.mode;
        }
        break;
      case RGB3:
        if (record->event.pressed) {
          RGBAnimation = true;
          rgblight_mode(21);
          RGB_current_mode = rgblight_config.mode;
        }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif

  INIT_OLED();
}

// LED Effect
#ifdef RGBLIGHT_ENABLE
/*
keyswitches matrix
cols = 5, rows = 4, {x, y}
{4,0}, {3,0}, {2,0}, {1,0}, {0,0}
{4,1}, {3,1}, {2,1}, {1,1}, {0,1}
{4,2}, {3,2}, {2,2}, {1,2}, {0,2}
{4,3}, {3,3}, {2,3}, {1,3}, {0,3}

led index
16, 15, 08, 07, 00
17, 14, 09, 06, 01
18, 13, 10, 05, 02
19, 12, 11, 04, 03

led index
10, 11, 12, 13, 00
09, 18, 19, 14, 01
08, 17, 16, 15, 02
07, 06, 05, 04, 03

Convert switchmatrix position to led index
int at = keys_sum[x] + ((x & 1) ? (3 - y) : y);
*/

#ifdef REV_ALPHA_CONFIG_H
const uint8_t conv_pos2at[4][5] = {
  {  0,  7,  8, 15, 16},
  {  1,  6,  9, 14, 17},
  {  2,  5, 10, 13, 18},
  {  3,  4, 11, 12, 19}
};
#endif

#ifdef REV2_CONFIG_H
const uint8_t conv_pos2at[4][5] = {
  { 10, 11, 12, 13,  0},
  {  9, 18, 19, 14,  1},
  {  8, 17, 16, 15,  2},
  {  7,  6,  5,  4,  3}
};
#endif

void led_ripple_effect(char r, char g, char b) {
  static uint8_t rgb[5][4][3];
  static uint8_t scan_count = -10;
  // static uint8_t keys_sum[] = {0, 4, 8, 12, 16};

  if (scan_count == -1) {
    rgblight_enable_noeeprom();
    rgblight_mode(0);
  } else if (scan_count >= 0 && scan_count < 4) {
    for (uint8_t keybuf_index = keybuf_begin; keybuf_index != keybuf_end; ++keybuf_index) {
      int y = scan_count;
      int dist_y = abs(y - keybufs[keybuf_index].row);
      for (int x = 0; x < 5; ++x) {
        int dist = abs(x - keybufs[keybuf_index].col) + dist_y;
        if (dist <= keybufs[keybuf_index].frame) {
          int elevation = MAX(0, (16 + dist - keybufs[keybuf_index].frame)) << 2;
          if (elevation) {
            if ((rgb[x][y][0] != 255) && r) { rgb[x][y][0] = MIN(255, elevation + rgb[x][y][0]); }
            if ((rgb[x][y][1] != 255) && g) { rgb[x][y][1] = MIN(255, elevation + rgb[x][y][1]); }
            if ((rgb[x][y][2] != 255) && b) { rgb[x][y][2] = MIN(255, elevation + rgb[x][y][2]); }
          }
        }
      }
    }
  } else if (scan_count == 4) {
    for (uint8_t keybuf_index = keybuf_begin; keybuf_index != keybuf_end; keybuf_index++) {
      if (keybufs[keybuf_index].frame < 36) {
        keybufs[keybuf_index].frame++;
      } else {
        keybuf_begin++;
      }
    }
  } else if (scan_count >= 5 && scan_count < 9) {
    int y = scan_count - 5;
    for (int x = 0; x < 5; ++x) {
      // int at = keys_sum[x] + ((x & 1) ? (3 - y) : y);
      int at = conv_pos2at[y][x];
      led[at].r = rgb[x][y][0];
      led[at].g = rgb[x][y][1];
      led[at].b = rgb[x][y][2];
    }

    rgblight_set();
  } else if (scan_count == 9) {
    memset(rgb, 0, sizeof(rgb));
  }

  scan_count++;

  if (scan_count >= 10) {
    scan_count = 0;
  }
}
#endif

void matrix_scan_user(void) {
  #ifdef SSD1306OLED
    iota_gfx_task();  // this is what updates the display continuously
  #endif

  #ifdef RGBLIGHT_ENABLE
    if(!RGBAnimation){
      led_ripple_effect(0, 32, 64);
    }
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
static inline void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

static inline void render_status(struct CharacterMatrix *matrix) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS(matrix);
  RENDER_KEY_STATUS(matrix);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  render_status(&matrix);

  matrix_update(&display, &matrix);
}

#endif
