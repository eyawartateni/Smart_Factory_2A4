QT       += core gui sql printsupport
QT       += core gui sql
QT       +=  core gui serialport
 QT += widgets multimedia
QT       += core gui serialport
QT       +=printsupport
QT       += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agence.cpp \
    arduino1.cpp \
    assurance.cpp \
    chaine.cpp \
    client.cpp \
    connexion.cpp \
    employer.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp \
    parking.cpp \
    voiture.cpp

HEADERS += \
    agence.h \
    arduino1.h \
    assurance.h \
    chaine.h \
    client.h \
    connexion.h \
    employer.h \
    fournisseur.h \
    mainwindow.h \
    parking.h \
    voiture.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    image.qrc

