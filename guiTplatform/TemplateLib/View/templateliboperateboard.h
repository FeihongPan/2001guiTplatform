#ifndef TEMPLATELIBOPERATEBOARD_H
#define TEMPLATELIBOPERATEBOARD_H

#include <QWidget>

namespace Ui {
class TemplateLibOperateBoard;
}

class TemplateLibOperateBoard : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateLibOperateBoard(QWidget *parent = nullptr);
    ~TemplateLibOperateBoard();

private:
    Ui::TemplateLibOperateBoard *ui;
};

#endif // TEMPLATELIBOPERATEBOARD_H
