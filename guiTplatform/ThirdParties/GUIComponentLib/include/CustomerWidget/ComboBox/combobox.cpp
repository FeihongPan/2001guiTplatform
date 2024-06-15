#include "combobox.h"
#include "StyleSheet/stylesheet.h"
#include <QListView>
ComboBox::ComboBox(QWidget *parent) : QComboBox(parent)
{
    this->setView(new QListView());
    this->setStyleSheet(GlobalStyleSheet->ComboBox);
}
