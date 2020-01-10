MOUSEKEY_ENABLE = no       # Mouse keys
TAP_DANCE_ENABLE = no

RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
OLED_DRIVER_ENABLE = no
LTO_ENABLE = yes
RGB_MATRIX_ENABLE = WS2812

# If you want to change the display of OLED, you need to change here
SRC +=  ./common/oled_helper.c \
