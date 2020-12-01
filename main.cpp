#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include "excelexporthelper.h"


int main(int argc, char *argv[])
{
    /*try
        {
            const QString fileName = "g:\\temp\\kaka2.xlsx";

            ExcelExportHelper helper;

            helper.SetCellValue(1,1,"Test-11");
            helper.SetCellValue(1,2,"Test-12");

            helper.SaveAs(fileName);
        }
        catch (const exception& e)
        {
            QMessageBox::critical(this, "Error - Demo", e.what());
        }*/
    QApplication a(argc, argv);
    Connection c;
        bool test=c.createconnect();
        MainWindow w;   //appelle constructeur= appelle afficher
        if(test)
        {w.show();
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
