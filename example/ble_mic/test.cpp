#include "test.h"

namespace TEST
{
    void TEST::hardware_init()
    {
        /* Hold pwr pin */
        gpio_reset_pin((gpio_num_t)POWER_HOLD_PIN);
        pinMode(POWER_HOLD_PIN, OUTPUT);
        digitalWrite(POWER_HOLD_PIN, HIGH);

        Wire1.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    }

    void TEST::power_off()
    {
        display->fillScreen(TFT_BLACK);
        displayUpdate();

        while ((!btnPWR.read()))
        {
            delay(100);
        }

        delay(200);

        printf("power off\n");
        digitalWrite(POWER_HOLD_PIN, 0);
        delay(10000);

        while (1)
        {
            delay(1000);
        }
    }

    void TEST::setup()
    {
        hardware_init();
        lcd_init();
        key_init();
        mic_init();

        ColorBar();

        mic_fft_send_ble();
    }

    void TEST::loop()
    {
        
    }
}
