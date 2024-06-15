#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include "GUICommFuncLib_global.h"

#include "qpdfsearchresult.h"

#include <QWidget>

class SearchModel;
class QPdfDocument;

class GUICOMMFUNCLIB_EXPORT SearchView : public QWidget
{
    Q_OBJECT

public:
    explicit SearchView(QWidget *parent = nullptr);

    void SetDocument(QPdfDocument *document);

signals:
    void sigActivated(const QPdfSearchResult &);

private:
    SearchModel *m_pModel;
};

#endif // SEARCHVIEW_H
