# Changes to build PandaMicTx

PandaMicTx UI is like PandaMicTxUI

intsall script rely on `esp_idf_nvs_partition_gen`

```
C:\Users\cs\.platformio\penv\Scripts\python.exe -m pip install --upgrade pip
 C:\Users\cs\.platformio\penv\Scripts\python.exe -m pip install esp_idf_nvs_partition_gen
```

## build

1.Add porject of example\PandaMicTx

2.Edit `platformio.ini` and set `default_envs` with `PandaMicTx`, like:
```
[platformio]
default_envs = PandaMicTx
```
3.build and Upload

# Changes to build PandaMicTxUI

## Chage to Adafruit_GFX_Library

The PandaMicTxUI UI is not used `LGFX_Sprite`

The reason is that `LGFX_Sprite` seems to have a memory limit

>GFX library. However, it seems to be limited to a buffer size of 27840 bytes

Original post：https://forums.adafruit.com/viewtopic.php?t=210140

So use GFXcanvas1 from Adafruit_GFX_Library

## undef setFont

.pio\libdeps\PandaMicTxUI\M5GFX\src\M5GFX.h

```
// #ifdef setFont
// #undef setFont
// #endif
```

## build

1.Add porject of example\PandaMicTxUI

2.Edit `platformio.ini` and set `default_envs` with `PandaMicTxUI`, like:
```
[platformio]
default_envs = PandaMicTxUI
```
3.build and Upload

# Changes to build PandaMicTxMiniUI

![](images/miniUI-1.png)

1.Add porject of example\PandaMicTxMiniUI

2.Edit `platformio.ini` and set `default_envs` with `PandaMicTxMiniUI`, like:
```
[platformio]
default_envs = PandaMicTxMiniUI
```
3.build and Upload

# Changes to build gyroscope_mouse

1.Add porject of example\gyroscope_mouse

2.Edit `platformio.ini` and set `default_envs` with `gyroscope_mouse`, like:
```
[platformio]
default_envs = gyroscope_mouse
```
3.build and Upload

# Changes to build M5StickCPlus2-UserDemo

M5StickCPlus2 user demo for hardware evaluation.

1.Add porject of example\userdemo

2.Edit `platformio.ini` and set `default_envs` with `userdemo`, like:
```
[platformio]
default_envs = userdemo
```
3.build and Upload

## Tool Chains

[PlatformIO](https://platformio.org/)

## Build

- Upload firmware
- Upload filesystem image
