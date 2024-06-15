QT       += core gui
QT       += network xml serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = guiTplatform

CONFIG -= app_bundle

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/NaviForm/NaviForm.pri)
include($$PWD/Recipe/Recipe.pri)
include($$PWD/TemplateLib/TemplateLib.pri)
include($$PWD/ThirdParties/ThirdParties.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    startmanager.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    startmanager.h
