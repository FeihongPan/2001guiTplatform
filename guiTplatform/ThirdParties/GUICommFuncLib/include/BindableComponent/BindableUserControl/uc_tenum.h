#ifndef UC_TENUM_H
#define UC_TENUM_H

#include "GUICommFuncLib_global.h"

#include <QWidget>

namespace Ui
{
    class UC_TEnum;
}

class GUICOMMFUNCLIB_EXPORT UC_TEnum : public QWidget
{
    Q_OBJECT

public:
    explicit UC_TEnum(QWidget *parent = nullptr);
    ~UC_TEnum();

    void setName(QString &str);
    void setCurrentIndex(int index);
    void setDatasource(QStringList datasource);
signals:
    void activated(int index);
    void currentIndexChanged(const QString &);
private:
    Ui::UC_TEnum *ui;
};

#endif // UC_TENUM_H
