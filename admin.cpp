#include "admin.h"
#include "ui_admin.h"
#include "dialog_assurance.h"
#include "parking.h"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_assurance_clicked()
{
    dialog_assurance a;
    a.exec();
}

void admin::on_parking_clicked()
{
    parking f;
    f.exec();
}
