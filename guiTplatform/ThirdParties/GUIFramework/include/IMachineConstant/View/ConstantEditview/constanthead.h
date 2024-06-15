#ifndef CONSTANTHEAD_H
#define CONSTANTHEAD_H

#include "GUIFramework_global.h"
//#include "AuthorityComponent/authoritywidget.h"
#include "IMachineConstant/Command/cmd_machineconstant.h"
#include "IMachineConstant/Data/constantinfo.h"

#include <QWidget>

namespace Ui
{
    class ConstantHead;
}

class GUIFRAMEWORK_EXPORT ConstantHead : public QWidget
{
    Q_OBJECT

public:
    explicit ConstantHead(QWidget *parent = nullptr);
    ~ConstantHead();

    void setConstantInfo(const S_ConstantInfo &constantInfo);
    S_ConstantInfo getContantInfo(void);
    void setReadOnly(bool readOnly);
    void clean(void);
    void setBtnEnable(bool enable);

signals:
    void sig_sendConstantInfo(S_ConstantInfo conInfo);

private slots:
    void on_btn_basicInfo_clicked();

private:
    Ui::ConstantHead *ui;
    S_ConstantInfo m_constantInfo;
};

#endif // CONSTANTHEAD_H
