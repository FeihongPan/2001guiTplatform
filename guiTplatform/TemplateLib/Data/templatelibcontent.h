#ifndef TEMPLATELIBCONTENT_H
#define TEMPLATELIBCONTENT_H

#include "TemplateLib/Data/TemplateLibContent/align.h"
#include "TemplateLib/Data/TemplateLibContent/leveling.h"
#include "TemplateLib/Data/TemplateLibContent/templatelibsize.h"

#include "Serializer/QSerializer"

class S_TemplateLibContent: public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Leveling, leveing)
    QS_OBJECT(S_Align, align)
    QS_OBJECT(TemplatelibSize, templateLibSize)

public:
    S_TemplateLibContent();
    S_TemplateLibContent(const S_TemplateLibContent &content);
    S_TemplateLibContent &operator=(const S_TemplateLibContent &content);
};


#endif // TEMPLATELIBCONTENT_H
