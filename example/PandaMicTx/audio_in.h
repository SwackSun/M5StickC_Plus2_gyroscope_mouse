#ifndef _AUDIO_IN_H
#define _AUDIO_IN_H

#include "driver/i2s.h"
#include "freertos/queue.h"

#define I2S_PORT I2S_NUM_0
#define PIN_CLK 0
#define PIN_DATA 34

static const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_PDM),
            // .sample_rate = 44100,
            .sample_rate = 48000,
            .bits_per_sample =
                I2S_BITS_PER_SAMPLE_16BIT, // is fixed at 12bit, stereo, MSB
            .channel_format = I2S_CHANNEL_FMT_ALL_RIGHT,
#if ESP_IDF_VERSION > ESP_IDF_VERSION_VAL(4, 1, 0)
            .communication_format =
                I2S_COMM_FORMAT_STAND_I2S, // Set the format of the communication.
#else                                      // 设置通讯格式
            .communication_format = I2S_COMM_FORMAT_I2S,
#endif
            .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
            .dma_buf_count = 2,
            .dma_buf_len = 128,
        };

static const i2s_pin_config_t pin_config = {
#if (ESP_IDF_VERSION > ESP_IDF_VERSION_VAL(4, 3, 0))
        .mck_io_num = I2S_PIN_NO_CHANGE,
#endif
        .bck_io_num = I2S_PIN_NO_CHANGE,
        .ws_io_num = PIN_CLK,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = PIN_DATA,
};

void audio_init()
{
  ESP_ERROR_CHECK(i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL));
  ESP_ERROR_CHECK(i2s_set_pin(I2S_PORT, &pin_config));
}

void audio_deinit()
{
  ESP_ERROR_CHECK(i2s_driver_uninstall(I2S_PORT));
}

void audio_start()
{
  ESP_ERROR_CHECK(i2s_start(I2S_PORT));
}

void audio_stop()
{
  ESP_ERROR_CHECK(i2s_stop(I2S_PORT));
}

#endif
