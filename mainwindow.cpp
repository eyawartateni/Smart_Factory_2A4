#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include "dialog_assurance.h"
#include"parking.h"
#include"admin.h"
#include"assurance.h"
#include<QString>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
          QPixmap bkgnd(":/image/image/be-our-service.jpg");
          bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
          QPalette palette;
          palette.setBrush(QPalette::Background, bkgnd);
          this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connexion_clicked()
{
    QString username = ui->ln_user->text();
    QString password = ui->ln_password->text();

    if(username == "youssef"  &&  password ==  "yoyo" )
    {
        hide();
        admin a;
        a.exec();
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("connection failed."),
                    QObject::tr("\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
