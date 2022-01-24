QT -= gui

TEMPLATE = lib
CONFIG += staticlib
INCLUDEPATH += ../DataReceiver ../DBAccessProvider/
LIBS += L../DataReceiver/debug -ldatareceiver -L../DBAccessProvider/debug -ldbAccessprovider
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UIDataResponse.cpp \
    alarmlogic.cpp \
    kmslogic.cpp

HEADERS += \
    UIDataResponse.h \
    UIdata.h \
    alarmlogic.h \
    kmslogic.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
