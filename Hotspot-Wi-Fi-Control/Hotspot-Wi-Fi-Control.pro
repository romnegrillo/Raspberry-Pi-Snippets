#-------------------------------------------------
#
# Project created by QtCreator 2020-10-23T10:07:27
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hotspot-Wi-Fi-Control
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


SOURCES += \
    enter_wifi_password.cpp \
        main.cpp \
        mainwindow.cpp \
    confirm_switch_network.cpp

HEADERS += \
    enter_wifi_password.h \
        mainwindow.h \
    confirm_switch_network.h

FORMS += \
    enter_wifi_password.ui \
        mainwindow.ui \
    confirm_switch_network.ui
