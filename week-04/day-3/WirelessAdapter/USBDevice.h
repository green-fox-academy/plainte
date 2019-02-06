#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H


#include "Device.h"
#include <string>

enum class USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

class USBDevice : virtual public Device
{
public:
    USBDevice(std::string id, USBType usbType);
    std::string getUSBType();
protected:
    USBType _usbType;
};


#endif //WIRELESSADAPTER_USBDEVICE_H
