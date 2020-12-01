#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T22:19:03
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = demo1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    demo1.cpp

# Location of SMTP Library

INCLUDEPATH += $$SMTP_LIBRARY_LOCATION
DEPENDPATH += $$SMTP_LIBRARY_LOCATION


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/release/ -lSMTPEmail
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/ -lSMTPEmail
else:unix: LIBS += -L$$PWD/../../../build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/ -lSMTPEmail
LIBS +="C:/Users/Rostom/Desktop/New folder (6)/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/libeay32.dll"
LIBS +=" C:/Users/Rostom/Desktop/New folder (6)/build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/ssleay32.dll"
INCLUDEPATH += $$PWD/../../../build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../../../build-SMTPEmail-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug
