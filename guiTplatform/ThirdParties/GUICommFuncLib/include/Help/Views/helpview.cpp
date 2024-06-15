#include "helpview.h"

#include "pdfview.h"
#include "searchview.h"
#include "qpdfdocument.h"
#include "pageselector.h"
#include "zoomselector.h"
#include "Language/language.h"
#include "qpdfbookmarkmodel.h"
#include "qpdfpagenavigation.h"
#include "AppConfig/AppParameter.h"

#include <QPainter>
#include <QToolBar>
#include <QSplitter>
#include <QTreeView>
#include <QFileDialog>

HelpView::HelpView(QString name, QWidget *parent)
    : AuthorityWidget(name, parent)
    , m_pPdfView(new PdfView)
    , m_pDoc(new QPdfDocument(this))
    , m_pPageSelector(new PageSelector)
    , m_pZoomSelector(new ZoomSelector)
    , m_strFileName(DataPath + "Help/Operation Manual - iCB500.pdf")
{
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);
    {
        QToolBar *pToolBar = new QToolBar;
        {
            //m_pZoomSelector->setMaximumWidth(240);
            pToolBar->addWidget(m_pZoomSelector);
            pToolBar->addSeparator();
            pToolBar->addWidget(m_pPageSelector);
            m_pPageSelector->setMaximumWidth(200);
            pToolBar->addSeparator();
            //            QWidget *wdg = new QWidget;
            //            {
            //                QHBoxLayout *layout = new QHBoxLayout(wdg);
            //                QCheckBox *pCheckBox = new QCheckBox(Language::getInstance()->Translate("Continuous"));
            //                layout->addWidget(pCheckBox);
            //                connect(pCheckBox, &QCheckBox::stateChanged, this, [=](int state)
            //                {
            //                    m_pPdfView->setPageMode(state ? QPdfView::MultiPage : QPdfView::SinglePage);
            //                });
            //            }
            //            pToolBar->addWidget(wdg);
            //            pToolBar->addSeparator();
        }
        pMainLayout->addWidget(pToolBar);

        QSplitter *pSplitter = new QSplitter;
        {
            QTabWidget *pTabWdg = new QTabWidget;
            {
                QTreeView *pBookmarkView = new QTreeView;
                {
                    pBookmarkView->setHeaderHidden(true);
                    QPdfBookmarkModel *bookmarkModel = new QPdfBookmarkModel(this);
                    bookmarkModel->setDocument(m_pDoc);
                    pBookmarkView->setModel(bookmarkModel);

                    connect(pBookmarkView, SIGNAL(activated(QModelIndex)), this, SLOT(slotBookmarkSelected(QModelIndex)));
                }
                pTabWdg->addTab(pBookmarkView, Tr("Bookmarks"));

                SearchView *pSearchView = new SearchView;
                {
                    pSearchView->SetDocument(m_pDoc);

                    connect(pSearchView, &SearchView::sigActivated, m_pPdfView, &PdfView::Search);
                }
                pTabWdg->addTab(pSearchView, Tr("Search"));
            }

            QFont font = QFont("HarmonyOS Sans", 12);
            pTabWdg->setFont(font);
            pSplitter->addWidget(pTabWdg);
            pSplitter->addWidget(m_pPdfView);
            pSplitter->setStretchFactor(1, 1);
            pSplitter->setStretchFactor(2, 3);
        }
        pMainLayout->addWidget(pSplitter);
    }

    m_pPageSelector->setPageNavigation(m_pPdfView->pageNavigation());

    m_pPdfView->setDocument(m_pDoc);

    connect(m_pZoomSelector, &ZoomSelector::zoomModeChanged, m_pPdfView, &QPdfView::setZoomMode);
    connect(m_pZoomSelector, &ZoomSelector::zoomFactorChanged, m_pPdfView, &QPdfView::setZoomFactor);

    m_pZoomSelector->reset();

    QFile fp(m_strFileName);
    if (!fp.exists())
    {
        qDebug() << "HelpView::HelpView --The pdf file \"" << m_strFileName << "\" does not exist.";
    }
    else
    {
        m_pDoc->load(m_strFileName);
        m_pPdfView->pageNavigation()->currentPageChanged(0);
    }

    // test
    //    QUrl docLocation = QFileDialog::getOpenFileUrl(this, tr("Choose a PDF"), QUrl(), "Portable Documents (*.pdf)");
    //    if (docLocation.isValid() && docLocation.isLocalFile())
    //    {
    //        m_pDoc->load(docLocation.toLocalFile());
    //        m_pPdfView->pageNavigation()->currentPageChanged(0);
    //    }
}

HelpView::~HelpView()
{

}

void HelpView::slotBookmarkSelected(const QModelIndex &index)
{
    if (index.isValid())
    {
        const int page = index.data(QPdfBookmarkModel::PageNumberRole).toInt();
        m_pPdfView->pageNavigation()->setCurrentPage(page);
    }
}
