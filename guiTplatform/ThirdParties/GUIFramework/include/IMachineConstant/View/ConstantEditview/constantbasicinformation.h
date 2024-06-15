#ifndef CONSTANTBASICINFORMATION_H
#define CONSTANTBASICINFORMATION_H

#include "GUIFramework_global.h"
#include "IMachineConstant/Data/constantinfo.h"

#include <QDialog>

namespace Ui
{
    class ConstantBasicInformation;
}

class GUIFRAMEWORK_EXPORT ConstantBasicInformation : public QDialog
{
    Q_OBJECT

public:
    explicit ConstantBasicInformation(const S_ConstantInfo &constant, bool isAvtive, QWidget *pBlurWgt = nullptr, QWidget *parent = nullptr);
    ~ConstantBasicInformation();
    S_ConstantInfo getResult(void);

private slots:
    void on_btn_Confirm_clicked();
    void reject() override;

private:
    void updateClient(bool isClient);

private:
    Ui::ConstantBasicInformation *ui;
    QWidget *m_pBlurWdg = nullptr;
    S_ConstantInfo m_constantInfo;
    bool m_bIsActive = false;
};

#endif // CONSTANTBASICINFORMATION_H
