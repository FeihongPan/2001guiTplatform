#ifndef TEMPLATELIB_H
#define TEMPLATELIB_H

#include "ITemplateLib/Data/templateinfo.h"
#include "templatelibcontent.h"
#include "Serializer/QSerializer"

#include <QObject>

class S_TemplateLib : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_TemplateInfo, templateInfo)
    QS_OBJECT(S_TemplateLibContent, templateLibContent)

public:
    S_TemplateLib();
    S_TemplateLib(const S_TemplateLib &templateLib);
    S_TemplateLib &operator=(const S_TemplateLib &templateLib);
};

#endif // TEMPLATELIB_H
