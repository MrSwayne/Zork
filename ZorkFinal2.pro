#-------------------------------------------------
#
# Project created by QtCreator 2018-11-22T11:12:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT       += core gui widgets multimedia

TARGET = ZorkFinal2
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
    menu.cpp \
    startmenu.cpp \
    gamemenu.cpp \
    zork.cpp \
    model.cpp \
    character.cpp \
    controller.cpp \
    enemy.cpp \
    gamemenu.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    model.cpp \
    player.cpp \
    room.cpp \
    startmenu.cpp \
    view.cpp \
    zork.cpp \
    config.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    ipushcallback.h \
    startmenu.h \
    gamemenu.h \
    zork.h \
    model.h \
    character.h \
    config.h \
    controller.h \
    enemy.h \
    gamemenu.h \
    ipushcallback.h \
    item.h \
    logger.h \
    mainwindow.h \
    menu.h \
    model.h \
    player.h \
    room.h \
    startmenu.h \
    view.h \
    zork.h

FORMS += \
        mainwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ZorkFinal2.pro

DISTFILES += \
    ZorkFinal2.pro.user

RESOURCES += \
    rsc.qrc
