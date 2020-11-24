#include "dialog_modifier.h"
#include "ui_dialog_modifier.h"

Dialog_modifier::Dialog_modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_modifier)
{
    ui->setupUi(this);
}

Dialog_modifier::~Dialog_modifier()
{
    delete ui;
}

void Dialog_modifier::on_pushButton_clicked()
{
    close();
}
