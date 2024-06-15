#ifndef HELPVIEW_H
#define HELPVIEW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"

class PdfView;
class QPdfDocument;
class PageSelector;
class ZoomSelector;

class GUICOMMFUNCLIB_EXPORT HelpView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit HelpView(QString name, QWidget *parent = nullptr);
    ~HelpView();

private slots:
    void slotBookmarkSelected(const QModelIndex &index);

private:
    PdfView *m_pPdfView;
    QPdfDocument *m_pDoc;
    PageSelector *m_pPageSelector;
    ZoomSelector *m_pZoomSelector;

    QString m_strFileName;
};

#endif // HELPVIEW_H
