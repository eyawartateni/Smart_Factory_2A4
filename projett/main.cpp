 #include "mainwindow.h"
#include<QDebug>
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;//1 seul instance de la classe cnx
    bool test=c.createconnect();//etablir la cnx

     MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
