/*
Info on seriel comms between split keyboards: https://docs.qmk.fm/#/feature_split_keyboard?id=hardware-configuration
This board will use the D2 (RX) pin on Elite-C

Info on OLED screen: https://docs.qmk.fm/#/feature_oled_driver?id=oled-driver
This keyboard will use D1 and D0 for the OLED screen. This is the only viable option so by turning on OLED screen
it should know this. There is no option to define pins.

Info on RGB lights: https://docs.qmk.fm/#/feature_rgblight?id=rgb-lighting
Configuring B7 to be the RGB DI PIN for the Elite-C since micropro is what the dactyl was originally written
for I will initially try pin D11 as that is the equivalent Arduino pin. My RGB strips only have 10 LED's

To determine which is the right and left half of the split keyboard I will use EEPROM
when flashing the MCU I need to use the following
for left: :dfu-split-left
for right: :dfu-split-right
*/

#undef RGB_DI_PIN
#define RGB_DI_PIN D11

#undef RGBLED_NUM
//#define RGBLED_NUM 10
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 10, 10 }

#undef USE_I2C
#define SOFT_SERIAL_PIN D2

#define EE_HANDS
#undef SPLIT_USB_DETECT // Just to be sure this isn't set somewhere

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

