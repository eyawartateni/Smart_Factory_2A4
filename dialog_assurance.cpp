#include "dialog_assurance.h"
#include "ui_dialog_assurance.h"
#include "assurance.h"
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




dialog_assurance::dialog_assurance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_assurance)
{
    ui->setupUi(this);
    ui->tableView_assurance->setModel(tmp.afficher());
}

dialog_assurance::~dialog_assurance()
{
    delete ui;
}

void dialog_assurance::on_supprimer_clicked()
{
    int reference = ui->supp_assu->text().toInt();
    bool test=tmp.supprimer(reference);
    if(test)
    {
        ui->tableView_assurance->setModel(tmp.afficher());// refresh => chaque ajout sera affiché
        //ui->tableView_upark->setModel(tmp.afficher());

        QMessageBox::information(nullptr, QObject::tr("Assurance Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Supprimé"),
                    QObject::tr("OK.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialog_assurance::on_ajouter_assu_clicked()
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
         //ui->tableView_upark->setModel(tmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("Assurance Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("Assurance Pas Ajoutée"),
                     QObject::tr("OK.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void dialog_assurance::on_mod_assu_clicked()
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

/*
void dialog_assurance::on_recherche_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void dialog_assurance::on_criteres_currentIndexChanged(int index)
{
    if(index>1)
    {
        index = -1;
    }
}
*/

void dialog_assurance::on_recherche_clicked()
{
    ui->tableView_assurance->setModel(tmp.recherche(ui->reref->text().toInt(),ui->retype->text(),ui->recom->text()));
}
/*
void dialog_assurance::on_export_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_assurance->model()->rowCount();
    const int columnCount = ui->tableView_assurance->model()->columnCount();
    out << "<html>\n""<head>\n""<meta Content=\"Text/html; charset=Windows-1251\">\n"
    << QString("<title>%1<title>\n").arg("strTitle")
    << "<head>\n""<body bgcolor=#ffffff link=#5000A0>\n"
    // "<align= 'right'> "<<datefich << "</align>" "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    //headers
     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for(int column =0;column<columnCount; column++)
        if(!ui->tableView_assurance->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_assurance->model()->headerData(column,Qt::Horizontal).toString());
    out<< "</tr></thead>\n";
    //data table
    for (int row=0;row<rowCount;row++)
    {
        out<< "<tr> <td bkcolor=0>" <<row+1 <<"</td>";
        for(int column = 0;column<columnCount; column++)
        {
            if(!ui->tableView_assurance->isColumnHidden(column))
            {
                QString data = ui->tableView_assurance->model()->data(ui->tableView_assurance->model()->index(row,column)).toString().simplified();
                out << QString("<td bkcolor=0>%1<td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<"</table> <center>\n"
          "</body>\n"
          "</html>\n";
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0,"Sauvegarder en PDF", QString(), "*.pdf");
    (QFileInfo(fileName).suffix().isEmpty());
    {fileName.append(".pdf");}
    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
*/
void dialog_assurance::on_afficher_tab_assu_clicked()
{
    ui->tableView_assurance->setModel(tmp.afficher());
}
