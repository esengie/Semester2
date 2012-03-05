#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T22:21:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    consolePrinter.cpp \
    filePrinter.cpp \
    reader.cpp \
    printer.cpp

HEADERS += \
    printer.h \
    filePrinter.h \
    consolePrinter.h \
    reader.h
