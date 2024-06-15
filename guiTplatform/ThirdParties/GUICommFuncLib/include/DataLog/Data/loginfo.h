#ifndef LOGINFO_H
#define LOGINFO_H

#include "GUICommFuncLib_global.h"
#include "Serializer/QSerializer"
#include "BasicValue/serializablelist.h"
#include "BasicValue/others.h"

#include <QObject>

//Debug??
class GUICOMMFUNCLIB_EXPORT S_LogInfo_Debugs : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_QT_DICT(QMap, QString, QString, dicMessage)
public:
    S_LogInfo_Debugs();
    S_LogInfo_Debugs(const S_LogInfo_Debugs &msgs);
    S_LogInfo_Debugs &operator=(const S_LogInfo_Debugs &msgs);
};


//Process????
class GUICOMMFUNCLIB_EXPORT S_LogHeader_Process : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_QT_DICT_OBJECTS(QMap, QString, S_List_String, dic_Header)  //??-??
public:
    S_LogHeader_Process();
    S_LogHeader_Process(const S_LogHeader_Process &info);
    S_LogHeader_Process &operator=(const S_LogHeader_Process &info);
};


class GUICOMMFUNCLIB_EXPORT S_LogData_Process : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_QT_DICT(QMap, QString, QString, dic_ProcessData)           //proc-messages
public:
    S_LogData_Process();
    S_LogData_Process(const S_LogData_Process &data);
    S_LogData_Process &operator=(const S_LogData_Process &data);
};


class GUICOMMFUNCLIB_EXPORT S_LogInfo_Process : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
    QS_OBJECT(S_TimeSlot, dateTime)
    QS_OBJECT(S_List_String, lst_Header)
    QS_QT_DICT_OBJECTS(QMap, QString, S_LogData_Process, dic_ProcessInfo)  //Ê±¼ä-ÐÐÊý¾Ý
public:
    S_LogInfo_Process();
    S_LogInfo_Process(const S_LogInfo_Process &info);
    S_LogInfo_Process &operator=(const S_LogInfo_Process &info);
};

#endif // LOGINFO_H
