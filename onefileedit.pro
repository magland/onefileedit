QT += core
QT -= gui

TARGET = onefileedit
CONFIG += console
CONFIG -= app_bundle
DESTDIR = bin

LIBS += -lcurses

TEMPLATE = app

SOURCES += \
    onefileeditmain.cpp \
    get_command_line_params.cpp \
    textfile.cpp \
    onefile.cpp

HEADERS += \
    get_command_line_params.h \
    textfile.h \
    onefile.h

