/*
Info on seriel comms between split keyboards: https://docs.qmk.fm/#/feature_split_keyboard?id=hardware-configuration
This board will use the D2 (RX) pin on Elite-C

Info on OLED screen: https://docs.qmk.fm/#/feature_oled_driver?id=oled-driver
This keyboard will use D1 and D0 for the OLED screen. This is the only viable option so by turning on OLED screen
it should know this. There is no option to define pins.

Info on RGB lights: https://docs.qmk.fm/#/feature_rgblight?id=rgb-lighting
Configuring C7 to be the RGB DI PIN for the Elite-C. My RGB strips only have 10 LED's

To determine which is the right and left half of the split keyboard I will use EEPROM
when flashing the MCU I need to use the following
for left: :dfu-split-left
for right: :dfu-split-right

Info on Audio: AUDIO_ENABLE = yes
Audio pin will be B7.
*/

#undef RGB_DI_PIN
#define RGB_DI_PIN C7 // Initially tried D11 and that didn't work.

// #undef RGBLED_NUM
//#define RGBLED_NUM 10
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 10, 10 }

//#undef USE_I2C // commenting this out because the OLED screen uses I2C
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2

//#undef SPLIT_HAND_PIN
//#undef SPLIT_HAND_MATRIX_GRID
//#undef SPLIT_USB_DETECT // Just to be sure this isn't set somewhere
#define EE_HANDS

// The following is only needed if there is an issue with serial comms
// #define SELECT_SOFT_SERIAL_SPEED #
/*
    0: about 189kbps (Experimental only)
    1: about 137kbps (default)
    2: about 75kbps
    3: about 39kbps
    4: about 26kbps
    5: about 20kbps
*/

// incase I ever want to use only one side?
#define SPLIT_MAX_CONNECTION_ERRORS 10
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500

// The following is useful for OLED screens to use layer data
#define SPLIT_LAYER_STATE_ENABLE
// This shares the lock key status
#define SPLIT_LED_STATE_ENABLE

// For small piezo buzzer
#define AUDIO_PIN B7
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
// https://docs.qmk.fm/#/feature_audio?id=audio-click
// #define AUDIO_CLICKY // This would make the little speaker simulate key presses
