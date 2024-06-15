#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "GUIComponentLib_global.h"

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class GUICOMPONENTLIB_EXPORT LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    virtual void reject() override;
public slots:
    void RecivedLoginInfo(int res);   ///返回结果 0--成功 1--用户错误 2--密码错误
signals:
    void SendLoginInfo(QString userName, QString password);  ///发送用户信息

private:
    Ui::LoginDialog *ui;
//    QWidget *parent;
    QString userName;
    QString password;
};

#endif // LOGINDIALOG_H
