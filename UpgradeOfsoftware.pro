#-------------------------------------------------
#
# Project created by QtCreator 2021-12-01T15:42:53
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UpgradeOfsoftware
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qttelnet.cpp

HEADERS  += widget.h \
    qttelnet.h

FORMS    += widget.ui

LIBS += -lwsock32


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
