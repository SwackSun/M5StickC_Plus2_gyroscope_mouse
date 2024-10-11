#include "test.h"

#ifndef ABS
#define ABS(x) ((x) > 0 ? (x) : -(x))
#endif

namespace TEST
{
    void TEST::imu_init()
    {
        imu.Init();
        bleMouse.begin();
    }

    void TEST::imu_test()
    {
        printf("imu test\n");

        float accX, accY, accZ;
        float lastAccX = 0;
        float lastAccY = 0;
        float xDistance, yDistance;
        const float smoothingFactor = 0.1;  // 平滑因子，值越小越平滑

        while (1)
        {
            // 获取IMU数据
            imu.getAccelData(&accX, &accY, &accZ);

            // 使用低通滤波器平滑加速度值
            accX = lastAccX + smoothingFactor * (accX - lastAccX);
            accY = lastAccY + smoothingFactor * (accY - lastAccY);

            // 将加速度值转换为鼠标移动距离
            xDistance = map(accX * 100, -70, 70, -20, 20);  // 将范围扩大100倍以提高精度
            yDistance = map(accY * 100, -70, 70, -20, 20);

            // 检查鼠标移动距离
            if (abs(xDistance) > 1 || abs(yDistance) > 1) {  // 设置阈值以去除抖动
                bleMouse.move(xDistance, (-1)*yDistance, 0);
            }
            if(bleMouse.isConnected())
            {
                if (btnA.pressed()) {
                    if (!bleMouse.isPressed(MOUSE_LEFT)) {
                    bleMouse.press(MOUSE_LEFT);
                    }
                }
                else {
                    if (bleMouse.isPressed(MOUSE_LEFT)) {
                    bleMouse.release(MOUSE_LEFT);
                    }
                }
            }

            // 更新上一个加速度值
            lastAccX = accX;
            lastAccY = accY;

            delay(5);  // 调整延迟以控制更新频率
            display->fillScreen(TFT_BLACK);
            display->setTextColor(TFT_WHITE, TFT_BLACK);
            display->setFont(&fonts::efontCN_24);
            display->setTextSize(1);
            display->setCursor(0, 10);
            display->setTextColor(TFT_YELLOW, TFT_BLACK);
            display->printf("accX: % 0.2f\n", accX);
            display->printf("accY: % 0.2f\n", accY);
            display->printf("dx: % 0.2f\n", xDistance);
            display->printf("dy: % 0.2f\n", yDistance);
            Displaybuff();

            checkReboot();
        }
    }

}
