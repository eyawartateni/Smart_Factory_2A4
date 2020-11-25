/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *voiture;
    QLabel *marque;
    QLabel *ref;
    QLabel *modele;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_marque;
    QLineEdit *lineEdit_ref;
    QLineEdit *lineEdit_modele;
    QLineEdit *lineEdit_prix;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_p_op;
    QLineEdit *lineEdit_couleur;
    QLineEdit *lineEdit_option;
    QTableView *tableView;
    QPushButton *ajouter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(995, 456);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        voiture = new QGroupBox(centralwidget);
        voiture->setObjectName(QString::fromUtf8("voiture"));
        voiture->setGeometry(QRect(10, 10, 331, 261));
        marque = new QLabel(voiture);
        marque->setObjectName(QString::fromUtf8("marque"));
        marque->setGeometry(QRect(20, 30, 47, 14));
        ref = new QLabel(voiture);
        ref->setObjectName(QString::fromUtf8("ref"));
        ref->setGeometry(QRect(20, 60, 47, 14));
        modele = new QLabel(voiture);
        modele->setObjectName(QString::fromUtf8("modele"));
        modele->setGeometry(QRect(20, 90, 47, 14));
        label_4 = new QLabel(voiture);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 120, 47, 14));
        label_5 = new QLabel(voiture);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 150, 47, 14));
        label_6 = new QLabel(voiture);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 180, 47, 14));
        label_7 = new QLabel(voiture);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 210, 47, 14));
        label_8 = new QLabel(voiture);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 240, 47, 14));
        lineEdit_marque = new QLineEdit(voiture);
        lineEdit_marque->setObjectName(QString::fromUtf8("lineEdit_marque"));
        lineEdit_marque->setGeometry(QRect(80, 20, 113, 21));
        lineEdit_ref = new QLineEdit(voiture);
        lineEdit_ref->setObjectName(QString::fromUtf8("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(80, 50, 113, 21));
        lineEdit_modele = new QLineEdit(voiture);
        lineEdit_modele->setObjectName(QString::fromUtf8("lineEdit_modele"));
        lineEdit_modele->setGeometry(QRect(80, 80, 113, 21));
        lineEdit_prix = new QLineEdit(voiture);
        lineEdit_prix->setObjectName(QString::fromUtf8("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(80, 110, 113, 21));
        lineEdit_type = new QLineEdit(voiture);
        lineEdit_type->setObjectName(QString::fromUtf8("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(80, 140, 113, 21));
        lineEdit_p_op = new QLineEdit(voiture);
        lineEdit_p_op->setObjectName(QString::fromUtf8("lineEdit_p_op"));
        lineEdit_p_op->setGeometry(QRect(80, 170, 113, 21));
        lineEdit_couleur = new QLineEdit(voiture);
        lineEdit_couleur->setObjectName(QString::fromUtf8("lineEdit_couleur"));
        lineEdit_couleur->setGeometry(QRect(80, 200, 113, 21));
        lineEdit_option = new QLineEdit(voiture);
        lineEdit_option->setObjectName(QString::fromUtf8("lineEdit_option"));
        lineEdit_option->setGeometry(QRect(80, 230, 113, 21));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(370, 60, 256, 192));
        ajouter = new QPushButton(centralwidget);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        ajouter->setGeometry(QRect(470, 20, 80, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 995, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        voiture->setTitle(QCoreApplication::translate("MainWindow", "voiture", nullptr));
        marque->setText(QCoreApplication::translate("MainWindow", "marque", nullptr));
        ref->setText(QCoreApplication::translate("MainWindow", "reference", nullptr));
        modele->setText(QCoreApplication::translate("MainWindow", "modele", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "prix", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "type", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "prix option", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "couleur", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "option", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
