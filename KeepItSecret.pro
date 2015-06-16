#-------------------------------------------------
#
# Project created by QtCreator 2015-05-17T20:53:00
#
#-------------------------------------------------

QT       += core gui bluetooth widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KeepItSecret
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    contactswindow.cpp \
    newaccountwindow.cpp \
    newcontactwindow.cpp \
    deviceselectionwindow.cpp \
    discussionwindow.cpp \
    chat.cpp \
    chatclient.cpp \
    chatserver.cpp \
    remoteselector.cpp \
    cryptotools.cpp \
    user.cpp

HEADERS  += \
    mainwindow.h \
    contactswindow.h \
    newaccountwindow.h \
    newcontactwindow.h \
    deviceselectionwindow.h \
    discussionwindow.h \
    chat.h \
    chatclient.h \
    chatserver.h \
    remoteselector.h \
    cryptotools.h \
    user.h

FORMS    += \
    mainwindow.ui \
    contactswindow.ui \
    newaccountwindow.ui \
    newcontactwindow.ui \
    deviceselectionwindow.ui \
    discussionwindow.ui \
    chat.ui \
    remoteselector.ui

CONFIG += mobility
MOBILITY = 

