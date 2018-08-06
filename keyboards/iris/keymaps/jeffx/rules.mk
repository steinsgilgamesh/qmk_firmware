RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes
TAP_DANCE_ENABLE=yes
SRC+=encoder.c
ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
