#include <Arduino.h>

const uint8_t PROGMEM LOGO[] = {
    // 'PandaMic', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0c, 0xfd, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1f, 0x03, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1c, 0x01, 0xc2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x00, 0xc1, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x30, 0x00, 0xc3, 0x06, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x00, 0xc1, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x30, 0x00, 0xc3, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x40, 0x83, 0x1c, 0x00, 0x00, 0x00, 0x30, 0x00, 0xe7, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x21, 0xc6, 0x43, 0x83, 0x0c, 0x7c, 0x37, 0x03, 0xb1, 0xf0, 0xe7, 0x1e, 0x03, 0xc0, 0x00,
    0x00, 0x23, 0x83, 0x43, 0x83, 0x0c, 0x7e, 0x3f, 0x87, 0xf1, 0xf8, 0xff, 0x1e, 0x07, 0xe0, 0x00,
    0x00, 0x23, 0x83, 0x43, 0x83, 0x1c, 0x03, 0x39, 0xce, 0x70, 0x0c, 0xff, 0x06, 0x0e, 0x70, 0x00,
    0x00, 0x23, 0x19, 0x47, 0x83, 0xf8, 0x7f, 0x30, 0xcc, 0x31, 0xfc, 0xdb, 0x06, 0x0c, 0x00, 0x00,
    0x00, 0x30, 0x00, 0xc7, 0x03, 0xf0, 0xff, 0x30, 0xcc, 0x33, 0xfc, 0xdb, 0x06, 0x0c, 0x00, 0x00,
    0x00, 0x3f, 0x03, 0xc7, 0x03, 0x00, 0xc3, 0x30, 0xcc, 0x33, 0x0c, 0xc3, 0x06, 0x0c, 0x00, 0x00,
    0x00, 0x1f, 0xff, 0x9e, 0x03, 0x00, 0xc3, 0x30, 0xce, 0x73, 0x0c, 0xc3, 0x06, 0x0e, 0x70, 0x00,
    0x00, 0x0f, 0x7f, 0xfc, 0x03, 0x00, 0xff, 0x30, 0xc7, 0xf3, 0xfc, 0xc3, 0x1f, 0x87, 0xe0, 0x00,
    0x00, 0x00, 0x7e, 0x38, 0x03, 0x00, 0x7f, 0x30, 0xc3, 0xb1, 0xfc, 0xc3, 0x1f, 0x83, 0xc0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
