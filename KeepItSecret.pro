#-------------------------------------------------
#
# Project created by QtCreator 2015-05-17T20:53:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeepItSecret
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywindow.cpp

HEADERS  += mainwindow.h \
    mywindow.h

FORMS    += mainwindow.ui \
    mywindow.ui

CONFIG += mobility
MOBILITY = 

