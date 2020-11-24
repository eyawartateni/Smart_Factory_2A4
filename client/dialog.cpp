#include "dialog.h"
#include "ui_dialog.h"
#include "client.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setClient(Client C)
{
ui->lineEdit_nom->setText(C.getNom());
ui->lineEdit_prenom->setText(C.getPrenom());
ui->lineEdit_paiement->setText(C.getpaiement());
ui->dateEdit->setDate(C.getdate_naissance());
ui->lineEdit_cin->setText(C.getCin());
ui->lineEdit_achat->setText(C.getachat());
ui->lineEdit_model->setText(C.getModelChoisi());


}
