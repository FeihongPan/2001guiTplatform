#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "CommonLib_global.h"

#include <QMap>
#include <QObject>

#define Tr(msg) Language::getInstance()->Translate(msg)

class COMMONLIB_EXPORT Language: public QObject
{
    Q_OBJECT

public:
    enum LanguageType
    {
        English = 0,
        Chinese,
        Japanese,
    };
    Q_ENUM(LanguageType)

public:
    ~Language();

    static Language *getInstance();

    bool Initialize();
    bool Initialize(const QString &folderPath);

    void SetFilePath(const QString &folderPath);

    bool SaveToFile();

    void SetLanguageType(LanguageType type);

    QString Translate(const QString &msg);

    QStringList Translate(const QStringList &msg);

private:
    Language(QObject *parent = nullptr);
    Language(const Language &) = delete;
    Language &operator=(const Language) = delete;

private:
    static Language *self;

    bool m_bInitialized = false;
    QStringList lstLanguage;
    QStringList lstUnTranslated;
    LanguageType languageType = English;
    QString m_FolderPath;

    QMap<QString, QStringList> dicLanguage;
};

#endif // LANGUAGE_H
