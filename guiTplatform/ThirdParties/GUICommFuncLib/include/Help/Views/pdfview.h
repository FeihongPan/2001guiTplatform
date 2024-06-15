#ifndef PDFVIEW_H
#define PDFVIEW_H

#include "GUICommFuncLib_global.h"

#include "qpdfview.h"
#include "qpdfsearchresult.h"

class GUICOMMFUNCLIB_EXPORT PdfView : public QPdfView
{
    Q_OBJECT

public:
    explicit PdfView(QWidget *parent = nullptr);

public slots:
    void Search(const QPdfSearchResult &);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    double m_screenResolution;
    int m_searchPage;
    QVector<QRectF> m_vecSearchRect;
};

#endif // PDFVIEW_H
