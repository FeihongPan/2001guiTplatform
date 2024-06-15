#include "pdfview.h"

#include "qpdfdocument.h"
#include "qpdfpagenavigation.h"

#include <QScreen>
#include <QPainter>
#include <QScrollBar>
#include <QGuiApplication>

PdfView::PdfView(QWidget *parent)
    : QPdfView(parent)
    , m_screenResolution(QGuiApplication::primaryScreen()->logicalDotsPerInch() / 72.0)
    , m_searchPage(-1)
{

}

void PdfView::Search(const QPdfSearchResult &data)
{
    m_searchPage = data.page();
    m_vecSearchRect = data.rectangles();
    pageNavigation()->setCurrentPage(data.page());
    update();
}

void PdfView::paintEvent(QPaintEvent *event)
{
    QPdfView::paintEvent(event);

    auto doc = document();
    if (!doc || doc->status() != QPdfDocument::Ready)
    {
        return ;
    }

    const int startPage = (pageMode() == QPdfView::SinglePage ? pageNavigation()->currentPage() : 0);
    const int endPage = (pageMode() == QPdfView::SinglePage ? pageNavigation()->currentPage() + 1 : doc->pageCount());

    if (startPage > m_searchPage && m_searchPage >= endPage)
    {
        return;
    }

    QPainter painter(viewport());
    auto tmpViewport(QRect(horizontalScrollBar()->value(), verticalScrollBar()->value(), viewport()->width(), viewport()->height()));
    painter.translate(-tmpViewport.x(), -tmpViewport.y());

    QHash<int, QRect> pageGeometries;

    // calculate page sizes
    int totalWidth = 0;
    auto docMargins = documentMargins();
    for (int page = startPage; page <= m_searchPage; ++page)
    {
        QSize pageSize;
        switch (zoomMode())
        {
        case QPdfView::CustomZoom:
            pageSize = QSizeF(doc->pageSize(page) * m_screenResolution * zoomFactor()).toSize();
            break;
        case QPdfView::FitToWidth:
            pageSize = QSizeF(doc->pageSize(page) * m_screenResolution).toSize();
            pageSize *= (qreal(tmpViewport.width() - docMargins.left() - docMargins.right()) / qreal(pageSize.width()));
            break;
        case QPdfView::FitInView:
            pageSize = QSizeF(doc->pageSize(page) * m_screenResolution).toSize();
            pageSize = pageSize.scaled(QSize(tmpViewport.size() + QSize(-docMargins.left() - docMargins.right(), -pageSpacing())), Qt::KeepAspectRatio);
            break;
        }
        totalWidth = qMax(totalWidth, pageSize.width());
        pageGeometries[page] = QRect(QPoint(0, 0), pageSize);
    }
    totalWidth += docMargins.left() + docMargins.right();

    // calculate page positions
    int pageY = docMargins.top();
    for (int page = startPage; page <= m_searchPage; ++page)
    {
        const QSize& pageSize = pageGeometries[page].size();

        // center horizontal inside the viewport
        const int pageX = (qMax(totalWidth, tmpViewport.width()) - pageSize.width()) / 2;

        pageGeometries[page].moveTopLeft(QPoint(pageX, pageY));

        pageY += pageSize.height() + pageSpacing();
    }

    double ratio = pageGeometries[m_searchPage].width() / doc->pageSize(m_searchPage).width();
    for (const auto & e : m_vecSearchRect)
    {
        painter.fillRect(QRectF(e.topLeft() * ratio + pageGeometries[m_searchPage].topLeft(), e.size() * ratio), QBrush(QColor(0,0,255,100)));
    }
}
