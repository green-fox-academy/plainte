#include "Device.h"

Device::Device(std::string id)
{
    _id = id;
}

std::string Device::getID()
{
    return _id;
}
