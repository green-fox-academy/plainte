#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H


#include "Device.h"

class NetworkDevice : virtual public Device
{
public:
    NetworkDevice(std::string id, int bandwidth);
protected:
    int _bandwidth;
};


#endif //WIRELESSADAPTER_NETWORKDEVICE_H
