#include "loginfo.h"

S_LogInfo_Debugs::S_LogInfo_Debugs()
{

}

S_LogInfo_Debugs::S_LogInfo_Debugs(const S_LogInfo_Debugs &msgs)
{
    QList<QString> lst = msgs.dicMessage.keys();
    for(int i = 0; i < lst.count(); i++)
    {
        this->dicMessage[lst[i]] = msgs.dicMessage[lst[i]];
    }
}

S_LogInfo_Debugs &S_LogInfo_Debugs::operator=(const S_LogInfo_Debugs &msgs)
{
    QList<QString> lst = msgs.dicMessage.keys();
    for(int i = 0; i < lst.count(); i++)
    {
        this->dicMessage[lst[i]] = msgs.dicMessage[lst[i]];
    }
    return *this;
}

S_LogHeader_Process::S_LogHeader_Process()
{

}

S_LogHeader_Process::S_LogHeader_Process(const S_LogHeader_Process &info)
{
    this->dic_Header = info.dic_Header;
}

S_LogHeader_Process &S_LogHeader_Process::operator=(const S_LogHeader_Process &info)
{
    this->dic_Header = info.dic_Header;
    return *this;
}

S_LogData_Process::S_LogData_Process()
{

}

S_LogData_Process::S_LogData_Process(const S_LogData_Process &data)
{
    this->dic_ProcessData = data.dic_ProcessData;
}

S_LogData_Process &S_LogData_Process::operator=(const S_LogData_Process &data)
{
    this->dic_ProcessData = data.dic_ProcessData;
    return *this;
}


S_LogInfo_Process::S_LogInfo_Process()
{

}

S_LogInfo_Process::S_LogInfo_Process(const S_LogInfo_Process &info)
{
    this->dateTime = info.dateTime;
    this->lst_Header = info.lst_Header;
    this->dic_ProcessInfo = info.dic_ProcessInfo;
}

S_LogInfo_Process &S_LogInfo_Process::operator=(const S_LogInfo_Process &info)
{
    this->dateTime = info.dateTime;
    this->lst_Header = info.lst_Header;
    this->dic_ProcessInfo = info.dic_ProcessInfo;
    return *this;
}
