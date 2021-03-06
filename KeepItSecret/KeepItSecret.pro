#-------------------------------------------------
#
# Project created by QtCreator 2015-05-17T20:53:00
#
#-------------------------------------------------

QT       += core gui widgets sql network

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = KeepItSecret
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    contactswindow.cpp \
    newaccountwindow.cpp \
    newcontactwindow.cpp \
    client.cpp \
    options.cpp \
    chatdialog.cpp \
    qblowfish.cpp \
    cryptoutils.cpp

HEADERS  += \
    mainwindow.h \
    contactswindow.h \
    newaccountwindow.h \
    newcontactwindow.h \
    client.h \
    options.h \
    chatdialog.h \
    qblowfish.h \
    qblowfish_p.h \
    cryptoutils.h

FORMS    += \
    mainwindow.ui \
    contactswindow.ui \
    newaccountwindow.ui \
    newcontactwindow.ui \
    chatdialog.ui

CONFIG += mobility \
       += c++11

MOBILITY =

RESOURCES += \
    res.qrc

