#pragma once
#include <Arduino.h>
#include <M5GFX.h>
#include <lgfx/v1/panel/Panel_ST7789.hpp>
#include <Button.h>
#include <Wire.h>
#include <MPU6886.h>

#include <BLE2902.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <cplus_RTC.h>

#include <esp_wifi.h>
#include "constants.h"

class CLite_GFX : public lgfx::LGFX_Device
{
    lgfx::Panel_ST7789 _panel_instance;
    lgfx::Bus_SPI _bus_instance;
    lgfx::Light_PWM _light_instance;

public:
    CLite_GFX(void)
    {
        {
            auto cfg = _bus_instance.config();

            cfg.pin_mosi = LCD_MOSI_PIN;
            cfg.pin_miso = LCD_MISO_PIN;
            cfg.pin_sclk = LCD_SCLK_PIN;
            cfg.pin_dc = LCD_DC_PIN;
            cfg.freq_write = 40000000;

            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }
        {
            auto cfg = _panel_instance.config();

            cfg.invert = true;
            cfg.pin_cs = LCD_CS_PIN;
            cfg.pin_rst = LCD_RST_PIN;
            cfg.pin_busy = LCD_BUSY_PIN;
            cfg.panel_width = 135;
            cfg.panel_height = 240;
            cfg.offset_x = 52;
            cfg.offset_y = 40;
            // cfg.offset_x     = 0;
            // cfg.offset_y     = 0;

            _panel_instance.config(cfg);
        }
        {                                        // バックライト制御の設定を行います。（必要なければ削除）
            auto cfg = _light_instance.config(); // バックライト設定用の構造体を取得します。

            cfg.pin_bl = 27;    // バックライトが接続されているピン番号
            cfg.invert = false; // バックライトの輝度を反転させる場合 true
            // cfg.freq   = 44100;           // バックライトのPWM周波数
            cfg.freq = 200;      // バックライトのPWM周波数
            cfg.pwm_channel = 7; // 使用するPWMのチャンネル番号

            _light_instance.config(cfg);
            _panel_instance.setLight(&_light_instance); // バックライトをパネルにセットします。
        }

        setPanel(&_panel_instance);
    }
};

typedef LGFX_Sprite GFXcanvas1;

class M5_Board
{
public:
    M5_Board()
    {
    }

    static void hardware_init()
    {
        /* Hold pwr pin */
        gpio_reset_pin((gpio_num_t)POWER_HOLD_PIN);
        pinMode(POWER_HOLD_PIN, OUTPUT);
        digitalWrite(POWER_HOLD_PIN, HIGH);

        Wire1.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    }

    static void power_off()
    {
        printf("power off\n");
        digitalWrite(POWER_HOLD_PIN, 0);
        delay(10000);

        while (1)
        {
            delay(1000);
        }
    }
};