#ifndef TEMPLATELIBBASICINFORMATION_H
#define TEMPLATELIBBASICINFORMATION_H

#include "GUIFramework_global.h"
#include "ITemplateLib/Data/templateinfo.h"

#include <QDialog>

namespace Ui
{
    class TemplateLibBasicInformation;
}

class GUIFRAMEWORK_EXPORT TemplateLibBasicInformation : public QDialog
{
    Q_OBJECT

public:
    explicit TemplateLibBasicInformation(S_TemplateInfo &tempInfo, bool enable, QWidget *blurWdg, QWidget *parent = nullptr);
    ~TemplateLibBasicInformation();

    virtual void reject() override;

signals:
    void sig_TemplateInfo(S_TemplateInfo &tempInfo);

private:
    void refresh(bool enable);

private:
    Ui::TemplateLibBasicInformation *ui;
    QWidget *p_BlurWdg;
    S_TemplateInfo m_TempInfo;
};

#endif // TEMPLATELIBBASICINFORMATION_H
