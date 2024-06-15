#ifndef CONSTANTINFO_GUI_H
#define CONSTANTINFO_GUI_H
#include "BasicValue/tvalue.h"

#include <QObject>
#include <QSerializer>

class S_ConstantInfo;
class SR_ConstantInfo : public TValueBase
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
    QS_OBJECT(TBool, isCurrentConstant)

public:
    SR_ConstantInfo();
    SR_ConstantInfo(const SR_ConstantInfo &sr_cst);
    SR_ConstantInfo &operator=(const SR_ConstantInfo &sr_cst);
    SR_ConstantInfo &operator=(const S_ConstantInfo &s_cst);
    S_ConstantInfo toS();
    void clear();
};

#endif // CONSTANTINFO_H
