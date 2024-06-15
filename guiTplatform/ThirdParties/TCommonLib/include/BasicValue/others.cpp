#include "others.h"

S_IPAddress::S_IPAddress()
{

}

S_IPAddress::S_IPAddress(const SR_IPAddress &ip)
{
    this->IP = ip.IP.value;
    this->port = ip.port.value;
}

S_IPAddress::S_IPAddress(const S_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
}

S_IPAddress &S_IPAddress::operator=(const SR_IPAddress &ip)
{
    this->IP = ip.IP.value;
    this->port = ip.port.value;
    return *this;
}

S_IPAddress &S_IPAddress::operator=(const S_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
    return *this;
}

SR_IPAddress::SR_IPAddress()
{

}

SR_IPAddress::SR_IPAddress(const SR_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
}

SR_IPAddress::SR_IPAddress(const S_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
}

SR_IPAddress &SR_IPAddress::operator=(const SR_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
    return *this;
}

SR_IPAddress &SR_IPAddress::operator=(const S_IPAddress &ip)
{
    this->IP = ip.IP;
    this->port = ip.port;
    return *this;
}

S_TimeSlot::S_TimeSlot()
{

}

S_TimeSlot::S_TimeSlot(const S_TimeSlot &info)
{
    this->dateTimeStart = info.dateTimeStart;
    this->dateTimeEnd = info.dateTimeEnd;
}

S_TimeSlot &S_TimeSlot::operator=(const S_TimeSlot &info)
{
    this->dateTimeStart = info.dateTimeStart;
    this->dateTimeEnd = info.dateTimeEnd;
    return *this;
}



