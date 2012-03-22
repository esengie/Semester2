#-------------------------------------------------
#
# Project created by QtCreator 2012-03-02T17:50:18
#
#-------------------------------------------------

QT       += core\
            testlib

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sort.cpp \
    bubbleSort.cpp \
    quickSort.cpp \
    shitSort.cpp

HEADERS += \
    sort.h \
    bubbleSort.h \
    quickSort.h \
    shitSort.h \
    sortTest.h
