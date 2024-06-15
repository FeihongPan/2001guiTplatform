QT       += gui
QT       += network xml serialport printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += GUICOMPONENTLIB_LIBRARY

CONFIG += c++11

DEFINES += QCUSTOMPLOT_COMPILE_LIBRARY
#defined QCUSTOMPLOT_COMPILE_LIBRARY

CONFIG(debug,debug|release){
    TARGET = GUIComponentLibd
} else {
    TARGET = GUIComponentLib
}

CONFIG += skip_target_version_ext
VERSION = 1.0.0
QMAKE_TARGET_PRODUCT = "iStar GUIComponentLib Library"
QMAKE_TARGET_DESCRIPTION = "Gui Basic Function Component"

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/CustomerWidget/CustomerWidget.pri)
include($$PWD/StyleSheet/StyleSheet.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \

HEADERS += \
    GUIComponentLib_global.h \

DISTFILES += \
    Version

RESOURCES += \
    Resources.qrc

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

CONFIG(debug,debug|release){
    DLLDESTDIR = $$OUT_PWD/../MainProject/debug
} else {
    DLLDESTDIR = $$OUT_PWD/../MainProject/release
}

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
