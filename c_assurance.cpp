#include "assurance.h"
#include "ui_assurance.h"

assurance::assurance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assurance)
{
    ui->setupUi(this);
}

assurance::~assurance()
{
    delete ui;
}
