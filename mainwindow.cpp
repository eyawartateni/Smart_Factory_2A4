#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parking.h"
#include "assurance.h"
#include<QPixmap>
#include <QComboBox>
#include "QMessageBox"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QPrintDialog>
#include <QFile>
#include <QDataStream>
#include <QTextStream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  /*  QPixmap bkgnd(":/image/image/be-our-service.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);*/
    ui->choix_2->addItem("reference");
    ui->choix_2->addItem("place");
    ui->choix_2->addItem("nom");

    ui->ln_reference->setValidator(new QIntValidator(0,99999999,this));
    ui->ln_prix->setValidator(new QIntValidator(0,99999999,this));
    ui->ln_compagnie->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
    ui->ln_type->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));
    ui->reference_2->setValidator(new QIntValidator( 0,99999999, this ));
    ui->nbr_place_2->setValidator(new QIntValidator( 0,99999999, this ));
    ui->nom_employe_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_]{0,255}"), this ));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_connexion_clicked()
{
    QString username = ui->ln_user->text();
    QString password = ui->ln_password->text();

    if(username == "y"  &&  password ==  "y" )
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
*/

void MainWindow::on_ajouter_assu_clicked()
{
    // recuperer les informations saisies dans l'interface
     QString compagnie = ui->ln_compagnie->text();
     int prix = ui->ln_prix->text().toInt();
     QString type = ui->ln_type->text();
     int reference = ui->ln_reference->text().toInt();

     Assurance A(compagnie,prix,type,reference);
     bool test=A.ajouter();

     if(test)
     {
         ui->tableView_assurance->setModel(tmp.afficher()); // refresh => chaque ajout sera affiché
         QMessageBox::information(nullptr, QObject::tr("Assurance Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_mod_assu_clicked()
{
    QString compagnie,type,reference,prix;
    //int reference,prix;
    compagnie=ui->ln_compagnie->text();
    type=ui->ln_type->text();
    prix=ui->ln_prix->text();
    reference=ui->ln_reference->text();

    QSqlQuery qry;
    qry.prepare("update assurance set reference='"+reference+"',type='"+type+"',prix='"+prix+"',compagnie='"+compagnie+"'where reference='"+reference+"'");
    if(qry.exec())
    {
        ui->tableView_assurance->setModel(tmp.afficher());
        //ui->tableView_upark->setModel(tmp.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_export_pdf_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_assurance->model()->rowCount();
                     const int columnCount = ui->tableView_assurance->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_assurance->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_assurance->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_assurance->isColumnHidden(column)) {
                                 QString data = ui->tableView_assurance->model()->data(ui->tableView_assurance->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}

void MainWindow::on_recherche_clicked()
{
    ui->tableView_assurance->setModel(tmp.recherche(ui->reref->text().toInt(),ui->retype->text(),ui->recom->text()));
}

void MainWindow::on_afficher_tab_assu_clicked()
{
    ui->tableView_assurance->setModel(tmp.afficher());
}

void MainWindow::on_park_ajout_2_clicked()
{
    //QSqlQueryModel * model= new QSqlQueryModel();
    int reference = ui->reference_2->text().toInt();
    int place = ui->nbr_place_2->text().toInt();
    QString nom = ui->nom_employe_2->text();

    Parking P(reference,place,nom);
    //model=P.recherche(reference,nom);
    //if(model==0)
    //{
        bool test=P.ajouter();
        if(test)
        {
            ui->tableView_parking_2->setModel(tmp1.afficher());
            QMessageBox::information(nullptr, QObject::tr("Parking ajouté"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit"),QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr, QObject::tr("Parking pas ajouté"),
                         QObject::tr("OK.\n"
                                     "Click Cancel to exit."),QMessageBox::Cancel);

   /* }
    else
        QMessageBox::critical(nullptr, QObject::tr("Nom ou Place Deja Utilisée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);*/



}

void MainWindow::on_mod_park_2_clicked()
{
    QString reference,place,nom;
    reference=ui->reference_2->text();
    place=ui->nbr_place_2->text();
    nom=ui->nom_employe_2->text();

    QSqlQuery qry1;
    qry1.prepare("update parking set reference='"+reference+"',place='"+place+"',nom='"+nom+"'where reference='"+reference+"'");
    if(qry1.exec())
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());
        QMessageBox::information(this,tr("Edit"),tr("Updated"));

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Modifiée"),
                              QObject::tr("OK.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }
}



void MainWindow::on_trier_2_clicked()
{
    int test=0;

          if (ui->choix_2->currentText()=="reference")
                     {test=1;}

          else if (ui->choix_2->currentText()=="nom")
                      {test=2;}

          else if (ui->choix_2->currentText()=="place")
                      {test=3;}


          ui->tableView_parking_2->setModel(tmp1.trier(test)) ;
}

void MainWindow::on_afficher_tab_park_2_clicked()
{
    ui->tableView_parking_2->setModel(tmp1.afficher());
}

void MainWindow::on_supp_park_2_clicked()
{
    int reference = ui->reference_2->text().toInt();
    bool test=tmp1.supprimer(reference);
    if(test)
    {
        ui->tableView_parking_2->setModel(tmp1.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    int reference = ui->ln_reference->text().toInt();
    bool test=tmp.supprimer(reference);
    if(test)
    {
        ui->tableView_assurance->setModel(tmp.afficher());// refresh => chaque ajout sera affiché

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tableView_assurance_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_assurance->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from ASSURANCE  where PRIX='"+val+"'or REFERENCE='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->ln_compagnie->setText(qry.value(0).toString());

           ui->ln_type->setText(qry.value(1).toString());

           ui->ln_prix->setText(qry.value(2).toString());

           ui->ln_reference->setText(qry.value(3).toString());
       }
    }
}

void MainWindow::on_tableView_parking_2_activated(const QModelIndex &index)
{
    QString  val=ui->tableView_parking_2->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from PARKING  where REFERENCE='"+val+"'or NOM='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->reference_2->setText(qry.value(0).toString());

           ui->nbr_place_2->setText(qry.value(1).toString());

           ui->nom_employe_2->setText(qry.value(2).toString());
       }
    }
}
