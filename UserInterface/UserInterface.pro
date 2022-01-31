QT += core gui multimedia sql

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

TARGET = KMS

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DataReceiver/release/ -lDataReceiver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DataReceiver/debug/ -lDataReceiver
else:unix: LIBS += -L$$OUT_PWD/../DataReceiver/ -lDataReceiver

INCLUDEPATH += $$PWD/../DataReceiver
DEPENDPATH += $$PWD/../DataReceiver

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataReceiver/release/libDataReceiver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataReceiver/debug/libDataReceiver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataReceiver/release/DataReceiver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DataReceiver/debug/DataReceiver.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../DataReceiver/libDataReceiver.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DBAccessProvider/release/ -lDBAccessProvider
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DBAccessProvider/debug/ -lDBAccessProvider
else:unix: LIBS += -L$$OUT_PWD/../DBAccessProvider/ -lDBAccessProvider

INCLUDEPATH += $$PWD/../DBAccessProvider
DEPENDPATH += $$PWD/../DBAccessProvider

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBAccessProvider/release/libDBAccessProvider.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBAccessProvider/debug/libDBAccessProvider.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBAccessProvider/release/DBAccessProvider.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../DBAccessProvider/debug/DBAccessProvider.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../DBAccessProvider/libDBAccessProvider.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../KMSLogic/release/ -lKMSLogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../KMSLogic/debug/ -lKMSLogic
else:unix: LIBS += -L$$OUT_PWD/../KMSLogic/ -lKMSLogic

INCLUDEPATH += $$PWD/../KMSLogic
DEPENDPATH += $$PWD/../KMSLogic

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KMSLogic/release/libKMSLogic.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KMSLogic/debug/libKMSLogic.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KMSLogic/release/KMSLogic.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KMSLogic/debug/KMSLogic.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../KMSLogic/libKMSLogic.a
