#ifndef CONSTANTINFO_H
#define CONSTANTINFO_H

#include "GUIFramework_global.h"
#include "BasicValue/tvalue.h"
#include "Serializer/QSerializer"

#include <QObject>

class SR_ConstantInfo;

class GUIFRAMEWORK_EXPORT S_ConstantInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE
public:
    QS_FIELD(QString, constantName)
    QS_FIELD(QString, createdTime)
    QS_FIELD(QString, creator)
    QS_FIELD(QString, description)
    QS_FIELD(QString, modifiedTime)
    QS_FIELD(QString, modifier)
    QS_FIELD(QString, excuteTime)
    QS_FIELD(QString, unexcuteTime)

public:
    S_ConstantInfo();
    S_ConstantInfo(const S_ConstantInfo &s_cst);
    S_ConstantInfo(const SR_ConstantInfo &mcInfo);
    S_ConstantInfo &operator=(const S_ConstantInfo &s_cst);
    S_ConstantInfo &operator=(const SR_ConstantInfo &s_cst);
};

class GUIFRAMEWORK_EXPORT SR_ConstantInfo : public TValueBase
{
    Q_GADGET
    QS_SERIALIZABLE

public:
    QS_OBJECT(TString, constantName)
    QS_OBJECT(TString, createdTime)
    QS_OBJECT(TString, creator)
    QS_OBJECT(TString, description)
    QS_OBJECT(TString, modifiedTime)
    QS_OBJECT(TString, modifier)
    QS_OBJECT(TString, excuteTime)
    QS_OBJECT(TString, unexcuteTime)

public:
    SR_ConstantInfo();
    SR_ConstantInfo(const SR_ConstantInfo &mcInfo);
    SR_ConstantInfo(const S_ConstantInfo &mcInfo);
    SR_ConstantInfo &operator=(const SR_ConstantInfo &mcInfo);
    SR_ConstantInfo &operator=(const S_ConstantInfo &mcmcInfo);
};

#endif // CONSTANTINFO_H
