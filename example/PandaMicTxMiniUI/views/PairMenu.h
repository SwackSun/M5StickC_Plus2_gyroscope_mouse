#ifndef _PAIR_MENU_H
#define _PAIR_MENU_H

#include <DiscoverySession.h>
#include "Navigation/Menu.h"
#include "storage/Storage.h"
#include "PairCommand.h"

class PairMenu : public Menu
{
  DiscoverySession session;

public:
  PairMenu(CLite_GFX *gfx) : Menu(gfx, "Scan for new device", "Pairing")
  {
    session.onNewDevice([=](DeviceInformation device) {
      this->custom([&](CLite_GFX *gfx) {
        return new PairCommand(device.name + " (" + device.address.toString() + ")", device);
      });
    });
  }

  void onEnter() override
  {
    session.start();
    session.clear();
    for (Device device : storage.getDevices())
    {
      session.devices[device.address.toString()] = DeviceInformation{.address = device.address, .name = device.name};
    }
  }

  void onLeave() override
  {
    session.stop();
    clear();
  }
};

#endif
