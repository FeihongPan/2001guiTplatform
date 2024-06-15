#include "authoritywdgmanager.h"
#include "FileSystem/filesystem.h"
#include "AuthorityManage/Subscriber/userSubscriber.h"
#include <QMutex>
#include <QDebug>
AuthorityWdgManager *AuthorityWdgManager::self = nullptr;
AuthorityWdgManager::AuthorityWdgManager(QObject *parent) : QObject(parent)
{
    connect(UserSubscriber::getInstance(), &UserSubscriber::userChanged, this, &AuthorityWdgManager::changeView);
}

AuthorityWdgManager *AuthorityWdgManager::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new AuthorityWdgManager;
        }
    }
    return self;
}

void AuthorityWdgManager::SetMainWindow(MainWindow *w)
{
    this->mainWindow = w;
}

MainWindow *AuthorityWdgManager::GetMainWindow()
{
    return this->mainWindow;
}

void AuthorityWdgManager::InitOpt(NaviButton *btn, AuthorityWidget *view, QStackedWidget *wdg, AuthorityWindow *mainWindow, int index, bool left)
{
    int i = wdg->addWidget(view);
    view->ItemInitialize(left);
    connect(btn, &QPushButton::toggled, this, [ = ]
    {
        wdg->setCurrentIndex(i);
    });

    connect(UserSubscriber::getInstance(), &UserSubscriber::userChanged, this, [ = ](S_UserInfo & user)
    {
        view->user = user;
        view->UserChanged(user);
        btn->setEnabled(view->wdgInfo->accessLevels.contains(view->user.accessLevel));
        QList<int> lst_Keys = dic_Buttons.keys();
        for(int i = 0; i < lst_Keys.count(); i++)
        {
            if(dic_Buttons[lst_Keys[i]]->isEnabled())
            {
                dic_Buttons[lst_Keys[i]]->setChecked(true);
                break;
            }
        }
    });

    connect(view, &AuthorityWidget::ViewStatusChanged, btn, &NaviButton::RecivedViewStatus);

    connect(mainWindow, &AuthorityWindow::MainWindowIntialized, view, [ = ]
    {
        view->PublisherInitialize();
        view->ConstructFinished();
        emit view->Signal_ConstructFinished();
    });

    connect(mainWindow, &AuthorityWindow::MachineContollerLoadFinished, view, [ = ]
    {
        view->MachineControllerLoadFinished();
        emit view->Signal_MachineControllerLoadFinished();
    });

    connect(mainWindow, &AuthorityWindow::MachineStateChanged, view, [ = ](int state)
    {
        view->SetMachineState(state);
        emit view->MachineStateChanged(state);
    });

    lst_AuthorityWidgets.insert(index, view);
    dic_Buttons.insert(index, btn);
}

void AuthorityWdgManager::InitOpt(NaviButton *btn, AuthorityWidget *view, QStackedWidget *wdg, AuthorityWidget *parent, int index)
{
    int i = wdg->addWidget(view);
    view->ItemInitialize();
    connect(btn, &QPushButton::toggled, this, [ = ]
    {
        wdg->setCurrentIndex(i);
    });

    connect(UserSubscriber::getInstance(), &UserSubscriber::userChanged, this, [ = ](S_UserInfo & user)
    {
        view->user = user;
        view->UserChanged(user);
        btn->setEnabled(view->wdgInfo->accessLevels.contains(view->user.accessLevel));
        QList<int> lst_Keys = parent->dic_SubButtons.keys();
        for(int i = 0; i < lst_Keys.count(); i++)
        {
            if(parent->dic_SubButtons[lst_Keys[i]]->isEnabled())
            {
                parent->dic_SubButtons[lst_Keys[i]]->setChecked(true);
                break;
            }
        }
    });
    connect(view, &AuthorityWidget::ViewStatusChanged, btn, &NaviButton::RecivedViewStatus);
    connect(view, &AuthorityWidget::ViewStatusChanged, parent, &AuthorityWidget::RecivedViewStatus);

    connect(parent, &AuthorityWidget::Signal_ConstructFinished, view, [ = ]()
    {
        view->PublisherInitialize();
        view->ConstructFinished();
        emit view->Signal_ConstructFinished();
    });

    connect(parent, &AuthorityWidget::Signal_MachineControllerLoadFinished, view, [ = ]
    {
        view->MachineControllerLoadFinished();
        emit view->Signal_MachineControllerLoadFinished();
    });

    connect(parent, &AuthorityWidget::MachineStateChanged, view, [ = ](int state)
    {
        view->SetMachineState(state);
        emit view->MachineStateChanged(state);
    });

    parent->lst_SubWidget.append(view);
    parent->dic_SubButtons.insert(index, btn);
    view->parentWidget = parent;
}

void AuthorityWdgManager::InitOpt(AuthorityWidget *view, AuthorityWidget *parent)
{
    view->ItemInitialize();

    connect(UserSubscriber::getInstance(), &UserSubscriber::userChanged, this, [ = ](S_UserInfo & user)
    {
        view->user = user;
    });

    connect(parent, &AuthorityWidget::Signal_ConstructFinished, view, [ = ]()
    {
        view->ConstructFinished();
        emit view->Signal_ConstructFinished();
    });

    connect(parent, &AuthorityWidget::Signal_MachineControllerLoadFinished, view, [ = ]
    {
        view->MachineControllerLoadFinished();
        emit view->Signal_MachineControllerLoadFinished();
    });

    connect(parent, &AuthorityWidget::MachineStateChanged, view, [ = ](int state)
    {
        view->SetMachineState(state);
        qDebug() << "parent, &AuthorityWidget::MachineStateChanged";
        emit view->MachineStateChanged(state);
    });

    parent->lst_SubWidget.append(view);
    view->parentWidget = parent;
}

void AuthorityWdgManager::SetMainStackedWidget(QStackedWidget *wdg)
{
    this->MainStackedWidget = wdg;
}

void AuthorityWdgManager::changeView(S_UserInfo &user)
{
    //    dic_Buttons[0]->setChecked(true);
    //    lst_AuthorityWidgets[0]->dic_SubButtons[0]->setChecked(true);
}

void AuthorityWdgManager::Initialize()
{
    if(ReadFormFile())
    {
        setWidgetAuthority(lst_AuthorityWidgets, authorityWdgInfo.subWidgets);
    }
}

bool AuthorityWdgManager::ReadFormFile()
{
    QByteArray arr;
    if(FileSystem::Read_CRC(filePath, arr))
    {
        authorityWdgInfo.fromJson(arr);
        return true;
    }
    return false;
}

bool AuthorityWdgManager::WriteToFile()
{
    return FileSystem::Write_CRC(folderPath, fileName, authorityWdgInfo.toRawJson());
}

AuthorityWidget *AuthorityWdgManager::GetAuthorityWidget(QString name)
{
    AuthorityWidget *wdg = NULL;
    for(int i = 0; i < lst_AuthorityWidgets.count(); i++)
    {
        if(lst_AuthorityWidgets[i]->wdgInfo->wdgName == name)
        {
            wdg = lst_AuthorityWidgets[i];
            return wdg;
        }

        for(int j = 0; j < lst_AuthorityWidgets[i]->lst_SubWidget.count(); j++)
        {
            if(lst_AuthorityWidgets[i]->lst_SubWidget[j]->wdgInfo->wdgName == name)
            {
                wdg = lst_AuthorityWidgets[i]->lst_SubWidget[j];
                return wdg;
            }
        }
    }
    return wdg;
}

void AuthorityWdgManager::setEmptyWdgLinkInfo(QList<AuthorityWdgInfo> &lst)
{
    for(int i = 0; i < lst.count(); i++)
    {
        if(dic_AuthorityWidgets[lst[i].wdgName] == nullptr)
        {
            dic_AuthorityWidgets.insert(lst[i].wdgName, new AuthorityWidget(QString()));
        }
        setEmptyWdgLinkInfo(lst[i].subWidgets);
    }
}

void AuthorityWdgManager::setWidgetAuthority(QList<AuthorityWidget *> wdgs, QList<AuthorityWdgInfo> &wdgsInfo)
{
    foreach(AuthorityWidget *wdg, wdgs)
    {
        bool find = false;
        int index = 0;
        for(int i = 0; i < wdgsInfo.count(); i++)
        {
            if(wdg->wdgInfo->wdgName == wdgsInfo[i].wdgName)
            {
                index = i;
                wdg->wdgInfo = &wdgsInfo[i];
                find = true;
                break;
            }
        }
        if(!find)
        {
            AuthorityWdgInfo *wdgInfo = new AuthorityWdgInfo();
            wdgInfo->wdgName = wdg->wdgInfo->wdgName;
            wdgsInfo.append(*wdgInfo);
            wdg->wdgInfo = &wdgsInfo[wdgsInfo.count() - 1];
            index = wdgsInfo.count() - 1;
        }
        setWidgetAuthority(wdg->lst_SubWidget, wdgsInfo[index].subWidgets);
    }
}

void AuthorityWdgManager::getWidgetAuthority(QList<AuthorityWidget *> wdgs, AuthorityWdgInfo &wdgInfo)
{
    //    foreach(AuthorityWidget *wdg, wdgs)
    //    {
    //        wdgInfo.subWidgets.append(wdg->wdgInfo);
    //    }
}
