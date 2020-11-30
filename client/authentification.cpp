#include "authentification.h"
#include "ui_authentification.h"
#include <QSqlQuery>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
}

authentification::~authentification()
{
    delete ui;
}


void authentification::on_pushButton_clicked()
{
    QString username;
    QString password;
    username=ui->username->text();
    password=ui->password->text();
    if(username=="test" && password=="test")
    {
        QMessageBox::information(nullptr, QObject::tr("connexion"),
                    QObject::tr("vous etes connecté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }
 else
    {
        QMessageBox::critical(nullptr, QObject::tr("connexion"),
                    QObject::tr("connexion echouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}


