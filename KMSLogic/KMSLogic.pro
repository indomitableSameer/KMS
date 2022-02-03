QT -= gui
QT += multimedia
QT += sql

TEMPLATE = lib
CONFIG += staticlib
INCLUDEPATH += ../DataReceiver ../DBAccessProvider/
#LIBS += L../DataReceiver/debug -ldatareceiver -L../DBAccessProvider/debug -ldbAccessprovider
#LIBS +=
CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AlarmLogic.cpp \
    AlarmManager.cpp \
    AlarmPredictionLogic.cpp \
    AlarmSoundManager.cpp \
    IUiData.cpp \
    IUiQueryEngine.cpp \
    KmsLogic.cpp \
    NotificationGenerator.cpp

HEADERS += \
    AlarmLogic.h \
    AlarmManager.h \
    AlarmPredictionLogic.h \
    AlarmSoundManager.h \
    IAlarmType.h \
    IUiData.h \
    IUiQueryEngine.h \
    IUnprocessedData.h \
    KmsLogic.h \
    NotificationGenerator.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    alarm_red.wav
