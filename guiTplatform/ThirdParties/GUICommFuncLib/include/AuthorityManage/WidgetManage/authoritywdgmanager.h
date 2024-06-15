#ifndef AUTHORITYWDGMANAGER_H
#define AUTHORITYWDGMANAGER_H

#include "GUICommFuncLib_global.h"

#include "authoritywdginfo.h"
#include "AuthorityComponent/navibutton.h"
#include "AuthorityComponent/authoritywidget.h"
#include "AuthorityComponent/authoritywindow.h"
#include "AppConfig/AppParameter.h"
#include <QObject>
#include <QStackedWidget>
#include <QMap>

class MainWindow;

class GUICOMMFUNCLIB_EXPORT AuthorityWdgManager : public QObject
{
    Q_OBJECT
public:
    explicit AuthorityWdgManager(QObject *parent = nullptr);
    static AuthorityWdgManager *getInstance();

    void SetMainWindow(MainWindow *w);
    MainWindow *GetMainWindow();
    void InitOpt(NaviButton *btn, AuthorityWidget *view, QStackedWidget *wdg, AuthorityWindow *mainWindow, int index, bool left);
    void InitOpt(NaviButton *btn, AuthorityWidget *view, QStackedWidget *wdg, AuthorityWidget *parent, int index);
    void InitOpt(AuthorityWidget *view, AuthorityWidget *parent);
    void SetMainStackedWidget(QStackedWidget *wdg);

    void Initialize();
    bool ReadFormFile();
    bool WriteToFile();
    AuthorityWidget *GetAuthorityWidget(QString name);

signals:

public slots:

private:
    void setEmptyWdgLinkInfo(QList<AuthorityWdgInfo> &lst);
    void setWidgetAuthority(QList<AuthorityWidget *> wdgs, QList<AuthorityWdgInfo> &wdgsInfo);
    void getWidgetAuthority(QList<AuthorityWidget *> wdgs, AuthorityWdgInfo &wdgInfo);
    void changeView(S_UserInfo &user);

public:
    AuthorityWdgInfo authorityWdgInfo;
    QMap<QString, AuthorityWidget *> dic_AuthorityWidgets;
    QList<AuthorityWidget *> lst_AuthorityWidgets;
    QMap<int, QPushButton *> dic_Buttons;

private:
    static AuthorityWdgManager *self;
    QStackedWidget *MainStackedWidget;
    MainWindow *mainWindow = NULL;

    QString folderPath = DataPath + "AuthorityWdgInfo";
    QString fileName = "AuthorityWdgInfo.json";
    QString filePath = folderPath + "/" + fileName;
};

#endif // AUTHORITYWDGMANAGER_H
