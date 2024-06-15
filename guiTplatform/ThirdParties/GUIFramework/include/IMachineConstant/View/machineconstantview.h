#ifndef MACHINECONSTANTVIEW_H
#define MACHINECONSTANTVIEW_H

#include "GUIFramework_global.h"
#include "AuthorityComponent/authoritywidget.h"
#include "IMachineConstant/View/ConstantEditview/mceditorview.h"
#include "constantmodel.h"
#include "IMachineConstant/Data/machineconstant.h"
#include "BasicValue/serializablelist.h"

#include <QWidget>

namespace Ui
{
    class MachineConstantView;
}

class GUIFRAMEWORK_EXPORT MachineConstantView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit MachineConstantView(QString name, QWidget *parent = nullptr);
    ~MachineConstantView();

    S_MachineConstant CreateMachineConstant(QStringList constantNames);
    void cleanViewer(void);
    void setReadOnly(bool readOnly);

public slots:
    virtual void ConstructFinished() override;

public slots:
    void slot_sendConstantInfo(S_ConstantInfo conInfo);

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;

    void userModelInitialize();
    void setEditorStatus();
    bool isActiveConstant();



private:
    Ui::MachineConstantView *ui;
    McEditorView *m_pEditView;
    ConstantModel *m_pConstantModel;
    S_List_String m_constantNames;
    S_ConstantInfo m_currentConstant;
    SR_ConstantInfo m_keepConstantInfo;
    SR_MachineConstant m_constant;
    SR_MachineConstant m_emptyConstant;
    TString m_selectedConstantName;
    int m_selectedIndex = 0;
    bool m_bIsModify = false;
};

#endif // MACHINECONSTANTVIEW_H
