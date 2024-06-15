QT       += gui
QT       += network xml serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets testlib

TEMPLATE = lib
DEFINES += GUIFRAMEWORK_LIBRARY

CONFIG += c++11

CONFIG(debug,debug|release){
    TARGET = GUIFrameworkd
} else {
    TARGET = GUIFramework
}

CONFIG += skip_target_version_ext
VERSION = 1.0.0
QMAKE_TARGET_PRODUCT = "iStar GUIFramework Library"
QMAKE_TARGET_DESCRIPTION = "Gui Framework Library"

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/Alarms/Alarms.pri)
include($$PWD/IMachineConstant/IMachineConstant.pri)
include($$PWD/IRecipe/IRecipe.pri)
include($$PWD/ITemplateLib/ITemplateLib.pri)
include($$PWD/JsonEditor_MC/JsonEditor_MC.pri)
include($$PWD/SGT/SGT.pri)
include($$PWD/Starter/Starter.pri)
include($$PWD/ThreadProc/ThreadProc.pri)

include($$PWD/../ThirdParties/ThirdParties.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    runtimepara.cpp

HEADERS += \
    GUIFramework_global.h \
    runtimepara.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# CommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../CommonLib/release/ -lCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../CommonLib/debug/ -lCommonLibd
else:unix: LIBS += -L$$OUT_PWD/../CommonLib/ -lCommonLib

INCLUDEPATH += $$PWD/../CommonLib
DEPENDPATH += $$PWD/../CommonLib

# TCommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../TCommonLib/release/ -lTCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../TCommonLib/debug/ -lTCommonLibd
else:unix: LIBS += -L$$OUT_PWD/../TCommonLib/ -lTCommonLib

INCLUDEPATH += $$PWD/../TCommonLib
DEPENDPATH += $$PWD/../TCommonLib

# GUIComponentLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GUIComponentLib/release/ -lGUIComponentLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GUIComponentLib/debug/ -lGUIComponentLibd
else:unix: LIBS += -L$$OUT_PWD/../GUIComponentLib/ -lGUIComponentLib

INCLUDEPATH += $$PWD/../GUIComponentLib
DEPENDPATH += $$PWD/../GUIComponentLib

# GUICommFuncLib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GUICommFuncLib/release/ -lGUICommFuncLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GUICommFuncLib/debug/ -lGUICommFuncLibd
else:unix: LIBS += -L$$OUT_PWD/../GUICommFuncLib/ -lGUICommFuncLib

INCLUDEPATH += $$PWD/../GUICommFuncLib
DEPENDPATH += $$PWD/../GUICommFuncLib
