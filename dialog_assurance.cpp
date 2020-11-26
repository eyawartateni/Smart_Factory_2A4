#include "dialog_assurance.h"
#include "ui_dialog_assurance.h"
#include "assurance.h"
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

dialog_assurance::dialog_assurance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_assurance)
{
    ui->setupUi(this);
    ui->tableView_assurance->setModel(tmp.afficher());
}

dialog_assurance::~dialog_assurance()
{
    delete ui;
}

void dialog_assurance::on_supprimer_clicked()
{
    int reference = ui->supp_assu->text().toInt();
    bool test=tmp.supprimer(reference);
    if(test)
    {
        ui->tableView_assurance->setModel(tmp.afficher()); // refresh => chaque ajout sera affiché
        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialog_assurance::on_ajouter_assu_clicked()
{
    // recuperer les informations saisies dans l'interface
     int prix = ui->ln_prix->text().toInt();
     QString compagnie = ui->ln_compagnie->text();
     QString type = ui->ln_type->text();
     int reference = ui->ln_reference->text().toInt();

     Assurance A(compagnie,prix,type,reference);
     bool test=A.ajouter();

     if(test)
     {
         ui->tableView_assurance->setModel(tmp.afficher()); // refresh => chaque ajout sera affiché
         QMessageBox::information(nullptr, QObject::tr("Assurance Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void dialog_assurance::on_mod_assu_clicked()
{
    QString compagnie,type,reference,prix;
    //int reference,prix;
    compagnie=ui->ln_compagnie->text();
    type=ui->ln_type->text();
    prix=ui->ln_prix->text();
    reference=ui->ln_reference->text();

    QSqlQuery qry;
    qry.prepare("update assurance set reference='"+reference+"',type='"+type+"',prix='"+prix+"',compagnie='"+compagnie+"'where reference='"+reference+"'");
    if(qry.exec())
    {
        ui->tableView_assurance->setModel(tmp.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }

}
