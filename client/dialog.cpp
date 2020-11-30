#include "dialog.h"
#include "ui_dialog.h"
#include "client.h"
#include <QPrinter>
#include <QPrintDialog>

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
ui->textEdit->setText(C.getNom());
ui->textEdit->setText(C.getPrenom());
ui->textEdit->setText(C.getpaiement());

ui->textEdit->setText(C.getCin());
ui->textEdit->setText(C.getachat());
ui->textEdit->setText(C.getModelChoisi());


}

void Dialog::on_exporterExcel_clicked()
{
   /* QPrinter printer;
     printer.setPrinterName("cc");
     QPrintDialog dialog(&printer,this);
     if(dialog.exec()==QDialog::Rejected)return;
     ui->textEdit->print(&printer);*/

}
