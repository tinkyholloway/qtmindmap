#-------------------------------------------------
#
# Project created by QtCreator 2011-05-24T11:24:26
#
#-------------------------------------------------

QT       += core gui svg xml

CONFIG   += warn_on

TARGET = qtmindmap

TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    graphwidget.cpp \
    node.cpp \
    edge.cpp \
    systemtray.cpp \
    argumentparser.cpp

HEADERS  += mainwindow.h \
    graphwidget.h \
    node.h \
    edge.h \
    systemtray.h \
    argumentparser.h

FORMS    += mainwindow.ui

RESOURCES = qtmindmap.qrc

TRANSLATIONS += qtmindmap_hu.ts \
                qtmindmap_nb_NO.ts

CODECFORTR = UTF-8
