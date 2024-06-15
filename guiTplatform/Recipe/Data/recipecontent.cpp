#include "recipecontent.h"

S_RecipeContent::S_RecipeContent()
{

}

S_RecipeContent::S_RecipeContent(const S_RecipeContent &content)
{
    this->substrates = content.substrates;
    this->stencil = content.stencil;
    this->focusAndLeveing = content.focusAndLeveing;
    this->coarseAlign = content.coarseAlign;
    this->refineAlign = content.refineAlign;
    this->backAlign = content.backAlign;
    this->exposure = content.exposure;
    this->isBlank = content.isBlank;
    this->isPreAlign = content.isPreAlign;
    this->isAllowManualAlign = content.isAllowManualAlign;
    this->isAllowBackAlign = content.isAllowBackAlign;
    /* Camera Parameters for Align */
    this->isShapeMatch = content.isShapeMatch;
    this->isGrayMatch = content.isGrayMatch;
    this->exposureTime = content.exposureTime;
    this->focalOffset = content.focalOffset;
    this->rectROI = content.rectROI;
}

S_RecipeContent &S_RecipeContent::operator=(const S_RecipeContent &content)
{
    this->substrates = content.substrates;
    this->stencil = content.stencil;
    this->focusAndLeveing = content.focusAndLeveing;
    this->coarseAlign = content.coarseAlign;
    this->refineAlign = content.refineAlign;
    this->backAlign = content.backAlign;
    this->exposure = content.exposure;
    this->isBlank = content.isBlank;
    this->isPreAlign = content.isPreAlign;
    this->isAllowManualAlign = content.isAllowManualAlign;
    this->isAllowBackAlign = content.isAllowBackAlign;
    /* Camera Parameters for Align */
    this->isShapeMatch = content.isShapeMatch;
    this->isGrayMatch = content.isGrayMatch;
    this->exposureTime = content.exposureTime;
    this->focalOffset = content.focalOffset;
    this->rectROI = content.rectROI;
    return *this;
}
