#ifndef MAINWINDOW_H
#define MAINWINDOW_
#include<QLabel>
#include"QMessageBox"
#include"QSqlQuery"
#include"employer.h"
#include "agence.h"
#include"voiture.h"
#include"chaine.h"
#include "parking.h"
#include "assurance.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include<QTextDocument>
#include<QFileDialog>
#include<QtCharts>
#include<QMessageBox>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QSound>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDialog>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include "fournisseur.h"
#include "client.h"
#include <QSound>
#include <QSqlTableModel>
//#include "C:/Users/Mayssa/Desktop/Qt-Table-Printer-master/Qt-Table-Printer-master/tableprinter.h"
//#include "C:/Users/Rostom/Desktop/New folder (2)/Smart_factory_2A4/SmtpClient-for-Qt-1.1/src/SmtpMime"
//#include "C:/Users/eyaou/Desktop/Qt-Table-Printer-master/tableprinter.h"
//#include "C:/Users/eyaou/Desktop/Smart_Factory_2A4-master/Smart_factory_2A4/Qt-Table-Printer-master/tableprinter.h"
#include <QMainWindow>
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QLabel *processLabel ;
 QGraphicsScene scene;
 ///eya
 QSqlRelationalTableModel *modClient;
 QSortFilterProxyModel * proxyclient;
 QSqlRelationalTableModel *modFournisseur;
 QSortFilterProxyModel * proxyfournisseur;

private slots:
    void on_btn_login_clicked();

    void on_ajouterFour_clicked();

    void on_afficherfour_clicked();

    void on_trier_clicked();

    void on_quitter_clicked();

    void on_adm_tab_aff_activated(const QModelIndex &index);

    void on_modifier_emp_clicked();

    void on_ajouter_agence_clicked();

    void on_afficher_agence_clicked();

    void on_supprimer_agence_clicked();

    void on_ag_tab_aff_activated(const QModelIndex &index);

    void on_modifier_agence_clicked();

    void on_imprimer_clicked();

    void on_btn_exporter_clicked();

    void on_btn_statistique_clicked();

   // void on_btn_em_rec_clicked();
    
    void on_reclamation_clicked();

    void on_btn_resource_clicked();

    void on_pushButton_3_clicked();

    void on_btn_existe_clicked();

    void on_btn_existe_2_clicked();

    void on_btn_retour_em_clicked();

    void on_btn_retour_clicked();

    void on_btn_existe_3_clicked();

    void on_btn_Production_clicked();

    void on_btn_existe_4_clicked();

    void on_ajouter_voi_clicked();

    void on_afficher_voi_clicked();

    void on_ajouter_ch_clicked();

    void on_comboBox_ch_currentIndexChanged();

    void on_afficher_ch_clicked();

    void on_modifier_ch_clicked();

    void on_supp_ch_clicked();

    void on_trier_2_clicked();

    void on_modifier_voi_clicked();

    void on_supprimer_voi_clicked();

    void on_rechercher_voi_clicked();

    void on_tableView_chaine_activated(const QModelIndex &index);

    void on_tableView_voiture_activated(const QModelIndex &index);

   void on_pdf_clicked();

    void on_stat_clicked();

    void on_btn_existe_5_clicked();

    void on_btn_echange_clicked();

    void on_aff_four_clicked();

    void on_ajout_four_clicked();

    void on_trier_four_clicked();

    void on_chercher_four_clicked();

    void on_modif_four_clicked();

    void on_supp_four_clicked();

    void on_ajouter_client_clicked();

    void on_aff_client_clicked();

    void on_cher_client_clicked();

    void on_mod_client_clicked();

    void on_supp_client_clicked();

    void on_tabclient_2_activated(const QModelIndex &index);

    void on_tabfour_2_activated(const QModelIndex &index);

    void on_btn_existe_6_clicked();

    void on_btn_service_clicked();

    void on_btn_existe_7_clicked();

    void on_btn_existe_8_clicked();

    void on_ajouter_assu_clicked();

    void on_mod_assu_clicked();

    void on_export_pdf_clicked();

    void on_recherche_clicked();

    void on_afficher_tab_assu_clicked();

    void on_park_ajout_2_clicked();

    void on_mod_park_2_clicked();



    void on_afficher_tab_park_2_clicked();

    void on_supp_park_2_clicked();

    void on_supprimer_clicked();

    void on_tableView_assurance_activated(const QModelIndex &index);

    void on_tableView_parking_2_activated(const QModelIndex &index);

    void on_trier_parking_clicked();

    void on_pdf_client_clicked();

    void on_imprimer_assu_clicked();

    void on_btn_existe_9_clicked();


    void on_arreter_clicked();

    void on_stat_2_clicked();

    void on_btn_pointage_clicked();

    void on_excel_clicked();

    void on_NomFournisseur_4_textChanged(const QString &arg1);

    void on_imp_clicked();

    void on_tutoriel_clicked();

    void on_tutoriel_2_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_Tutorial_clicked();

    void on_ajouter_assu_2_clicked();

    void on_afficher_tab_assu_2_clicked();

    void on_mod_assu_2_clicked();

    void on_supprimer_2_clicked();

    void on_export_pdf_2_clicked();

    void on_recherche_2_clicked();

    void on_park_ajout_3_clicked();

    void on_afficher_tab_park_3_clicked();

    void on_mod_park_3_clicked();

    void on_supp_park_3_clicked();

    void on_trier_parking_2_clicked();

    void on_tableView_parking_3_activated(const QModelIndex &index);

    void on_tableView_assurance_2_activated(const QModelIndex &index);

    void on_btn_existe_10_clicked();

    void on_btn_existe_123_clicked();

    void on_Tutorial_2_clicked();

    void on_Tutorial_55_clicked();

private:
    Ui::MainWindow *ui;
    voiture vtmp;
    chaine ctmp;
    QSqlTableModel *model;
    QSound *son;
    QChart *chart;
    ///eya
    ///


    Client tmpclient;
    Client tmpclient2;

    fournisseur tmpfournisseur;
    fournisseur tmpfournisseur2;

     QSqlTableModel *model1;
    fournisseur tmpc;
    //youssef

    Assurance tmp;
    Assurance tmp2;
    QSortFilterProxyModel * proxy;
    Parking tmp1;
    Parking tmp3;

    QSerialPort *arduino;
    void write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
     QByteArray data;
    static const quint16 arduino_uno_vendor_id=9025;
      static const quint16 arduino_uno_producy_id=67;
      QString arduino_port_name;
      bool arduino_is_available;
};
#endif // MAINWINDOW_H
