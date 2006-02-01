
#include "config.h"

#if STATIC_SCRIPTS

#include "static_scripts.h"

/* testscript */
static const uint8_t testscript_flash1[] PROGMEM = {
    MACRO_WAIT(_BV(CHANNEL_RED)),
    MACRO_SET_CHANNEL(CHANNEL_BLUE, 0xff),
    MACRO_WAIT(_BV(CHANNEL_RED)),
    MACRO_SET_CHANNEL(CHANNEL_BLUE, 0),
    MACRO_JUMP(-4),
    MACRO_STOP()
                        };

static const uint8_t testscript_flash2[] PROGMEM = {
    MACRO_FADE_CHANNEL(CHANNEL_RED, 255, 0x100),
    MACRO_WAIT(_BV(CHANNEL_RED)),
    MACRO_FADE_CHANNEL(CHANNEL_RED, 100, 0x100),
    MACRO_WAIT(_BV(CHANNEL_RED)),
    MACRO_JUMP(-4),
    };


static const uint8_t testscript_eeprom[] EEMEM = {
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 255, 0xf00),
    MACRO_WAIT(_BV(CHANNEL_GREEN)),
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 0, 0x100),
    MACRO_WAIT(_BV(CHANNEL_GREEN)),
    MACRO_JUMP(-4)
    };


static const uint8_t colorchange_red[] PROGMEM = {
    MACRO_FADE_CHANNEL(CHANNEL_RED, 255, 0x200),

    MACRO_WAIT(_BV(CHANNEL_RED)|_BV(CHANNEL_GREEN)|_BV(CHANNEL_BLUE)),
    MACRO_FADE_CHANNEL(CHANNEL_RED, 0, 0x040),
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 255, 0x040),
    MACRO_WAIT(_BV(CHANNEL_RED)|_BV(CHANNEL_GREEN)|_BV(CHANNEL_BLUE)),
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 0, 0x040),
    MACRO_FADE_CHANNEL(CHANNEL_BLUE, 255, 0x040),
    MACRO_WAIT(_BV(CHANNEL_RED)|_BV(CHANNEL_GREEN)|_BV(CHANNEL_BLUE)),
    MACRO_FADE_CHANNEL(CHANNEL_BLUE, 0, 0x040),
    MACRO_FADE_CHANNEL(CHANNEL_RED, 255, 0x040),
    MACRO_JUMP(-9)
    };

static const uint8_t colorchange_red_blue[] PROGMEM = {
    MACRO_FADE_CHANNEL(CHANNEL_RED, 255, 0x200),

    MACRO_WAIT(_BV(CHANNEL_RED)|_BV(CHANNEL_BLUE)),
    MACRO_FADE_CHANNEL(CHANNEL_RED, 0, 0x040),
    MACRO_FADE_CHANNEL(CHANNEL_BLUE, 255, 0x040),
    MACRO_WAIT(_BV(CHANNEL_RED)|_BV(CHANNEL_BLUE)),
    MACRO_FADE_CHANNEL(CHANNEL_BLUE, 0, 0x040),
    MACRO_FADE_CHANNEL(CHANNEL_RED, 255, 0x040),
    MACRO_JUMP(-6)
    };


static const uint8_t green_flash[] PROGMEM = {
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 255, 0xf00),
    MACRO_WAIT(_BV(CHANNEL_GREEN)),
    MACRO_FADE_CHANNEL(CHANNEL_GREEN, 0, 0x100),
    MACRO_WAIT(_BV(CHANNEL_GREEN)),
    MACRO_STOP()
    };

static const uint8_t green_blink[] PROGMEM = {
    MACRO_SET_CHANNEL(CHANNEL_GREEN, 150),
    MACRO_SLEEP(125),
    MACRO_SET_CHANNEL(CHANNEL_GREEN, 0),
    MACRO_SLEEP(125),
    MACRO_JUMP(-4)
    };

#endif
