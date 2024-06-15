#ifndef RECIPESUBSCRIBER_H
#define RECIPESUBSCRIBER_H

#include "GUIFramework_global.h"
#include "Communication/MQTT/isubscriber.h"
#include "IRecipe/Data/recipeinfo.h"
#include "IRecipe/Command/cmd_recipe.h"

#include <QObject>

class GUIFRAMEWORK_EXPORT RecipeSubscriber : public ISubscriber
{
    Q_OBJECT
public:

    explicit RecipeSubscriber(QString name, QObject *parent = nullptr);
    static RecipeSubscriber *getInstance();

signals:
    void sig_RecipeNames(S_RecipeNames recipeNames);
    void sig_RecipeInfo(S_RecipeInfo &info);
    void sig_RecipeContent(QByteArray &content);
    void sig_Recipe(QByteArray &rcp);
    void sig_OperateResult(CMD_Recipe::Command cmd, bool res);

private slots:
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static RecipeSubscriber *self;
};

#endif // RECIPESUBSCRIBER_H
