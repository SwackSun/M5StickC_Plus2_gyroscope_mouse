# Changes to build PandaMicTx

The PandaMicTx UI is not used `LGFX_Sprite`

The reason is that `LGFX_Sprite` seems to have a memory limit

>GFX library. However, it seems to be limited to a buffer size of 27840 bytes

Original post：https://forums.adafruit.com/viewtopic.php?t=210140

So use GFXcanvas1 from Adafruit_GFX_Library

1.Add porject of example\PandaMicTx

2.Edit `platformio.ini` and set `default_envs` with `PandaMicTx`, like:
```
[platformio]
default_envs = PandaMicTx
```
3.build and Upload

# Changes to build PandaMicTx

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
