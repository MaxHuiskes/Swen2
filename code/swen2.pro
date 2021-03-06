QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/QUILift.cpp \
    source/ibelt.cpp \
    source/quibelt.cpp \
    source/quibelt.cpp \
    source/cbelt.cpp \
    source/quibelt.cpp \
    source/cblock.cpp \
    source/clift.cpp \
    source/cmotor.cpp \
    source/cpushrot.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/sensor.cpp

HEADERS += \
    headers/QUILift.h \
    headers/cbelt.h \
    headers/cblock.h \
    headers/clift.h \
    headers/cmotor.h \
    headers/cpushrot.h \
    headers/ibelt.h \
    headers/mainwindow.h \
    headers/quibelt.h \
    headers/sensor.h

FORMS += \
    ui/mainwindow.ui


INCLUDEPATH += $$PWD/headers/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
