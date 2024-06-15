QT       -= gui
QT       += network xml serialport printsupport

TEMPLATE = lib
DEFINES += TCOMMONLIB_LIBRARY

CONFIG += c++11

CONFIG(debug,debug|release){
    TARGET = TCommonLibd
} else {
    TARGET = TCommonLib
}

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/Communication/Communication.pri)
include($$PWD/Logger/Logger.pri)
include($$PWD/TimeSynchronization/TimeSynchronization.pri)
include($$PWD/BasicValue/BasicValue.pri)
include($$PWD/NetworkEquipmentMonitor/NetworkEquipmentMonitor.pri)
include($$PWD/KeyVerify/KeyVerify.pri)

include($$PWD/../ThirdParties/ThirdParties.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS += \
    TCommonLib_global.h

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
