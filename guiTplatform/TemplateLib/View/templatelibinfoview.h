#ifndef TEMPLATELIBINFOVIEW_H
#define TEMPLATELIBINFOVIEW_H

#include <QWidget>

namespace Ui {
class TemplateLibInfoView;
}

class TemplateLibInfoView : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateLibInfoView(QWidget *parent = nullptr);
    ~TemplateLibInfoView();

private:
    Ui::TemplateLibInfoView *ui;
};

#endif // TEMPLATELIBINFOVIEW_H
