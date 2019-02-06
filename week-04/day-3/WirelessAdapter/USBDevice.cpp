#include "USBDevice.h"

USBDevice::USBDevice(std::string id, USBType usbType) :
        Device(id)
{
    _usbType = usbType;
}

std::string USBDevice::getUSBType()
{
    if(_usbType == USBType::USB_TYPE_2) {
        return "USB_TYPE_2";
    } else {
        return "USB_TYPE_3";
    }
}
