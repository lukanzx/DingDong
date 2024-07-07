QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    qqserver.cpp \
    sqlaccountmodel.cpp \
    sqlfriendmodel.cpp \
    sqlgroupmodel.cpp \
    tcpclient.cpp \
    tcpserver.cpp

HEADERS += \
    ../../Tcp-Version/QQServer/onlinelist.h \
    qqserver.h \
    sqlaccountmodel.h \
    sqlfriendmodel.h \
    sqlgroupmodel.h \
    tcpclient.h \
    tcpserver.h

FORMS += \
    qqserver.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
