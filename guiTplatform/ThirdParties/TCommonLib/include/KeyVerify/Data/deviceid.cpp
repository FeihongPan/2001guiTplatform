#include "deviceid.h"

DeviceID::DeviceID()
{

}

bool DeviceID::operator==(const DeviceID &id)
{
    return this->uuid == id.uuid && this->cpuId == id.cpuId && this->baseBoardNum == id.baseBoardNum
           && this->biosNum == id.biosNum && this->diskNum == id.diskNum && this->deviceMesaage == id.deviceMesaage;
}

bool DeviceID::operator!=(const DeviceID &id)
{
    return !(*this == id);
}
