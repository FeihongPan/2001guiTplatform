#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include "GUIComponentLib_global.h"

#include <QDialog>
#include <QMap>
#include <QGraphicsBlurEffect>
namespace Ui {
class MessageDialog;
}

class GUICOMPONENTLIB_EXPORT MessageDialog : public QDialog
{
    Q_OBJECT

public:
    enum NoticeType
    {
        Success,     ///成功
        Attention,   ///警告
        Error,       ///错误
    };
    Q_ENUM(NoticeType)

    explicit MessageDialog(NoticeType type, QWidget *parent = nullptr, const QString msg = QString());
    ~MessageDialog();

    ///设置装饰条颜色
    void SetNoticeColor(QString success, QString attention, QString error);
    ///设置图标
    void SetNoticeIcon(QString success, QString attention, QString error);

    virtual void showEvent(QShowEvent *event) override;
    virtual void hideEvent(QHideEvent *event) override;
    virtual void reject() override;

signals:
    void Showed();
    void Hided();

private:
    Ui::MessageDialog *ui;
    NoticeType noticeType;
    QMap<NoticeType, QString> dic_NoticeColor;
    QMap<NoticeType, QString> dic_NoticeIcon;
};

#endif // MESSAGEDIALOG_H
