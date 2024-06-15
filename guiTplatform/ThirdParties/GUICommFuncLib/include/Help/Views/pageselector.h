#ifndef PAGESELECTOR_H
#define PAGESELECTOR_H

#include "GUICommFuncLib_global.h"

#include <QWidget>

class QLabel;
class QLineEdit;
class QToolButton;
class QPdfDocument;
class QPdfPageNavigation;

class GUICOMMFUNCLIB_EXPORT PageSelector : public QWidget
{
    Q_OBJECT

public:
    explicit PageSelector(QWidget *parent = nullptr);

    void setPageNavigation(QPdfPageNavigation *pageNavigation);

private slots:
    void onCurrentPageChanged(int page);
    void pageNumberEdited();

private:
    QPdfPageNavigation *m_pageNavigation;

    QLineEdit *m_pageNumberEdit;
    QLabel *m_pageCountLabel;
    QToolButton *m_previousPageButton;
    QToolButton *m_nextPageButton;
};

#endif // PAGESELECTOR_H
