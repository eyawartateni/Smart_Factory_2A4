#include "dialog_parking.h"
#include "ui_dialog_parking.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "QMessageBox"
#include "parking.h"
#include <QComboBox>

dialog_parking::dialog_parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_parking)
{
    ui->setupUi(this);
    ui->choix_2->addItem("reference");
    ui->choix_2->addItem("place");
    ui->choix_2->addItem("nom");
    ui->tableView_parking_2->setModel(tmp1.afficher());
}

dialog_parking::~dialog_parking()
{
    delete ui;
}

void dialog_parking::on_park_ajout_2_clicked()
{
    int reference = ui->reference_2->text().toInt();
    int place = ui->nbr_place_2->text().toInt();
    QString nom = ui->nom_employe_2->text();

    Parking P(reference,place,nom);
    bool test=P.ajouter();
    if(test)
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());
        QMessageBox::information(nullptr, QObject::tr("Parking ajouté"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit"),QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Parking pas ajouté"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);

}

void dialog_parking::on_mod_park_2_clicked()
{
    QString reference,place,nom;
    reference=ui->reference_2->text();
    place=ui->nbr_place_2->text();
    nom=ui->nom_employe_2->text();

    QSqlQuery qry1;
    qry1.prepare("update parking set reference='"+reference+"',place='"+place+"',nom='"+nom+"'where reference='"+reference+"'");
    if(qry1.exec())
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

}

void dialog_parking::on_supp_park_2_clicked()
{
    int reference = ui->park_supp_2->text().toInt();
    bool test=tmp1.supprimer(reference);
    if(test)
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Parking Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Parking Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialog_parking::on_trier_2_clicked()
{
    int test=0;

          if (ui->choix_2->currentText()=="reference")
                     {test=1;}

          else if (ui->choix_2->currentText()=="nom")
                      {test=2;}

          else if (ui->choix_2->currentText()=="place")
                      {test=3;}


          ui->tableView_parking_2->setModel(tmp1.trier(test)) ;
}

void dialog_parking::on_afficher_tab_park_2_clicked()
{
    ui->tableView_parking_2->setModel(tmp1.afficher());
}
