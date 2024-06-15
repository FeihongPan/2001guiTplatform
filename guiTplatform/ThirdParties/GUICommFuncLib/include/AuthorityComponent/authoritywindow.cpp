#include "authoritywindow.h"
#include "StyleSheet/stylesheet.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "CustomerWidget/Dialog/logindialog.h"
#include "Language/language.h"

AuthorityWindow::AuthorityWindow(QWidget *parent) : QMainWindow(parent)
{
    connect(UserSubscriber::getInstance(), &UserSubscriber::userChanged, this, [ = ](S_UserInfo & user)
    {
        this->user = user;
        userChanged(this->user);
    });
}
