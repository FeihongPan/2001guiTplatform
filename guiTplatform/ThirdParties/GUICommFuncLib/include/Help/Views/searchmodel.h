#ifndef SEARCHMODEL_H
#define SEARCHMODEL_H

#include "GUICommFuncLib_global.h"

#include "qpdfsearchmodel.h"

class GUICOMMFUNCLIB_EXPORT SearchModel : public QPdfSearchModel
{
    Q_OBJECT

public:
    explicit SearchModel(QObject *parent = nullptr);

    virtual QVariant data(const QModelIndex &index, int role) const override;
};

#endif // SEARCHMODEL_H
