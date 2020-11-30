QT       += core gui sql
QT  +=core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../Qt-Table-Printer-master/tableprinter.cpp \
    authentification.cpp \
    client.cpp \
    connection.cpp \
    dialog.cpp \
    dialog_fournisseur.cpp \
    fournisseur.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../Qt-Table-Printer-master/tableprinter.h \
    authentification.h \
    client.h \
    connection.h \
    dialog.h \
    dialog_fournisseur.h \
    fournisseur.h \
    mainwindow.h

FORMS += \
    authentification.ui \
    dialog.ui \
    dialog_fournisseur.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    sound.qrc
