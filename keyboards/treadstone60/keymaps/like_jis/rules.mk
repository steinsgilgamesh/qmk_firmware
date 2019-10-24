
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
TAP_DANCE_ENABLE = no

# If your custom treadstone60 pcb, you can rewrite to yes.
RGBLIGHT_ENABLE = no  # LED underglow (Enable WS2812 RGB underlight.)
LED_ANIMATIONS = no        # LED animations

ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
    OPT_DEFS += -DLED_ANIMATIONS
endif
