#-------------------------------------------------
#
# Project created by QtCreator 2018-09-17T12:19:09
#
#-------------------------------------------------

QT       += core gui widgets multimedia

TARGET = buttons
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
    src/mainwindow.cpp \
    src/Character.cpp \
    src/Command.cpp \
    src/CommandWords.cpp \
    src/graphicsview.cpp \
    src/inventory.cpp \
    src/item.cpp \
    src/main.cpp \
    src/Parser.cpp \
    src/person.cpp \
    src/player.cpp \
    src/Room.cpp \
    src/sprite.cpp \
    src/ZorkUL.cpp \
    src/zork.cpp \
    src/config.cpp \
    src/startmenu.cpp \
    src/gamemenu.cpp \
    src/menu.cpp \
    src/Character.cpp \
    src/Command.cpp \
    src/CommandWords.cpp \
    src/config.cpp \
    src/graphicsview.cpp \
    src/inventory.cpp \
    src/item.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/Parser.cpp \
    src/person.cpp \
    src/player.cpp \
    src/Room.cpp \
    src/sprite.cpp \
    src/zork.cpp \
    src/ZorkUL.cpp

HEADERS += \
    src/mainwindow.h \
    src/Character.h \
    src/Command.h \
    src/CommandWords.h \
    src/graphicsview.h \
    src/inventory.h \
    src/item.h \
    src/Parser.h \
    src/person.h \
    src/player.h \
    src/Room.h \
    src/sprite.h \
    src/ZorkUL.h \
    src/zork.h \
    src/config.h \
    src/startmenu.h \
    src/gamemenu.h \
    src/menu.h \
    src/Character.h \
    src/Command.h \
    src/CommandWords.h \
    src/config.h \
    src/graphicsview.h \
    src/inventory.h \
    src/item.h \
    src/mainwindow.h \
    src/Parser.h \
    src/person.h \
    src/player.h \
    src/Room.h \
    src/sprite.h \
    src/zork.h \
    src/ZorkUL.h \
    src/ipushcallback.h \
    src/direction.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
