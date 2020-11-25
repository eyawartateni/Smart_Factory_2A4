QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agence.cpp \
    connexion.cpp \
    employer.cpp \
    main.cpp \
    mainwindow.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimetext.cpp \
    quotedprintable.cpp \
    smtpclient.cpp

HEADERS += \
    SmtpMime.h \
    agence.h \
    connexion.h \
    employer.h \
    mainwindow.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimetext.h \
    quotedprintable.h \
    smtpclient.h \
    smtpexports.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
