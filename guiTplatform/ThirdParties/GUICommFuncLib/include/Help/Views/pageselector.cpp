#include "pageselector.h"

#include "qpdfpagenavigation.h"

#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QHBoxLayout>

PageSelector::PageSelector(QWidget *parent)
    : QWidget(parent)
    , m_pageNavigation(nullptr)
{
    QHBoxLayout *layout = new QHBoxLayout(this);


    QFont font = QFont("HarmonyOS Sans",12);
    m_previousPageButton = new QToolButton(this);
    m_previousPageButton->setText("<");
    m_previousPageButton->setEnabled(false);
    m_previousPageButton->setMinimumSize(30,30);
    m_previousPageButton->setFont(font);

    m_pageNumberEdit = new QLineEdit(this);
    m_pageNumberEdit->setAlignment(Qt::AlignRight);
    m_pageNumberEdit->setFixedSize(60,30);
    m_pageNumberEdit->setFont(font);

    m_pageCountLabel = new QLabel(this);
    m_pageCountLabel->setText("0");
    m_pageCountLabel->setFont(font);

    m_nextPageButton = new QToolButton(this);
    m_nextPageButton->setText(">");
    m_nextPageButton->setEnabled(false);
    m_nextPageButton->setMinimumSize(30,30);
    m_nextPageButton->setFont(font);

    layout->addWidget(m_previousPageButton);
    layout->addWidget(m_pageNumberEdit);
    layout->addWidget(m_pageCountLabel);
    layout->addWidget(m_nextPageButton);
}

void PageSelector::setPageNavigation(QPdfPageNavigation *pageNavigation)
{
    m_pageNavigation = pageNavigation;

    connect(m_previousPageButton, &QToolButton::clicked, m_pageNavigation, &QPdfPageNavigation::goToPreviousPage);
    connect(m_pageNavigation, &QPdfPageNavigation::canGoToPreviousPageChanged, m_previousPageButton, &QToolButton::setEnabled);

    connect(m_pageNavigation, &QPdfPageNavigation::currentPageChanged, this, &PageSelector::onCurrentPageChanged);
    connect(m_pageNavigation, &QPdfPageNavigation::pageCountChanged, this, [this](int pageCount)
    {
        m_pageCountLabel->setText(QString::fromLatin1("/ %1").arg(pageCount));
    });

    connect(m_pageNumberEdit, &QLineEdit::editingFinished, this, &PageSelector::pageNumberEdited);

    connect(m_nextPageButton, &QToolButton::clicked, m_pageNavigation, &QPdfPageNavigation::goToNextPage);
    connect(m_pageNavigation, &QPdfPageNavigation::canGoToNextPageChanged, m_nextPageButton, &QToolButton::setEnabled);

    onCurrentPageChanged(m_pageNavigation->currentPage());
}

void PageSelector::onCurrentPageChanged(int page)
{
    if (m_pageNavigation->pageCount() == 0)
        m_pageNumberEdit->setText(QString::number(0));
    else
        m_pageNumberEdit->setText(QString::number(page + 1));
}

void PageSelector::pageNumberEdited()
{
    if (!m_pageNavigation)
        return;

    const QString text = m_pageNumberEdit->text();

    bool ok = false;
    const int pageNumber = text.toInt(&ok);

    if (!ok)
        onCurrentPageChanged(m_pageNavigation->currentPage());
    else
        m_pageNavigation->setCurrentPage(qBound(0, pageNumber - 1, m_pageNavigation->pageCount() - 1));
}
