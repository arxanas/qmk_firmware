# My Plover stenography layout.
#
# Note that to get this to build, you have to ignore the error about using too
# many USB endpoints. (This is because I wanted to have volume keys in addition
# to steno keys.) I did this by commenting out
#
# ```
# #if (defined(PROTOCOL_LUFA) && CDC_OUT_EPNUM > (ENDPOINT_TOTAL_ENDPOINTS - 1)) || \
#   (defined(PROTOCOL_CHIBIOS) && CDC_OUT_EPNUM > USB_MAX_ENDPOINTS)
# # error "There are not enough available endpoints to support all functions. Remove some in the rules.mk file.(MOUSEKEY, EXTRAKEY, CONSOLE, NKRO, MIDI, SERIAL, STENO)"
# #endif
# ```
#
# in `tmk_core/protocol/usb_descriptor.h`.
#
# It's unclear to me why everything seems to still work; it might be that only
# some keys are unavailable when there aren't enough USB endpoints.
STENO_ENABLE = yes

# This used to work, but no longer seems to suppress the error mentioned above.
# Not enough interrupts are available, so we have to disable something. I use
# mouse keys (MOUSEKEY_ENABLE) and the volume keys (EXTRAKEY_ENABLE), so I
# didn't want to disable any of those. This is some sort of debugging thing, I
# think, so I disabled it because I don't need it.
# CONSOLE_ENABLE = no
