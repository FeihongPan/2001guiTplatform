#ifndef TEMPLATEINFO_H
#define TEMPLATEINFO_H

#include "GUIFramework_global.h"
#include "Serializer/QSerializer"

class GUIFRAMEWORK_EXPORT S_TemplateInfo : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_FIELD(QString, templateType)
    QS_FIELD(QString, creator)
    QS_FIELD(QString, createdTime)
    QS_FIELD(QString, modifier)
    QS_FIELD(QString, modifiedTime)
    QS_FIELD(QString, description)

public:
    S_TemplateInfo();
    S_TemplateInfo(const S_TemplateInfo &info);
    S_TemplateInfo &operator=(const S_TemplateInfo &info);
    bool operator==(const S_TemplateInfo &info);
    bool operator!=(const S_TemplateInfo &info);
};

class GUIFRAMEWORK_EXPORT S_TemplateNames : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_COLLECTION(QList, QString, lst_Names)

public:
    S_TemplateNames();
    S_TemplateNames(const S_TemplateNames &names);
    S_TemplateNames &operator=(const S_TemplateNames &names);
};

#endif // TEMPLATEINFO_H
