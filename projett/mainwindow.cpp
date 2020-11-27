#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voiture.h"
#include"chaine.h"
#include"connexion.h"
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include "C:\Users\Mayssa\Desktop\Qt-Table-Printer-master\Qt-Table-Printer-master/tableprinter.h"

#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>

class PrintBorder : public PagePrepare {
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter) { // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     ui->tableView->setModel(vtmp.afficher());
     ui->tableView->setModel(vtmp.afficher());
     ui->comboBox->setModel(vtmp.load());
     ui->comboBox_2->addItem("REFERENCE");
     ui->comboBox_2->addItem("NB_MACHINE");
     ui->comboBox_2->addItem("TYPE_PRODUIT");
     ui->tableView_2->setModel(ctmp.afficher());
     ui->tableView_2->setModel(ctmp.afficher());
     ui->comboBox_ch->setModel(ctmp.load_ch());
     model = new QSqlTableModel;
             model->setTable("chaine");
             model->select();
             ui->tableView_2->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    QString marque = ui->lineEdit_marque->text();
     QString modele=ui->lineEdit_modele->text();
     QString type=ui->lineEdit_type->text();
     QString options=ui->lineEdit_option->text();
     QString couleur=ui->lineEdit_couleur->text();
     int prix=ui->lineEdit_prix->text().toInt();
     int  prix_option=ui->lineEdit_p_op->text().toInt();
     int reference=ui->lineEdit_reference->text().toInt();
     voiture v(marque,reference,modele,prix,type,prix_option,couleur,options);
     bool test=v.ajouter();
     if(test)
     {
         ui->tableView->setModel(vtmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("voiture ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("voiture non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_ajouter_chaine_clicked()
{
    QString type_produit = ui->lineEdit_type_p->text();
     int  reference=ui->lineEdit_ref->text().toInt();
     int nb_machine=ui->spinBox->text().toInt();
     chaine c(reference,nb_machine,type_produit);
     bool test=c.ajouter();
     if(test)
     {
          ui->tableView_2->setModel(ctmp.afficher());
         QMessageBox::information(nullptr, QObject::tr("ajout effectuee"),
                     QObject::tr("chaine ajouté avec succés.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("ajout non effectuee"),
                     QObject::tr("chaine non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_afficher_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question
            (this,"quitter","voulez-vous vraiment quitter?",QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes)
{
        close();
    }else
    {

    }
}


void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_supprimer_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_4_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_afficher_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_modifier_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_supprimer_chaine_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(1);
}



void MainWindow::on_quitter_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question
         (this,"quitter","voulez-vous vraiment quitter?",QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes)
{
        close();
    }else
    {

    }
}

void MainWindow::on_load_data_clicked()
{
     ui->comboBox->setModel(vtmp.load());
}

void MainWindow::on_modifier_3_clicked()
{

    QSqlQuery query;
    QMessageBox msgBox;
    QMessageBox msgBox1;
    query.prepare("update VOITURE1 SET  MARQUE=:marque, MODELE=:modele, PRIX=:prix ,TYPE=:type,PRIX_OPTION=:prix_option,COULEUR=:couleur, OPTIONS=:options where REFERENCE=:reference");
    query.bindValue(":marque",ui->lineEdit_maq->text());
    query.bindValue(":reference",ui->lineEdit_refer->text().toInt());
    query.bindValue(":modele",ui->lineEdit_mod->text());
    query.bindValue(":prix",ui->lineEdit_p->text().toInt());
    query.bindValue(":type",ui->lineEdit_typ->text());
    query.bindValue(":prix_option",ui->lineEdit_po->text().toInt());
    query.bindValue(":couleur",ui->lineEdit_col->text());
    query.bindValue(":options",ui->lineEdit_ops->text());
    if(query.exec())
    {
       ui->tableView->setModel(vtmp.afficher());
       msgBox.setText("voiture modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("voiture non modifié");
           msgBox1.exec();
     }

}


void MainWindow::on_comboBox_currentIndexChanged()
{
    QString reference = ui->comboBox->currentText();
    QSqlQuery query;
    query.prepare("select*  from voiture1 where reference='"+reference+"'");
       if(query.exec())
    {
        while(query.next())
        {
             ui->lineEdit_refer->setText(query.value(0).toString());
            ui->lineEdit_maq->setText(query.value(1).toString());
            ui->lineEdit_mod->setText(query.value(2).toString());
            ui->lineEdit_typ->setText(query.value(3).toString());
            ui->lineEdit_ops->setText(query.value(4).toString());
            ui->lineEdit_col->setText(query.value(5).toString());
            ui->lineEdit_p->setText(query.value(6).toString());
            ui->lineEdit_po->setText(query.value(7).toString());

       }
    }

}


void MainWindow::on_sup_clicked()
{
     int reference=ui->lineEdit_referencee->text().toInt();
    bool test=vtmp.supprimer(reference);
    if(test)
    {
         ui->tableView->setModel(vtmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                    QObject::tr("voiture supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
    else
        QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                              QObject::tr("voiture non supprimé.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_tri_clicked()
{

    QSqlQueryModel *model=new QSqlQueryModel() ;

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NB_MACHINE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));
        ui->tableView_2->setModel(model);
        QSqlQuery query ;
            if(ui->comboBox_2->currentText()=="REFERENCE")
            query.prepare("SELECT *  FROM CHAINE ORDER BY REFERENCE ASC ") ;
          else

            if (ui->comboBox_2->currentText()=="NB_MACHINE")
            query.prepare("SELECT *  FROM CHAINE ORDER BY NB_MACHINE ASC ") ;
          else

            if (ui->comboBox_2->currentText()=="TYPE_PRODUIT")
             query.prepare("SELECT *  FROM CHAINE ORDER BY TYPE_PRODUIT ASC ") ;

            if (query.exec()&&query.next()) {
                model->setQuery(query) ;

                ui->tableView_2->setModel(model) ;
            }



}






void MainWindow::on_recherche_clicked()
{/*
      QString marque = ui->lineEdit_marquee->text();
      QString modele=ui->lineEdit_modelee->text();
      int reference=ui->lineEdit_referencee->text().toInt();
      ui->tableView->setModel(vtmp.recherche(reference,marque,modele));*/
}

void MainWindow::on_load_ch_clicked()
{
     ui->comboBox_ch->setModel(ctmp.load_ch());
}



void MainWindow::on_comboBox_ch_currentIndexChanged()
{
    //int REFERENCE = ui->comboBox_2->currentText().toInt();
    QSqlQuery query;
    query.prepare("select*  from CHAINE where REFERENCE=:REFERENCE");
       if(query.exec())
    {
        while(query.next())
        {
             ui->lineEdit_ref_ch->setText(query.value(0).toString());
            ui->lineEdit_nb_mach->setText(query.value(1).toString());
            ui->lineEdit_type_prod->setText(query.value(2).toString());
       }
    }

}

void MainWindow::on_modifier_ch_clicked()
{
    QSqlQuery query;
    QMessageBox msgBox;
    QMessageBox msgBox1;
    query.prepare("update CHAINE SET  NB_MACHINE=:NB_MACHINE, TYPE_PRODUIT=:TYPE_PRODUIT where REFERENCE=:REFERENCE");
     query.bindValue(":REFERENCE",ui->lineEdit_reff_ch->text().toInt());
    query.bindValue(":NB_MACHINE",ui->lineEdit_nb_mach->text());
    query.bindValue(":TYPE_PRODUIT",ui->lineEdit_type_prod->text());
    if(query.exec())
    {
       ui->tableView_2->setModel(ctmp.afficher());
       msgBox.setText("chaine modifié");
       msgBox.exec();
    }
else
    {
       msgBox1.setText("chaine non modifié");
           msgBox1.exec();
     }

}


void MainWindow::on_sup_ch_clicked()
{
    int reference=ui->lineEdit_reff_ch->text().toInt();
   bool test=ctmp.supprimer(reference);
   if(test)
   {
        ui->tableView_2->setModel(ctmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("suppression effectuee"),
                   QObject::tr("chaine supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
   else
       QMessageBox::critical(nullptr, QObject::tr("suppression non effectuee"),
                             QObject::tr("chaine non supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
  stat=new Statistique (this);
  stat->exec();
}

void MainWindow::print(QPrinter *printer)
{
    QPainter painter;
    if(!painter.begin(printer)) {
        qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<int> columnStretch = QVector<int>() << 2 << 5 << 10 ;
    if(!tablePrinter.printTable(ui->tableView_2->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    // print second table
    painter.translate(0, 100);
    if(!tablePrinter.printTable(ui->tableView_2->model(), columnStretch)) {
        qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

void MainWindow::on_pushButton_3_clicked()
{
    QPrintPreviewDialog dialog;
      connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
      dialog.exec();
}
