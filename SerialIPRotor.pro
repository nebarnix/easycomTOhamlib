#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T19:35:21
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialIPRotor
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        plot.cpp

HEADERS  += mainwindow.h \
    plot.h

FORMS    += mainwindow.ui

include(C:/qwt-6.1.3/features/qwt.prf)
include(c:/qwtpolar-1.1.1/features/qwtpolar.prf)
