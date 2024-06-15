#ifndef JSONEDITOR_MC_H
#define JSONEDITOR_MC_H

#include "GUIFramework_global.h"
#include "JsonTreeModel_mc.h"

#include <QWidget>

namespace Ui
{
    class JsonEditor_MC;
}

class GUIFRAMEWORK_EXPORT JsonEditor_MC : public QWidget
{
    Q_OBJECT

public:
    explicit JsonEditor_MC(QWidget *parent = nullptr);
    ~JsonEditor_MC();

    void expandAll();
    void loadJson(QByteArray &data);    ///载入Json
    void dumpJson(QByteArray &data);    ///导出Json数据
    void setReadOnly(bool readOnly);    ///设置只读

private:
    //    void initLoadDump();
    //    void initEdit();
    void updateIndex();

private:
    Ui::JsonEditor_MC *ui;
    JsonTreeModel_MC *jsonModel;
};

#endif // JSONEDITOR_MC_H
