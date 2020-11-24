#include "dialog_fournisseur.h"
#include "ui_dialog_fournisseur.h"
#include "fournisseur.h"

Dialog_fournisseur::Dialog_fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_fournisseur)
{
    ui->setupUi(this);
}

Dialog_fournisseur::~Dialog_fournisseur()
{
    delete ui;
}

/*void Dialog_fournisseur::setfournisseur(fournisseur F)
{
   ui->lineEdit_prenomFour->setText(F.getPrenom());
   ui->lineEdit_cinfour->setText(F.getCin());
   ui->NomFournisseur_2->setText(F.getNom());
   ui->dateEdit_datelimF->setDate(F.getdate_limite());
   ui->lineEdit_prixapyer->setText(F.getprix_apayer());
ui->nombre->setText(F.getnbre_pieces());
ui->piece_demand->setText(F.getpieces_demand());

   //ui->nbre->setDate


}*/


