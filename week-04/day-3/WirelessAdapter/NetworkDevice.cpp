#include "NetworkDevice.h"

NetworkDevice::NetworkDevice(std::string id, int bandwidth) :
        Device(id)
{
    _bandwidth = bandwidth;
}