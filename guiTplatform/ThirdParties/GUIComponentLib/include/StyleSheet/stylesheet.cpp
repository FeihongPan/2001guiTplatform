#include "stylesheet.h"
#include <QMutex>
#include <QFontDatabase>
#include <QDebug>
StyleSheet *StyleSheet::self = nullptr;
StyleSheet::StyleSheet(QObject *parent) : QObject(parent)
{
    int fontId = QFontDatabase::addApplicationFont(":/font/icomoon.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    this->font.setFamily(fontFamilies.at(0));
}

StyleSheet *StyleSheet::getInstance()
{
    if(self == nullptr)
    {
        static QMutex mutex;
        QMutexLocker locker(&mutex);
        if(self == nullptr)
        {
            self = new StyleSheet;
        }
    }
    return self;
}

QFont StyleSheet::Font()
{
    return this->font;
}
