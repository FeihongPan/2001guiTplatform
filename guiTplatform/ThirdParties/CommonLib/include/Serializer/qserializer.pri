contains(DEFINES, QS_HAS_XML) {
    QT += xml
}

HEADERS += \
#        $$PWD/serializeroperator.h \
        $$PWD/src/qserializer.h

INCLUDEPATH += $$PWD/

DISTFILES += \
        $$PWD/QSerializer

CONFIG += QSERIALIZER_INCLUDED
DEFINES += QSERIALIZER_INCLUDED

SOURCES +=
 #    $$PWD/serializeroperator.cpp
