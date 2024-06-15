#include "searchview.h"

#include "searchmodel.h"

#include <QLineEdit>
#include <QListView>
#include <QVBoxLayout>

SearchView::SearchView(QWidget *parent)
    : QWidget(parent)
    , m_pModel(new SearchModel(this))
{
    QVBoxLayout *pMainLayout = new QVBoxLayout(this);

    QFont font = QFont("HarmonyOS Sans",12);
    QLineEdit *pLineEdit=new QLineEdit;
    pLineEdit->setMinimumHeight(30);
    pLineEdit->setFont(font);
    pMainLayout->addWidget(pLineEdit);

    QListView *pListView = new QListView;
    //pListView->setHeaderHidden(true);
    pListView->setModel(m_pModel);
    pMainLayout->addWidget(pListView);

    connect(pLineEdit, &QLineEdit::editingFinished, this, [=]()
    {
        m_pModel->setSearchString(pLineEdit->text());
    });
    connect(pListView, &QListView::activated, this, [=](const QModelIndex &index)
    {
        if (index.isValid())
        {
            emit sigActivated(m_pModel->resultAtIndex(index.row()));
        }
    });
}

void SearchView::SetDocument(QPdfDocument *document)
{
    m_pModel->setDocument(document);
}
