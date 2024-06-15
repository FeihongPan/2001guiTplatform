#ifndef AUTHORITYSETTINGVIEW_H
#define AUTHORITYSETTINGVIEW_H

#include "GUICommFuncLib_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "AuthorityManage/Data/userinfo.h"
#include "userinfomodel.h"
#include "viewaccesslevelmodel.h"

#include <QWidget>
#include <QStandardItemModel>

namespace Ui
{
    class AuthoritySettingView;
}

class GUICOMMFUNCLIB_EXPORT AuthoritySettingView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit AuthoritySettingView(QString name, QWidget *parent = nullptr);
    ~AuthoritySettingView();
    Ui::AuthoritySettingView *GetUI();
    void on_UpdateView(S_UsersInfo info);

    virtual void ConstructFinished() override;
private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys()override;
    virtual void setConnections() override;
    virtual void UserChanged(S_UserInfo &user) override;

    void userModelInitialize();
    void hideSuperAdmin();
    void setSelectedRow(QString name);
    void setEditorStatus();
    void setUserInfoLimit(SR_UserInfo &info);

private:
    Ui::AuthoritySettingView *ui;

    UserInfoModel *userModel;
    S_UsersInfo usersInfo;
    SR_UserInfo selectedUser;
    SR_UserInfo modifyingUser;
    TString pwdCheck;

    ViewAccessLevelModel *mainFuncModel;
    ViewAccessLevelModel *subFuncModel;
    AuthorityWidget *selectedMainView;
    AuthorityWidget *selectedSubView;
    bool bViewModelInitialized = false;
};

#endif // AUTHORITYSETTINGVIEW_H
