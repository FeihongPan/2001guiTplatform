QT       -= gui
QT       += network xml serialport printsupport

TEMPLATE = lib
DEFINES += COMMONLIB_LIBRARY

CONFIG += c++11

CONFIG(debug,debug|release){
    TARGET = CommonLibd
} else {
    TARGET = CommonLib
}

DEFINES += QS_HAS_JSON
DEFINES += QS_HAS_XML

QMAKE_CXXFLAGS_EXCEPTIONS_ON = /EHa
QMAKE_CXXFLAGS_STL_ON = /EHa

include($$PWD/Serializer/qserializer.pri)
include($$PWD/Encryption/Encryption.pri)
include($$PWD/DeviceRecognize/DeviceRecognize.pri)
include($$PWD/FileSystem/FileSystem.pri)
include($$PWD/Language/Language.pri)
include($$PWD/Converter/Converter.pri)

include($$PWD/../ThirdParties/ThirdParties.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

HEADERS += \
    CommonLib_global.h

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
