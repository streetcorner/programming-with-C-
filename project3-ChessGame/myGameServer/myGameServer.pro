#-------------------------------------------------
#
# Project created by QtCreator 2017-06-10T17:22:54
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myGameServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userinfo.cpp \
    Array.cpp \
    Object.cpp \
    Value.cpp

HEADERS  += mainwindow.h \
    userinfo.h \
    gameboard.h \
    Array.h \
    Object.h \
    Value.h

FORMS    += mainwindow.ui
