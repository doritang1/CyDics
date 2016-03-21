#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T17:14:10
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CyDics
TEMPLATE = app


SOURCES += main.cpp\
        cydicmain.cpp \
    ckdbengine.cpp \
    itembody.cpp \
    itemTitle.cpp

HEADERS  += cydicmain.h \
    ckdbengine.h \
    itembody.h \
    itemTitle.h

FORMS    += cydicmain.ui

DISTFILES += \
    debug/QtinyMCE/tinymce4_base.html
