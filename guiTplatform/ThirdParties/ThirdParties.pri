#Mqtt
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqtt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqttd
else:unix: LIBS += -L$$PWD/../ThirdParties/Mqtt/lib/ -lQt5Mqtt

INCLUDEPATH += $$PWD/../ThirdParties/Mqtt/include
DEPENDPATH += $$PWD/../ThirdParties/Mqtt/include

#spdlog
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/spdlog/lib/ -lspdlog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/spdlog/lib/ -lspdlogd

INCLUDEPATH += $$PWD/../ThirdParties/spdlog/include
DEPENDPATH += $$PWD/../ThirdParties/spdlog/include

#libQPdf
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/libQPdf/lib/x64/ -lqpdf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/libQPdf/lib/x64/ -lqpdfd
else:unix: LIBS += -L$$PWD/../ThirdParties/libQPdf/lib/x64/ -lqpdf

INCLUDEPATH += $$PWD/../ThirdParties/libQPdf/include
DEPENDPATH += $$PWD/../ThirdParties/libQPdf/include

#CommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/CommonLib/lib/ -lCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/CommonLib/lib/ -lCommonLibd
else:unix: LIBS += -L$$PWD/../ThirdParties/CommonLib/lib/ -lCommonLib

CONFIG(debug, debug|release) {
    CommonLib_dll.files = $$PWD/CommonLib/lib/CommonLibd.dll
    CommonLib_dll.path = $$OUT_PWD/debug
}else {
    CommonLib_dll.files = $$PWD/CommonLib/lib/CommonLib.dll
    CommonLib_dll.path = $$OUT_PWD/release
}

INCLUDEPATH += $$PWD/CommonLib/include
DEPENDPATH += $$PWD/CommonLib/include

#TCommonLib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/TCommonLib/lib/ -lTCommonLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/TCommonLib/lib/ -lTCommonLibd
else:unix: LIBS += -L$$PWD/../ThirdParties/TCommonLib/lib/ -lTCommonLib

CONFIG(debug, debug|release) {
    TCommonLib_dll.files = $$PWD/TCommonLib/lib/TCommonLibd.dll
    TCommonLib_dll.path = $$OUT_PWD/debug
}else {
    TCommonLib_dll.files = $$PWD/TCommonLib/lib/TCommonLib.dll
    TCommonLib_dll.path = $$OUT_PWD/release
}

INCLUDEPATH += $$PWD/TCommonLib/include
DEPENDPATH += $$PWD/TCommonLib/include

#GUIComponentLib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/GUIComponentLib/lib/ -lGUIComponentLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/GUIComponentLib/lib/ -lGUIComponentLibd
else:unix: LIBS += -L$$PWD/../ThirdParties/GUIComponentLib/lib/ -lGUIComponentLib

CONFIG(debug, debug|release) {
    GUIComponentLib_dll.files = $$PWD/GUIComponentLib/lib/GUIComponentLibd.dll
    GUIComponentLib_dll.path = $$OUT_PWD/debug
}else {
    GUIComponentLib_dll.files = $$PWD/GUIComponentLib/lib/GUIComponentLib.dll
    GUIComponentLib_dll.path = $$OUT_PWD/release
}

INCLUDEPATH += $$PWD/GUIComponentLib/include
DEPENDPATH += $$PWD/GUIComponentLib/include

#GUICommFuncLib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ThirdParties/GUICommFuncLib/lib/ -lGUICommFuncLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ThirdParties/GUICommFuncLib/lib/ -lGUICommFuncLibd
else:unix: LIBS += -L$$PWD/../ThirdParties/GUICommFuncLib/lib/ -lGUICommFuncLib

CONFIG(debug, debug|release) {
    GUICommFuncLib_dll.files = $$PWD/GUICommFuncLib/lib/GUICommFuncLibd.dll
    GUICommFuncLib_dll.path = $$OUT_PWD/debug
}else {
    GUICommFuncLib_dll.files = $$PWD/GUICommFuncLib/lib/GUICommFuncLib.dll
    GUICommFuncLib_dll.path = $$OUT_PWD/release
}

INCLUDEPATH += $$PWD/GUICommFuncLib/include
DEPENDPATH += $$PWD/GUICommFuncLib/include

#GUIFramework
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/GUIFramework/lib/ -lGUIFramework
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/GUIFramework/lib/ -lGUIFrameworkd
else:unix: LIBS += -L$$PWD/GUIFramework/lib/ -lGUIFramework

CONFIG(debug, debug|release) {
    GUIFramework_dll.files = $$PWD/GUIFramework/lib/GUIFrameworkd.dll
    GUIFramework_dll.path = $$OUT_PWD/debug
}else {
    GUIFramework_dll.files = $$PWD/GUIFramework/lib/GUIFramework.dll
    GUIFramework_dll.path = $$OUT_PWD/release
}

INCLUDEPATH += $$PWD/GUIFramework/include
DEPENDPATH += $$PWD/GUIFramework/include

#Copie dll
COPIES += CommonLib_dll       \
          TCommonLib_dll      \
          GUIComponentLib_dll \
          GUICommFuncLib_dll  \
          GUIFramework_dll    \
