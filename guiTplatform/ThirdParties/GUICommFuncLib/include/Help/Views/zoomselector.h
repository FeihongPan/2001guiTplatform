#ifndef ZOOMSELECTOR_H
#define ZOOMSELECTOR_H

#include "GUICommFuncLib_global.h"

#include "qpdfview.h"

#include <QWidget>

class QComboBox;
class QToolButton;

class GUICOMMFUNCLIB_EXPORT ZoomSelector : public QWidget
{
    Q_OBJECT

public:
    explicit ZoomSelector(QWidget *parent = nullptr);

public slots:
    void reset();

signals:
    void zoomModeChanged(QPdfView::ZoomMode zoomMode);
    void zoomFactorChanged(qreal zoomFactor);

private slots:
    void onCurrentTextChanged(const QString &text);

private:
    qreal string2zoomFactor(const QString &str);

private:
    int m_nItemCount;
    QComboBox *m_pComboBox;
    QToolButton *m_pZoomInBtn;
    QToolButton *m_pZoomOutBtn;
};

#endif // ZOOMSELECTOR_H
