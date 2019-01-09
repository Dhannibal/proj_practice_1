#-------------------------------------------------
#
# Project created by QtCreator 2018-11-29T13:38:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bankmanager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    check.cpp \
    master.cpp \
    atm.cpp \
    transmoney.cpp \
    save.cpp \
    drawmoney.cpp \
    deletacount.cpp \
    newaccount.cpp \
    getcardnum.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    check.h \
    master.h \
    atm.h \
    transmoney.h \
    save.h \
    drawmoney.h \
    deletacount.h \
    newaccount.h \
    getcardnum.h

FORMS += \
        mainwindow.ui \
    login.ui \
    check.ui \
    master.ui \
    atm.ui \
    transmoney.ui \
    save.ui \
    drawmoney.ui \
    deletacount.ui \
    newaccount.ui \
    getcardnum.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
QT +=  sql

DISTFILES +=
