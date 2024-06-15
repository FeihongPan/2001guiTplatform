#ifndef RECIPECONTENT_H
#define RECIPECONTENT_H

#include "Recipe/Data/RcpContent/substrate.h"
#include "Recipe/Data/RcpContent/focusandleveling.h"
#include "Recipe/Data/RcpContent/alignment.h"
#include "Recipe/Data/RcpContent/exposure.h"

#include "Serializer/QSerializer"

class S_RecipeContent : public QSerializer
{
    Q_GADGET
    QS_SERIALIZABLE

    QS_OBJECT(S_Substrate, substrates)
    QS_OBJECT(S_Stencil, stencil)
    QS_OBJECT(S_FocusAndLeveling, focusAndLeveing)
    QS_OBJECT(S_Alignment, coarseAlign)
    QS_OBJECT(S_Alignment, refineAlign)
    QS_OBJECT(S_Alignment, backAlign)
    QS_OBJECT(S_Exposure, exposure)

    QS_FIELD(bool, isBlank)
    QS_FIELD(bool, isPreAlign)
    QS_FIELD(bool, isAllowManualAlign)
    QS_FIELD(bool, isAllowBackAlign)

    // Camera Parameters for Align
    QS_FIELD(bool, isShapeMatch)
    QS_FIELD(bool, isGrayMatch)
    QS_FIELD(double, exposureTime)
    QS_FIELD(double, focalOffset)
    QS_COLLECTION(QList, double, rectROI) // (x,y,w,h)

public:
    S_RecipeContent();
    S_RecipeContent(const S_RecipeContent &content);
    S_RecipeContent &operator=(const S_RecipeContent &content);
};

#endif // RECIPECONTENT_H
