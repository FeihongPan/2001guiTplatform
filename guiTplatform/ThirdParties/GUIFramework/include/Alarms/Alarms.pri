FORMS += \
    $$PWD/Views/alarmeditview.ui \
    $$PWD/Views/historyalarmview.ui \
    $$PWD/Views/reportalarmview.ui

HEADERS += \
    $$PWD/Command/cmd_alarm.h \
    $$PWD/Data/alarmsinfo.h \
    $$PWD/Subscriber/alarmSubscriber.h \
    $$PWD/Views/alarmeditmodel.h \
    $$PWD/Views/alarmeditview.h \
    $$PWD/Views/historyalarmsmodel.h \
    $$PWD/Views/historyalarmview.h \
    $$PWD/Views/reportalarmview.h \
    $$PWD/Views/reportedalarmsmodel.h

SOURCES += \
    $$PWD/Command/cmd_alarm.cpp \
    $$PWD/Data/alarmsinfo.cpp \
    $$PWD/Subscriber/alarmSubscriber.cpp \
    $$PWD/Views/alarmeditmodel.cpp \
    $$PWD/Views/alarmeditview.cpp \
    $$PWD/Views/historyalarmsmodel.cpp \
    $$PWD/Views/historyalarmview.cpp \
    $$PWD/Views/reportalarmview.cpp \
    $$PWD/Views/reportedalarmsmodel.cpp
