#include "WirelessAdapter.h"
#include <iostream>

WirelessAdapter::WirelessAdapter(std::string id, USBType usbType, int bandwidth) :
        USBDevice(id, usbType),
        NetworkDevice(id, bandwidth),
        Device(id)
{

}

void WirelessAdapter::info()
{
    std::cout << getID() << " " << getUSBType() << " " << _bandwidth << std::endl;

}
