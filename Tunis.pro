QT       += core gui sql
QT       += core gui charts
QT       +=printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agence.cpp \
    connexion.cpp \
    employer.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    agence.h \
    connexion.h \
    employer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/ -lSMTPEmail
else:unix: LIBS += -L$$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/ -lSMTPEmail
LIBS +="C:/Users/Rostom/Desktop/New folder (7)/Tunis/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/libeay32.dll"
LIBS +="C:/Users/Rostom/Desktop/New folder (7)/Tunis/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/ssleay32.dll"
INCLUDEPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug

RESOURCES += \
    image.qrc
