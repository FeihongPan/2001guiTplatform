#ifndef RECIPEEDITVIEW_H
#define RECIPEEDITVIEW_H

#include "itemdelegate.h"
#include "AuthorityComponent/authoritywidget.h"
#include "Recipe/Data/recipe.h"

#include <QWidget>
#include <QTableWidget>

namespace Ui
{
    class RecipeEditView;
}

class RecipeEditView : public AuthorityWidget
{
    Q_OBJECT

public:
    explicit RecipeEditView(QString name, QWidget *parent = nullptr);
    ~RecipeEditView();

    void SetRecipe(S_Recipe &recipe);
    void SetRecipe(QByteArray &recipe);
    void setEditorStatus(bool status);
    void expandAll();
    void dumpJson(QByteArray &data);
    void loadUi();
    void dumpUi();

    S_Recipe recipe;

public slots:
    virtual void ConstructFinished() override;

signals:

private slots:
    void typeComboBoxUpCurrentTextChanged(const QString &arg1);
    //    void typeComboBoxDownCurrentTextChanged(const QString &arg1);

    void pointTabWidget_add(QTableWidget *widget);
    void pointTabWidget_delete(QTableWidget *widget);
    void pointTabWidget_up(QTableWidget *widget);
    void pointTabWidget_down(QTableWidget *widget);

    //    void bondingTabWidget_add(QTableWidget *widget);
    //    void bondingTabWidget_delete(QTableWidget *widget);
    //    void bondingTabWidget_up(QTableWidget *widget);
    //    void bondingTabWidget_down(QTableWidget *widget);



    //    void on_checkBox_stateChanged(int arg1);

    //    void on_bondig_modify_pushbutton_2_clicked();

    //    void on_Bonding_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

    //    void on_Bonding_tableWidget_itemClicked(QTableWidgetItem *item);

    //    void on_Bonding_tableWidget_itemSelectionChanged();

private:
    virtual void setWidgets() override;
    virtual void setWidgetStyleSheet() override;
    virtual void setLanguageKeys() override;
    virtual void setConnections() override;


private:
    Ui::RecipeEditView *ui;
    QString selectCmd;
    QTableWidgetItem *item{nullptr};
    QStringList m_lst_TemplateLibNames;
};

#endif // RECIPEEDITVIEW_H
