#include "authoritysettingview.h"
#include "ui_authoritysettingview.h"
#include "Converter/enumconverter.h"
#include "Language/language.h"
#include "CustomerWidget/Dialog/messagedialog.h"
#include "AuthorityManage/Subscriber/userSubscriber.h"
#include "AuthorityManage/WidgetManage/authoritywdgmanager.h"
#include "Communication/MQTT/publisher.h"
#include "StyleSheet/stylesheet.h"
#include "CustomerWidget/Delegate/checkboxdelegate.h"

AuthoritySettingView::AuthoritySettingView(QString name, QWidget *parent) :
    AuthorityWidget(name, parent),
    ui(new Ui::AuthoritySettingView)
{
    ui->setupUi(this);
}

AuthoritySettingView::~AuthoritySettingView()
{
    delete ui;
}

Ui::AuthoritySettingView *AuthoritySettingView::GetUI()
{
    return ui;
}

void AuthoritySettingView::on_UpdateView(S_UsersInfo info)
{
    qDebug() << "UserInterpreter::sendUsersInfo";
    usersInfo = info;
    userModel->resetModel(&usersInfo);
    hideSuperAdmin();
}

void AuthoritySettingView::ConstructFinished()
{
    m_Publisher.Publish("User", EnumConverter::ConvertToString(CMD_User::CMD_UsersInfo));
}

void AuthoritySettingView::setWidgets()
{
    QRegExp rx("[_|a-zA-Z0-9|]+$");
    ui->led_ModifyUser_Name->setValidator(new QRegExpValidator(rx, this));
    ui->led_ModifyUser_Name->setMaxLength(10);
    ui->led_ModifyUser_Password->setValidator(new QRegExpValidator(rx, this));
    ui->led_ModifyUser_Password->setMaxLength(16);
    ui->led_ModifyUser_PasswordCheck->setValidator(new QRegExpValidator(rx, this));
    ui->led_ModifyUser_PasswordCheck->setMaxLength(16);
}

void AuthoritySettingView::setWidgetStyleSheet()
{
    ui->tabWidget->setTabText(0, Tr("Users"));
    ui->tabWidget->setTabText(1, Tr("Views"));
    ui->tabWidget->setStyleSheet(GlobalStyleSheet->TabWidget + "QTabWidget" + GlobalStyleSheet->fontStyle_export_14);
    ui->tabAccess->setStyleSheet(GlobalStyleSheet->fontStyle_normal_12);
    ui->tabUser->setStyleSheet( "QGroupBox,QLabel,QLineEdit,IconLineEdit,QTableView,Comboboxcomn, QAbstractItemView,QHeaderView" + GlobalStyleSheet->fontStyle_export_12 +
                                "QButton#btn_CreateNewUser,#btn_UserModify,#btn_UserDelete,#btn_SaveUsersInfo,#btn_ComfirmUserChange,#btn_UserChangeCancel" + GlobalStyleSheet->fontStyle_export_12);

#pragma region gpb_Users{
    ui->gpb_Users->SetheaderFontSize(16);
    ui->gpb_Users->SetHeaderText(Tr("User List"));

    ui->lbl_SelectedUserName->setText(Tr("Selected User"));
    ui->led_SelectedUserName->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    ui->lbl_Filter->setText(Tr("Filter"));
    ui->led_SearchValue->SetIconDock(IconLineEdit::Right);
    ui->led_SearchValue->SetIconFont(GlobalStyleSheet->Font());
    ui->led_SearchValue->setTextMargins(0,0,35,0);
    ui->led_SearchValue->SetIcon(QString(0xa024), 14);

    ui->btn_CreateNewUser->setText(Tr("New"));
    ui->btn_CreateNewUser->setStyleSheet(GlobalStyleSheet->Button_Border);

    ui->btn_UserModify->setText(Tr("Modify"));
    ui->btn_UserModify->setStyleSheet(GlobalStyleSheet->Button_Border);

    ui->btn_UserDelete->setText(Tr("Delete"));
    ui->btn_UserDelete->setStyleSheet(GlobalStyleSheet->Button_Border);

    ui->btn_SaveUsersInfo->setText(Tr("Save"));
    ui->btn_SaveUsersInfo->setStyleSheet(GlobalStyleSheet->Button_Border);
#pragma endregion}

#pragma region gpb_UserModify{
    ui->gpb_UserModify->SetheaderFontSize(16);
    ui->gpb_UserModify->SetHeaderText(Tr("User Setting"));

    ui->lbl_ModifyUser_Name->setText(Tr("User Name"));
    ui->led_ModifyUser_Name->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    ui->lbl_ModifyUser_Password->setText(Tr("Password"));
    ui->led_ModifyUser_Password->setStyleSheet(GlobalStyleSheet->LineEdit_Dark);

    ui->lbl_ModifyUser_PasswordCheck->setText(Tr("Double Check"));
    ui->led_ModifyUser_PasswordCheck->SetIconDock(IconLineEdit::Right);
    ui->led_ModifyUser_PasswordCheck->SetIconFont(GlobalStyleSheet->Font());
    ui->led_ModifyUser_PasswordCheck->setTextMargins(0,0,35,0);
    ui->led_ModifyUser_PasswordCheck->SetIcon(QString(0xa024), 14);

    ui->lbl_ModifyUser_AccessLevel->setText(Tr("AccessLevel"));
    ui->btn_ComfirmUserChange->setText(Tr("Confirm"));
    ui->btn_ComfirmUserChange->setStyleSheet(GlobalStyleSheet->Button_Border);

    ui->btn_UserChangeCancel->setText(Tr("Cancel"));
    ui->btn_UserChangeCancel->setStyleSheet(GlobalStyleSheet->Button_Border);
#pragma endregion}

#pragma region gpb_UserModify{
    ui->lbl_MainFunc->setText(Tr("Main Function"));
    ui->lbl_SubFunc->setText(Tr("Sub Function"));
    ui->btn_SaveViewsInfo->setText(Tr("Save"));
    ui->btn_SaveViewsInfo->setStyleSheet(GlobalStyleSheet->Button_Border);
#pragma endregion}
}

void AuthoritySettingView::setLanguageKeys()
{
    Tr("A_User_Delete");
    Tr("A_DeleteConfirm");
    Tr("E_User_DeleteNotAllowed");
    Tr("E_User_nameRepeat");
    Tr("E_Password_NotMatch");
    Tr("E_AccessLevel_NotAlowed");
    Tr("S_User_Create");
    Tr("S_User_Modify");
    Tr("A_User_ModifyCancel");
    Tr("A_ModifyCancelConfirm");
    Tr("Users");
    Tr("Views");
    Tr("User List");
    Tr("Selected User");
    Tr("Filter");
    Tr("New");
    Tr("Modify");
    Tr("Delete");
    Tr("Save");
    Tr("User Setting");
    Tr("User Name");
    Tr("Password");
    Tr("Double Check");
    Tr("AccessLevel");
    Tr("Confirm");
    Tr("Cancel");
    Tr("Main Function");
    Tr("Sub Function");
    Tr("Save");
}

void AuthoritySettingView::setConnections()
{
#pragma region Users{
    setUserInfoLimit(selectedUser);
    setUserInfoLimit(modifyingUser);
    pwdCheck.SetMinLength(0);
    pwdCheck.SetMaxLength(16);

    userModelInitialize();
    Binding(&selectedUser.userName, ui->led_SelectedUserName);
    Binding(&modifyingUser.userName, ui->led_ModifyUser_Name);
    Binding(&modifyingUser.password, ui->led_ModifyUser_Password);
    Binding(&pwdCheck, ui->led_ModifyUser_PasswordCheck);
    Binding(&modifyingUser.accessLevel, ui->cmb_ModifyUser_AccessLevel);

    connect(ui->tbw_Users, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        selectedUser = ui->tbw_Users->model()->data(index, Qt::UserRole).value<S_UserInfo>();
        setEditorStatus();
    });

    connect(ui->led_SearchValue, &QLineEdit::textChanged, this, [ = ](QString str)
    {
        for(int i = 0; i < ui->tbw_Users->model()->rowCount(); i++)
        {
            ui->tbw_Users->setRowHidden(i, true);
            QAbstractItemModel *model = ui->tbw_Users->model();
            QModelIndex index;
            index = model->index(i, 0);
            if(model->data(index).toString().contains(str, Qt::CaseInsensitive)
                    && EnumConverter::ConvertStringToEnum<AccessLevel::Level>(model->data(model->index(i, 1)).toString()) != AccessLevel::SuperAdmin)
            {
                ui->tbw_Users->setRowHidden(i, false);
            }
        }
    });

    connect(ui->btn_CreateNewUser, &QPushButton::clicked, this, [ = ]
    {
        selectedUser = SR_UserInfo();
        setUserInfoLimit(selectedUser);
        status = ViewStatus::Adding;
        emit ViewStatusChanged(status);
        setEditorStatus();
        pwdCheck.value.clear();
        modifyingUser.password.value.clear();
        ui->led_ModifyUser_Password->clear();
        ui->led_ModifyUser_PasswordCheck->clear();
        ui->led_ModifyUser_Name->clear();
        ui->led_ModifyUser_Password->clear();
        ui->led_ModifyUser_PasswordCheck->clear();
        if(ui->cmb_ModifyUser_AccessLevel->count() > 0)
        {
            ui->cmb_ModifyUser_AccessLevel->setCurrentIndex(0);
        }
    });

    connect(ui->btn_UserModify, &QPushButton::clicked, this, [ = ]
    {
        modifyingUser = selectedUser;
        status = ViewStatus::Modifying;
        emit ViewStatusChanged(status);
        setEditorStatus();
        pwdCheck.value.clear();
        modifyingUser.password.value.clear();
    });

    connect(ui->btn_UserDelete, &QPushButton::clicked, this, [ = ]
    {
        QString msg = Tr("A_User_Delete") + Tr(" '") +  selectedUser.userName.value
                + Tr("'") + Tr("? ") + Tr("A_DeleteConfirm");
        MessageDialog* dlg = new MessageDialog(MessageDialog::Attention, this, msg);
        dlg->setObjectName("deleteUser");
        if (dlg->exec() == QDialog::Rejected)
        {
            delete dlg;
            return;
        }
        delete dlg;

        if((AccessLevel::Level)modifyingUser.accessLevel.value == AccessLevel::Admin ||
		   (AccessLevel::Level)modifyingUser.accessLevel.value == AccessLevel::SuperAdmin)
        {
            MessageDialog dlg(MessageDialog::Attention, this, Tr("E_User_DeleteNotAllowed"));
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }
        usersInfo.lstUsersInfo.removeOne(selectedUser);
        selectedUser = SR_UserInfo();
        setUserInfoLimit(selectedUser);
        ui->tbw_Users->clearSelection();
        userModel->resetModel(&usersInfo);
        setEditorStatus();
        hideSuperAdmin();
    });

    connect(ui->led_ModifyUser_PasswordCheck, &IconLineEdit::iconPressed, this, [ = ]
    {
        ui->led_ModifyUser_Password->setEchoMode(QLineEdit::EchoMode::Normal);
        ui->led_ModifyUser_PasswordCheck->setEchoMode(QLineEdit::EchoMode::Normal);
    });

    connect(ui->led_ModifyUser_PasswordCheck, &IconLineEdit::iconReleased, this, [ = ]
    {
        ui->led_ModifyUser_Password->setEchoMode(QLineEdit::EchoMode::Password);
        ui->led_ModifyUser_PasswordCheck->setEchoMode(QLineEdit::EchoMode::Password);
    });

    connect(ui->btn_ComfirmUserChange, &QPushButton::clicked, this, [ = ]
    {
        //判断用户名是否为空
        if(modifyingUser.userName.value.isEmpty())
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_UserName_Empty"));
            dlg.setObjectName("userEmpry");
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }

        //判断修改密码是否为空
        if(modifyingUser.password.value.isEmpty())
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_Password_Empty"));
            dlg.setObjectName("passwdEmpry");
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }

        //判断修改密码确认是否为空
        if(pwdCheck.value.isEmpty())
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_PasswordCheck_Empty"));
            dlg.setObjectName("passwdCheckEmpry");
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }

        //判断修改密码是否一致
        if(modifyingUser.password.value != pwdCheck.value )
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_Password_NotMatch"));
            dlg.setObjectName("passwdMatch");
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }

        //判断用户名是否重复
        QList<QString> list;
        for (int i = 0; i < usersInfo.lstUsersInfo.size(); i++)
        {
            list.append(usersInfo.lstUsersInfo.at(i).userName.toUpper());
        }
        if(status == ViewStatus::Modifying)
        {
            list.removeOne(selectedUser.userName.value.toUpper());
        }
        if(list.contains(modifyingUser.userName.value.toUpper()))
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("E_UserName_Repeat"));
            dlg.setObjectName("repeat");
            if (dlg.exec() == QDialog::Accepted)
            {
                return;
            }
        }

        //判断修改的权限
        if(status == ViewStatus::Status::Adding)
        {
            //非普通用户只能添加普通用户
            if(modifyingUser.accessLevel.value >= AccessLevel::Admin || modifyingUser.accessLevel.value == AccessLevel::Level::Visitor)
            {
                MessageDialog dlg(MessageDialog::Error, this, Tr("E_AccessLevel_NotAlowed"));
                dlg.setObjectName("level");
                if (dlg.exec() == QDialog::Accepted)
                {
                    return;
                }
            }
        }
        else if(status == ViewStatus::Status::Modifying)
        {
            //超级用户
            if(user.accessLevel >= AccessLevel::Level::Admin)
            {
                //高级用户可以改比自己权限低的用户
                if((selectedUser.accessLevel.value < AccessLevel::Level::Admin &&
                     modifyingUser.accessLevel.value >= AccessLevel::Level::Admin) ||
                   (selectedUser.accessLevel.value != AccessLevel::Level::Visitor &&
                    modifyingUser.accessLevel.value == AccessLevel::Level::Visitor)  ||
                   (selectedUser.accessLevel.value == AccessLevel::Level::Visitor &&
                    modifyingUser.accessLevel.value != AccessLevel::Level::Visitor) )
                {
                    MessageDialog dlg(MessageDialog::Error, this, Tr("E_AccessLevel_NotAlowed"));
                    dlg.setObjectName("level");
                    if(dlg.exec() == QDialog::Accepted)
                    {
                        return;
                    }
                }
            }
        }


        if(status == ViewStatus::Status::Adding)
        {
            usersInfo.lstUsersInfo.append(modifyingUser);
            MessageDialog dlg(MessageDialog::Success, this, Tr("S_User_Create"));
            dlg.setObjectName("create");
            dlg.exec();
        }
        else if(status == ViewStatus::Status::Modifying)
        {
            for (int i=0; i<usersInfo.lstUsersInfo.size(); i++)
            {
                if(selectedUser.userName.value == usersInfo.lstUsersInfo.at(i).userName)
                {
                    usersInfo.lstUsersInfo[i] = modifyingUser;
                    break;
                }
            }
            MessageDialog dlg(MessageDialog::Success, this, Tr("S_User_Modify"));
            dlg.setObjectName("modify");
            dlg.exec();
        }
        userModel->resetModel(&usersInfo);
        hideSuperAdmin();
        setSelectedRow(modifyingUser.userName.value);
        status = ViewStatus::Idle;
        modifyingUser = SR_UserInfo();
        setUserInfoLimit(modifyingUser);
        pwdCheck = TString();
        pwdCheck.SetMinLength(0);
        pwdCheck.SetMaxLength(16);
        emit ViewStatusChanged(status);
        setEditorStatus();
        ui->tbw_Users->clicked(ui->tbw_Users->currentIndex());
    });

    connect(ui->btn_UserChangeCancel, &QPushButton::clicked, this, [ = ]
    {
        QString msg = Tr("A_User_ModifyCancel") + " " + Tr("A_ModifyCancelConfirm");
        MessageDialog*dlg = new MessageDialog(MessageDialog::Attention, this, msg);
        dlg->setObjectName("cancel");
        if (dlg->exec() == QDialog::Accepted)
        {
            modifyingUser = SR_UserInfo();
            setUserInfoLimit(modifyingUser);
            pwdCheck = TString();
            pwdCheck.SetMinLength(0);
            pwdCheck.SetMaxLength(16);
            emit ViewStatusChanged(status);
            status = ViewStatus::Idle;
            emit ViewStatusChanged(status);
            setEditorStatus();
            ui->tbw_Users->clicked(ui->tbw_Users->currentIndex());
        }
        delete dlg;
    });

    connect(UserSubscriber::getInstance(), &UserSubscriber::sendUsersInfo, this, &AuthoritySettingView::on_UpdateView);

    connect(ui->btn_SaveUsersInfo, &QPushButton::clicked, this, [ = ]
    {
        status = ViewStatus::Idle;
        emit ViewStatusChanged(status);
        m_Publisher.Publish("User", EnumConverter::ConvertToString(CMD_User::CMD_SaveUsersInfo), false, usersInfo.toRawJson());
//        GUIClient::getInstance()->AddCommandToQueue(UserInterpreter::getInstance()->ModuleName(),
//                                                    EnumConverter::ConvertToString(UserInterpreter::CMD_Send_SaveUsersInfo), usersInfo.toRawJson());
    });

    connect(UserSubscriber::getInstance(), &UserSubscriber::saveUsersInfoResult, this, [ = ](bool r)
    {
        if(r)
        {
            MessageDialog dlg(MessageDialog::Success, this, Tr("A_User_WriteOK"));
            dlg.exec();
        }
        else
        {
            MessageDialog dlg(MessageDialog::Error, this, Tr("A_User_WriteFail"));
            dlg.exec();
        }
    });


#pragma endregion}

#pragma region Widget{
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [ = ](int index)
    {
        if(!bViewModelInitialized && index == 1)
        {
            mainFuncModel = new ViewAccessLevelModel(this);
            subFuncModel = new ViewAccessLevelModel(this);
            subFuncModel->enable = true;

            mainFuncModel->SetModel(AuthorityWdgManager::getInstance()->lst_AuthorityWidgets);
            ui->tbw_MainFunc->setModel(mainFuncModel);
            for (int i = 0; i < mainFuncModel->rowCount(QModelIndex()); i++)
            {
                ui->tbw_MainFunc->setColumnWidth(i, 180);
            }

            for (int i = 0; i < mainFuncModel->columnCount(); i++)
            {
                ui->tbw_MainFunc->setColumnWidth(i, 180);
                if(i > 0)
                {
                    ui->tbw_MainFunc->setItemDelegateForColumn(i, CheckBoxDelegate::getInstance());
                }
            }

            ui->tbw_MainFunc->selectRow(0);
            selectedMainView = ui->tbw_MainFunc->model()->data(ui->tbw_MainFunc->currentIndex(), Qt::UserRole).value<AuthorityWidget *>();

            subFuncModel->SetModel(selectedMainView->lst_SubWidget);
            ui->tbw_SubFunc->setModel(subFuncModel);
            for (int i = 0; i < subFuncModel->columnCount(); i++)
            {
                ui->tbw_SubFunc->setColumnWidth(i, 180);
                if(i > 0)
                {
                    ui->tbw_SubFunc->setItemDelegateForColumn( i, CheckBoxDelegate::getInstance());
                }
            }
            bViewModelInitialized = true;
        }
    });

    connect(ui->tbw_MainFunc, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        if(index.column() == 0)
        {
            selectedMainView = ui->tbw_MainFunc->model()->data(index, Qt::UserRole).value<AuthorityWidget *>();
            subFuncModel->SetModel(selectedMainView->lst_SubWidget);
            subFuncModel->enable = true;
            subFuncModel->disableRow.clear();
            subFuncModel->disableColumn.clear();
            if(user.accessLevel != AccessLevel::SuperAdmin)
            {
                if(selectedMainView->wdgInfo->wdgName == "Setup")
                {
                    subFuncModel->disableRow.append(1);
                }
                subFuncModel->disableColumn.append(7);
            }
            subFuncModel->resetModel(selectedMainView->lst_SubWidget);
        }
    });

    connect(ui->tbw_SubFunc, &QTableView::clicked, this, [ = ](const QModelIndex & index)
    {
        selectedSubView = ui->tbw_SubFunc->model()->data(index, Qt::UserRole).value<AuthorityWidget *>();
        AuthorityWidget *parentWdg = selectedSubView->parentWidget;
        parentWdg->wdgInfo->accessLevels.clear();
        foreach(AuthorityWidget *wdg, parentWdg->lst_SubWidget)
        {
            foreach(AccessLevel::Level acl, wdg->wdgInfo->accessLevels)
            {
                if(!parentWdg->wdgInfo->accessLevels.contains(acl))
                {
                    parentWdg->wdgInfo->accessLevels.append(acl);
                }
            }
        }
        mainFuncModel->resetModel(AuthorityWdgManager::getInstance()->lst_AuthorityWidgets);
        status = ViewStatus::Modifying;
        emit ViewStatusChanged(status);
    });

    connect(ui->btn_SaveViewsInfo, &QPushButton::clicked, this, [ = ]
    {
        bool res = AuthorityWdgManager::getInstance()->WriteToFile();
        if(res)
        {
            status = ViewStatus::Idle;
            emit ViewStatusChanged(status);
            MessageDialog dlg(MessageDialog::Success, this, Tr("A_User_WriteOK"));
            dlg.exec();
        }
        else
        {
            status = ViewStatus::Alarm;
            emit ViewStatusChanged(status);
            MessageDialog dlg(MessageDialog::Error, this, Tr("A_User_WriteFail"));
            if(dlg.exec() == QDialog::Accepted)
            {
                status = ViewStatus::Idle;
                emit ViewStatusChanged(status);
            }
        }
    });
#pragma endregion}

}

void AuthoritySettingView::UserChanged(S_UserInfo &user)
{
    setEditorStatus();
}

void AuthoritySettingView::userModelInitialize()
{
    userModel = new UserInfoModel(this);
    userModel->SetModel(&usersInfo);
    ui->tbw_Users->setModel(userModel);
    ui->tbw_Users->setColumnWidth(0, 180);
    hideSuperAdmin();
}

void AuthoritySettingView::hideSuperAdmin()
{
    for(int i = 0; i < ui->tbw_Users->model()->rowCount(); i++)
    {
        QAbstractItemModel *model = ui->tbw_Users->model();
        if(EnumConverter::ConvertStringToEnum<AccessLevel::Level>(model->data(model->index(i, 1)).toString()) == AccessLevel::SuperAdmin)
        {
            ui->tbw_Users->setRowHidden(i, true);
        }
    }
}

void AuthoritySettingView::setSelectedRow(QString name)
{
    ui->tbw_Users->clearSelection();
    for(int i = 0; i < ui->tbw_Users->model()->rowCount(); i++)
    {
        QAbstractItemModel *model = ui->tbw_Users->model();
        QModelIndex index;
        index = model->index(i, 0);
        QString userName = (ui->tbw_Users->model()->data(index, Qt::UserRole).value<S_UserInfo>()).userName;
        if(userName == name)
        {
            ui->tbw_Users->selectRow(i);
            break;
        }
    }
}

void AuthoritySettingView::setEditorStatus()
{
    if(selectedUser.userName.value.isEmpty())
    {
        if(status == ViewStatus::Idle)
        {
            ui->tbw_Users->setEnabled(true);
            ui->btn_CreateNewUser->setEnabled(true);
            ui->btn_UserModify->setEnabled(false);
            ui->btn_UserDelete->setEnabled(false);
            ui->btn_SaveUsersInfo->setEnabled(true);
            ui->led_ModifyUser_Name->setEnabled(false);
            ui->led_ModifyUser_Password->setEnabled(false);
            ui->led_ModifyUser_PasswordCheck->setEnabled(false);
            ui->cmb_ModifyUser_AccessLevel->setEnabled(false);
            ui->btn_ComfirmUserChange->setEnabled(false);
            ui->btn_UserChangeCancel->setEnabled(false);
        }
        else
        {
            ui->tbw_Users->setEnabled(false);
            ui->btn_CreateNewUser->setEnabled(false);
            ui->btn_UserModify->setEnabled(false);
            ui->btn_UserDelete->setEnabled(false);
            ui->led_ModifyUser_Name->setEnabled(true);
            ui->led_ModifyUser_Password->setEnabled(true);
            ui->led_ModifyUser_PasswordCheck->setEnabled(true);
            ui->cmb_ModifyUser_AccessLevel->setEnabled(true);
            ui->btn_ComfirmUserChange->setEnabled(true);
            ui->btn_UserChangeCancel->setEnabled(true);
            ui->btn_SaveUsersInfo->setEnabled(false);
        }
    }
    else
    {
        if(status == ViewStatus::Idle)
        {
            ui->tbw_Users->setEnabled(true);
            ui->btn_CreateNewUser->setEnabled(true);
            ui->btn_UserModify->setEnabled(true);
            ui->btn_UserDelete->setEnabled(true);
            ui->led_ModifyUser_Name->setEnabled(false);
            ui->led_ModifyUser_Password->setEnabled(false);
            ui->led_ModifyUser_PasswordCheck->setEnabled(false);
            ui->cmb_ModifyUser_AccessLevel->setEnabled(false);
            ui->btn_ComfirmUserChange->setEnabled(false);
            ui->btn_UserChangeCancel->setEnabled(false);
            ui->btn_SaveUsersInfo->setEnabled(true);
        }
        else
        {
            ui->tbw_Users->setEnabled(false);
            ui->btn_CreateNewUser->setEnabled(false);
            ui->btn_UserModify->setEnabled(false);
            ui->btn_UserDelete->setEnabled(false);
            ui->led_ModifyUser_Name->setEnabled(true);
            ui->led_ModifyUser_Password->setEnabled(true);
            ui->led_ModifyUser_PasswordCheck->setEnabled(true);
            if((AccessLevel::Level)modifyingUser.accessLevel.value == AccessLevel::Admin)
            {
                ui->cmb_ModifyUser_AccessLevel->setEnabled(false);
            }
            else
            {
                ui->cmb_ModifyUser_AccessLevel->setEnabled(true);
            }
            ui->btn_ComfirmUserChange->setEnabled(true);
            ui->btn_UserChangeCancel->setEnabled(true);
            ui->btn_SaveUsersInfo->setEnabled(false);
        }
    }


    //普通用户无法添加和删除,只能修改自身的密码
    if(user.accessLevel < AccessLevel::Level::Admin)
    {
        ui->btn_CreateNewUser->setEnabled(false);
        ui->btn_UserDelete->setEnabled(false);
        ui->btn_UserModify->setEnabled(false);
        ui->cmb_ModifyUser_AccessLevel->setEnabled(false);
        ui->led_ModifyUser_Name->setEnabled(false);
        if(user.userName == selectedUser.userName.value)
        {
            ui->btn_UserModify->setEnabled(true);
        }
    }
    else
    {
        ui->btn_CreateNewUser->setEnabled(true);
        if(selectedUser.accessLevel.value == AccessLevel::Level::Admin)
        {
            ui->btn_UserDelete->setEnabled(false);
            if(user.accessLevel == AccessLevel::Level::Admin)
            {
                ui->led_ModifyUser_Name->setEnabled(false);
            }
        }
    }

    if(selectedUser.accessLevel.value == AccessLevel::Level::Visitor)
    {
        ui->btn_UserDelete->setEnabled(false);
        ui->btn_UserModify->setEnabled(false);
    }

    if(user.accessLevel == AccessLevel::Level::Visitor)
    {
        ui->btn_ComfirmUserChange->setEnabled(false);
        ui->btn_CreateNewUser->setEnabled(false);
        ui->btn_UserDelete->setEnabled(false);
        ui->btn_UserModify->setEnabled(false);
    }

    ui->led_SelectedUserName->setEnabled(false);
    ui->led_ModifyUser_Name->setToolTip(Tr(""));
    ui->led_ModifyUser_Password->setToolTip(Tr(""));
    ui->led_ModifyUser_PasswordCheck->setToolTip(Tr(""));
    if(ui->led_ModifyUser_Name->isEnabled())
    {
        ui->led_ModifyUser_Name->setToolTip(Tr("10 character lenght limit"));
    }
    if(ui->led_ModifyUser_Password->isEnabled())
    {
        ui->led_ModifyUser_Password->setToolTip(Tr("16 character lenght limit"));
    }
    if(ui->led_ModifyUser_PasswordCheck->isEnabled())
    {
        ui->led_ModifyUser_PasswordCheck->setToolTip(Tr("16 character lenght limit"));
    }

    if(status != ViewStatus::Idle)
    {
        ui->btn_CreateNewUser->setEnabled(false);
        ui->btn_UserDelete->setEnabled(false);
        ui->btn_UserModify->setEnabled(false);
    }
}

void AuthoritySettingView::setUserInfoLimit(SR_UserInfo &info)
{
    info.userName.SetMinLength(0);
    info.userName.SetMaxLength(10);
    info.password.SetMinLength(0);
    info.password.SetMaxLength(16);
}

