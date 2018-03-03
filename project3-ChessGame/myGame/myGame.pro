#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T10:59:35
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp \
    Array.cpp \
    Object.cpp \
    Value.cpp

HEADERS  += mainwindow.h \
    mywidget.h \
    mywidget.h \
    Array.h \
    Object.h \
    Value.h

FORMS    += \
    mainwindow.ui
