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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *production;
    QWidget *tab;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *marque;
    QLabel *matricule;
    QLabel *modele;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_marque;
    QLineEdit *lineEdit_reference;
    QLineEdit *lineEdit_modele;
    QLineEdit *lineEdit_prix;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_p_op;
    QLineEdit *lineEdit_couleur;
    QLineEdit *lineEdit_option;
    QPushButton *ajouter;
    QPushButton *afficher;
    QPushButton *modifier;
    QPushButton *supprimer;
    QWidget *page_2;
    QTableView *tableView;
    QPushButton *retour;
    QPushButton *recherche;
    QPushButton *sup;
    QLineEdit *lineEdit_referencee;
    QWidget *page_3;
    QPushButton *retour_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_maq;
    QLineEdit *lineEdit_refer;
    QLineEdit *lineEdit_mod;
    QLineEdit *lineEdit_p;
    QLineEdit *lineEdit_typ;
    QLineEdit *lineEdit_po;
    QLineEdit *lineEdit_col;
    QLineEdit *lineEdit_ops;
    QComboBox *comboBox;
    QPushButton *modifier_3;
    QPushButton *load_data;
    QWidget *page_4;
    QPushButton *recherche_2;
    QPushButton *retour_3;
    QLineEdit *lineEdit_ref_3;
    QLabel *supp;
    QPushButton *quitter;
    QWidget *tab_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page_5;
    QPushButton *pushButton_ajouter_chaine;
    QPushButton *pushButton_afficher_chaine;
    QPushButton *pushButton_modifier_chaine;
    QPushButton *pushButton_supprimer_chaine;
    QLabel *ref;
    QLabel *nb;
    QLabel *type_p;
    QLineEdit *lineEdit_ref;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_type_p;
    QWidget *page_6;
    QTableView *tableView_2;
    QPushButton *retour_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *page_7;
    QPushButton *modifier_2;
    QLineEdit *lineEdit_ref_2;
    QLabel *mod_2;
    QPushButton *pushButton_retour;
    QWidget *page_8;
    QPushButton *pushButton_rech;
    QPushButton *pushButton_retour_2;
    QLabel *ref_sup;
    QLineEdit *lineEdit_sup;
    QPushButton *quitter_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(995, 456);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        production = new QTabWidget(centralwidget);
        production->setObjectName(QString::fromUtf8("production"));
        production->setGeometry(QRect(160, 10, 681, 421));
        production->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 671, 411));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        marque = new QLabel(page);
        marque->setObjectName(QString::fromUtf8("marque"));
        marque->setGeometry(QRect(40, 80, 81, 31));
        matricule = new QLabel(page);
        matricule->setObjectName(QString::fromUtf8("matricule"));
        matricule->setGeometry(QRect(40, 40, 91, 31));
        modele = new QLabel(page);
        modele->setObjectName(QString::fromUtf8("modele"));
        modele->setGeometry(QRect(40, 120, 91, 31));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 160, 91, 31));
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 200, 171, 31));
        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 240, 101, 31));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 280, 81, 31));
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 320, 81, 31));
        lineEdit_marque = new QLineEdit(page);
        lineEdit_marque->setObjectName(QString::fromUtf8("lineEdit_marque"));
        lineEdit_marque->setGeometry(QRect(210, 80, 141, 31));
        lineEdit_reference = new QLineEdit(page);
        lineEdit_reference->setObjectName(QString::fromUtf8("lineEdit_reference"));
        lineEdit_reference->setGeometry(QRect(210, 40, 141, 31));
        lineEdit_modele = new QLineEdit(page);
        lineEdit_modele->setObjectName(QString::fromUtf8("lineEdit_modele"));
        lineEdit_modele->setGeometry(QRect(210, 120, 141, 31));
        lineEdit_prix = new QLineEdit(page);
        lineEdit_prix->setObjectName(QString::fromUtf8("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(210, 160, 141, 31));
        lineEdit_type = new QLineEdit(page);
        lineEdit_type->setObjectName(QString::fromUtf8("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(210, 200, 141, 31));
        lineEdit_p_op = new QLineEdit(page);
        lineEdit_p_op->setObjectName(QString::fromUtf8("lineEdit_p_op"));
        lineEdit_p_op->setGeometry(QRect(210, 240, 141, 31));
        lineEdit_couleur = new QLineEdit(page);
        lineEdit_couleur->setObjectName(QString::fromUtf8("lineEdit_couleur"));
        lineEdit_couleur->setGeometry(QRect(210, 280, 141, 31));
        lineEdit_option = new QLineEdit(page);
        lineEdit_option->setObjectName(QString::fromUtf8("lineEdit_option"));
        lineEdit_option->setGeometry(QRect(210, 320, 141, 31));
        ajouter = new QPushButton(page);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        ajouter->setGeometry(QRect(440, 120, 121, 41));
        afficher = new QPushButton(page);
        afficher->setObjectName(QString::fromUtf8("afficher"));
        afficher->setGeometry(QRect(440, 170, 121, 41));
        modifier = new QPushButton(page);
        modifier->setObjectName(QString::fromUtf8("modifier"));
        modifier->setGeometry(QRect(440, 220, 121, 41));
        supprimer = new QPushButton(page);
        supprimer->setObjectName(QString::fromUtf8("supprimer"));
        supprimer->setGeometry(QRect(440, 270, 121, 41));
        stackedWidget->addWidget(page);
        ajouter->raise();
        marque->raise();
        matricule->raise();
        modele->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        lineEdit_marque->raise();
        lineEdit_reference->raise();
        lineEdit_modele->raise();
        lineEdit_prix->raise();
        lineEdit_type->raise();
        lineEdit_p_op->raise();
        lineEdit_couleur->raise();
        lineEdit_option->raise();
        afficher->raise();
        modifier->raise();
        supprimer->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 40, 601, 231));
        retour = new QPushButton(page_2);
        retour->setObjectName(QString::fromUtf8("retour"));
        retour->setGeometry(QRect(20, 10, 80, 22));
        recherche = new QPushButton(page_2);
        recherche->setObjectName(QString::fromUtf8("recherche"));
        recherche->setGeometry(QRect(50, 290, 101, 31));
        sup = new QPushButton(page_2);
        sup->setObjectName(QString::fromUtf8("sup"));
        sup->setGeometry(QRect(419, 290, 101, 31));
        lineEdit_referencee = new QLineEdit(page_2);
        lineEdit_referencee->setObjectName(QString::fromUtf8("lineEdit_referencee"));
        lineEdit_referencee->setGeometry(QRect(170, 290, 201, 31));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        retour_2 = new QPushButton(page_3);
        retour_2->setObjectName(QString::fromUtf8("retour_2"));
        retour_2->setGeometry(QRect(20, 10, 80, 22));
        label = new QLabel(page_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 80, 61, 21));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 40, 71, 21));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 110, 71, 21));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(100, 140, 81, 21));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 170, 111, 21));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(100, 200, 71, 21));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 230, 81, 21));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(100, 270, 71, 21));
        lineEdit_maq = new QLineEdit(page_3);
        lineEdit_maq->setObjectName(QString::fromUtf8("lineEdit_maq"));
        lineEdit_maq->setGeometry(QRect(220, 80, 113, 21));
        lineEdit_refer = new QLineEdit(page_3);
        lineEdit_refer->setObjectName(QString::fromUtf8("lineEdit_refer"));
        lineEdit_refer->setGeometry(QRect(210, 40, 113, 21));
        lineEdit_mod = new QLineEdit(page_3);
        lineEdit_mod->setObjectName(QString::fromUtf8("lineEdit_mod"));
        lineEdit_mod->setGeometry(QRect(210, 110, 113, 21));
        lineEdit_p = new QLineEdit(page_3);
        lineEdit_p->setObjectName(QString::fromUtf8("lineEdit_p"));
        lineEdit_p->setGeometry(QRect(210, 140, 113, 21));
        lineEdit_typ = new QLineEdit(page_3);
        lineEdit_typ->setObjectName(QString::fromUtf8("lineEdit_typ"));
        lineEdit_typ->setGeometry(QRect(210, 170, 113, 21));
        lineEdit_po = new QLineEdit(page_3);
        lineEdit_po->setObjectName(QString::fromUtf8("lineEdit_po"));
        lineEdit_po->setGeometry(QRect(230, 200, 113, 21));
        lineEdit_col = new QLineEdit(page_3);
        lineEdit_col->setObjectName(QString::fromUtf8("lineEdit_col"));
        lineEdit_col->setGeometry(QRect(220, 230, 113, 21));
        lineEdit_ops = new QLineEdit(page_3);
        lineEdit_ops->setObjectName(QString::fromUtf8("lineEdit_ops"));
        lineEdit_ops->setGeometry(QRect(220, 260, 113, 21));
        comboBox = new QComboBox(page_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(400, 50, 121, 31));
        modifier_3 = new QPushButton(page_3);
        modifier_3->setObjectName(QString::fromUtf8("modifier_3"));
        modifier_3->setGeometry(QRect(420, 200, 121, 31));
        load_data = new QPushButton(page_3);
        load_data->setObjectName(QString::fromUtf8("load_data"));
        load_data->setGeometry(QRect(420, 130, 121, 31));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        recherche_2 = new QPushButton(page_4);
        recherche_2->setObjectName(QString::fromUtf8("recherche_2"));
        recherche_2->setGeometry(QRect(360, 270, 121, 41));
        retour_3 = new QPushButton(page_4);
        retour_3->setObjectName(QString::fromUtf8("retour_3"));
        retour_3->setGeometry(QRect(20, 20, 80, 22));
        lineEdit_ref_3 = new QLineEdit(page_4);
        lineEdit_ref_3->setObjectName(QString::fromUtf8("lineEdit_ref_3"));
        lineEdit_ref_3->setGeometry(QRect(330, 130, 151, 31));
        supp = new QLabel(page_4);
        supp->setObjectName(QString::fromUtf8("supp"));
        supp->setGeometry(QRect(60, 130, 261, 31));
        stackedWidget->addWidget(page_4);
        quitter = new QPushButton(tab);
        quitter->setObjectName(QString::fromUtf8("quitter"));
        quitter->setGeometry(QRect(570, 350, 91, 31));
        quitter->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        production->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        stackedWidget_2 = new QStackedWidget(tab_2);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(-10, 0, 691, 401));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        pushButton_ajouter_chaine = new QPushButton(page_5);
        pushButton_ajouter_chaine->setObjectName(QString::fromUtf8("pushButton_ajouter_chaine"));
        pushButton_ajouter_chaine->setGeometry(QRect(460, 120, 131, 41));
        pushButton_afficher_chaine = new QPushButton(page_5);
        pushButton_afficher_chaine->setObjectName(QString::fromUtf8("pushButton_afficher_chaine"));
        pushButton_afficher_chaine->setGeometry(QRect(460, 170, 131, 41));
        pushButton_modifier_chaine = new QPushButton(page_5);
        pushButton_modifier_chaine->setObjectName(QString::fromUtf8("pushButton_modifier_chaine"));
        pushButton_modifier_chaine->setGeometry(QRect(460, 220, 131, 41));
        pushButton_supprimer_chaine = new QPushButton(page_5);
        pushButton_supprimer_chaine->setObjectName(QString::fromUtf8("pushButton_supprimer_chaine"));
        pushButton_supprimer_chaine->setGeometry(QRect(460, 270, 131, 41));
        ref = new QLabel(page_5);
        ref->setObjectName(QString::fromUtf8("ref"));
        ref->setGeometry(QRect(50, 49, 101, 31));
        nb = new QLabel(page_5);
        nb->setObjectName(QString::fromUtf8("nb"));
        nb->setGeometry(QRect(50, 110, 201, 31));
        nb->setStyleSheet(QString::fromUtf8(""));
        type_p = new QLabel(page_5);
        type_p->setObjectName(QString::fromUtf8("type_p"));
        type_p->setGeometry(QRect(50, 170, 161, 31));
        lineEdit_ref = new QLineEdit(page_5);
        lineEdit_ref->setObjectName(QString::fromUtf8("lineEdit_ref"));
        lineEdit_ref->setGeometry(QRect(260, 50, 141, 31));
        spinBox = new QSpinBox(page_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(260, 110, 111, 31));
        lineEdit_type_p = new QLineEdit(page_5);
        lineEdit_type_p->setObjectName(QString::fromUtf8("lineEdit_type_p"));
        lineEdit_type_p->setGeometry(QRect(260, 170, 141, 31));
        stackedWidget_2->addWidget(page_5);
        nb->raise();
        pushButton_ajouter_chaine->raise();
        pushButton_afficher_chaine->raise();
        pushButton_modifier_chaine->raise();
        pushButton_supprimer_chaine->raise();
        ref->raise();
        type_p->raise();
        lineEdit_ref->raise();
        spinBox->raise();
        lineEdit_type_p->raise();
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tableView_2 = new QTableView(page_6);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(50, 70, 441, 251));
        retour_4 = new QPushButton(page_6);
        retour_4->setObjectName(QString::fromUtf8("retour_4"));
        retour_4->setGeometry(QRect(30, 10, 80, 22));
        pushButton = new QPushButton(page_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 180, 121, 31));
        pushButton_3 = new QPushButton(page_6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 220, 121, 31));
        pushButton_4 = new QPushButton(page_6);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 260, 161, 31));
        stackedWidget_2->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        modifier_2 = new QPushButton(page_7);
        modifier_2->setObjectName(QString::fromUtf8("modifier_2"));
        modifier_2->setGeometry(QRect(370, 270, 121, 41));
        lineEdit_ref_2 = new QLineEdit(page_7);
        lineEdit_ref_2->setObjectName(QString::fromUtf8("lineEdit_ref_2"));
        lineEdit_ref_2->setGeometry(QRect(300, 110, 141, 31));
        mod_2 = new QLabel(page_7);
        mod_2->setObjectName(QString::fromUtf8("mod_2"));
        mod_2->setGeometry(QRect(40, 110, 251, 31));
        pushButton_retour = new QPushButton(page_7);
        pushButton_retour->setObjectName(QString::fromUtf8("pushButton_retour"));
        pushButton_retour->setGeometry(QRect(30, 20, 80, 22));
        stackedWidget_2->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        pushButton_rech = new QPushButton(page_8);
        pushButton_rech->setObjectName(QString::fromUtf8("pushButton_rech"));
        pushButton_rech->setGeometry(QRect(390, 260, 121, 41));
        pushButton_retour_2 = new QPushButton(page_8);
        pushButton_retour_2->setObjectName(QString::fromUtf8("pushButton_retour_2"));
        pushButton_retour_2->setGeometry(QRect(20, 10, 80, 22));
        ref_sup = new QLabel(page_8);
        ref_sup->setObjectName(QString::fromUtf8("ref_sup"));
        ref_sup->setGeometry(QRect(40, 120, 261, 31));
        lineEdit_sup = new QLineEdit(page_8);
        lineEdit_sup->setObjectName(QString::fromUtf8("lineEdit_sup"));
        lineEdit_sup->setGeometry(QRect(310, 120, 151, 31));
        stackedWidget_2->addWidget(page_8);
        quitter_2 = new QPushButton(tab_2);
        quitter_2->setObjectName(QString::fromUtf8("quitter_2"));
        quitter_2->setGeometry(QRect(560, 351, 91, 31));
        quitter_2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/1.jpg);"));
        production->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 995, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        production->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        marque->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/new/prefix1/9.jpg\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        marque->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">marque</span></p></body></html>", nullptr));
        matricule->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">reference</span></p></body></html>", nullptr));
        modele->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">modele</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">prix</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">type de carburant</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">prix option</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">couleur</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">option</span></p></body></html>", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        retour->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        recherche->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        sup->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        retour_2->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Marque", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Modele", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "type de carburant", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Prix option", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Couleur", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "options", nullptr));
        modifier_3->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        load_data->setText(QCoreApplication::translate("MainWindow", "Afficher les donnee", nullptr));
        recherche_2->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        retour_3->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">donner la reference a supprimer</span></p></body></html>", nullptr));
        quitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        production->setTabText(production->indexOf(tab), QCoreApplication::translate("MainWindow", "gestion des voitures", nullptr));
        pushButton_ajouter_chaine->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_afficher_chaine->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        pushButton_modifier_chaine->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_supprimer_chaine->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        ref->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Reference</span></p></body></html>", nullptr));
        nb->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Nombre de machine</span></p></body></html>", nullptr));
        type_p->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:9pt; font-weight:600;\">Type de produit</span></p></body></html>", nullptr));
        retour_4->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "imprimer ", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Afficher statistique", nullptr));
        modifier_2->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        mod_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">donner la reference a modifier</span></p></body></html>", nullptr));
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        pushButton_rech->setText(QCoreApplication::translate("MainWindow", "Rechcher", nullptr));
        pushButton_retour_2->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        ref_sup->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">donner la reference a supprimer</span></p></body></html>", nullptr));
        quitter_2->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        production->setTabText(production->indexOf(tab_2), QCoreApplication::translate("MainWindow", "gestion des chaines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
