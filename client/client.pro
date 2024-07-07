QT += quick network
CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    qqclient.cpp \
    tcpclient.cpp \
    tcpserver.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    qfileutils.h \
    qsettingini.h \
    qqclient.h \
    qsettingini.h \
    tcpclient.h \
    tcpserver.h
