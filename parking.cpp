#include "parking.h"
#include "ui_parking.h"
#include "cparking.h"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



parking::parking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parking)
{
    ui->setupUi(this);
    ui->tableView_parking->setModel(tmp1.afficher());
}

parking::~parking()
{
    delete ui;
}



void parking::on_supp_park_clicked()
{
    int reference = ui->park_supp->text().toInt();
    bool test=tmp1.supprimer(reference);
    if(test)
    {
        ui->tableView_parking->setModel(tmp1.afficher()); // refresh => chaque ajout sera affiché
        QMessageBox::information(nullptr, QObject::tr("Parking Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Parking Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void parking::on_park_ajout_clicked()
{
    // recuperer les informations saisies dans l'interface
     int reference = ui->reference->text().toInt();
     int place = ui->nbr_place->text().toInt();
     QString nom = ui->nom_employe->text();

     Cparking P(reference,place,nom);
     bool test=P.ajouter();

     if(test)
     {
         ui->tableView_parking->setModel(tmp1.afficher()); // refresh => chaque ajout sera affiché
         QMessageBox::information(nullptr, QObject::tr("Parking Ajouté"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Parking Pas Ajouté"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void parking::on_mod_park_clicked()
{
    QString reference,place,nom;
    reference=ui->reference->text();
    place=ui->nbr_place->text();
    nom=ui->nom_employe->text();

    QSqlQuery qry1;
    qry1.prepare("update parking set reference='"+reference+"',place='"+place+"',nom='"+nom+"'where reference='"+reference+"'");
    if(qry1.exec())
    {
        ui->tableView_parking->setModel(tmp1.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}
