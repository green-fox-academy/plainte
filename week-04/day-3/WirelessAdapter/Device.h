#ifndef WIRELESSADAPTER_DEVICE_H
#define WIRELESSADAPTER_DEVICE_H

#include <string>
class Device
{
public:
    Device(std::string id);
    virtual std::string getID();
protected:
    std::string _id;
};


#endif //WIRELESSADAPTER_DEVICE_H
