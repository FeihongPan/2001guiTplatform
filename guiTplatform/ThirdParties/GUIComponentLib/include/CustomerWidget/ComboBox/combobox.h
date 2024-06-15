#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "GUIComponentLib_global.h"

#include <QComboBox>
#include <QObject>

class GUICOMPONENTLIB_EXPORT ComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = nullptr);
};

#endif // COMBOBOX_H
