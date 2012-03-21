#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T17:02:20
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    hashChangeable.cpp \
    someHashFunction.cpp \
    stringList.cpp

HEADERS += \
    hash.h \
    hashChangeable.h \
    hashFunction.h \
    someHashFunction.h \
    stringList.h
