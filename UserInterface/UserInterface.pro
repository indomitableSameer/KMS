QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += ../DataReceiver ../DBAccessProvider/ ../KMSLogic/
LIBS += -L../DataReceiver/debug -ldatareceiver -L../DBAccessProvider/debug -ldbAccessprovider -L../KMSLogic/debug -lkmslogic

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    kms.cpp

HEADERS += \
    kms.h

FORMS += \
    kms.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
