#ifndef VIEWSTATUS_H
#define VIEWSTATUS_H

#include "GUICommFuncLib_global.h"

#include <QObject>

class GUICOMMFUNCLIB_EXPORT ViewStatus : public QObject
{
    Q_OBJECT
public:
    enum Status
    {
        Idle = 0,
        Runing,
        Adding,
        Modifying,
        Alarm,
    };
    Q_ENUM(Status)
public:
    explicit ViewStatus(QObject *parent = nullptr);

signals:

};

#endif // VIEWSTATUS_H
