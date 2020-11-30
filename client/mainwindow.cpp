#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog_fournisseur.h"
#include "client.h"
#include "fournisseur.h"
#include "C:/Users/eyaou/Desktop/Qt-Table-Printer-master/tableprinter.h"

#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSound>
#include <QMessageBox>
#include <QValidator>
#include <QPixmap>
#include <QPrinter>
#include <QFile>
#include <QTableWidgetItem>
#include <QTextDocument>
#include <QPrintDialog>
#include <QTextStream>
#include <QString>
#include <QPainter>

#include <QPrintPreviewWidget>
#include <QFileDialog>
#include <QDebug>




#include "dialog_fournisseur.h"

#include "dialog.h"

class PrintBorder : public PagePrepare {
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};
///test
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


    son=new QSound("C:/Users/eyaou/Desktop/Smart_Factory_2A4/client/son.wav");
    //////pdf

    model = new QSqlTableModel;
        model->setTable("client");
        model->select();
        ui->tabclient->setModel(model);
        //////

        ui->tri->addItem("CIN");
         ui->tri->addItem("NOM");
          ui->tri->addItem("PRENOM");


//// affichage client et fournisseur
    ui->tabclient->setModel(tmpclient.afficher());
    ui->tabfour->setModel(tmpfournisseur.afficherFour());

///////filtrer les données d'un client

modClient= new QSqlRelationalTableModel(this);
modClient->setTable("client");
modClient->select();
proxyclient=new QSortFilterProxyModel(this);
proxyclient->setSourceModel(modClient);
proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
proxyclient->setFilterKeyColumn(0);

ui->tabclient->setModel(proxyclient);


/////////filtrer les donnees fournisseur

modFournisseur= new QSqlRelationalTableModel(this);
modFournisseur->setTable("fournisseur");
modFournisseur->select();
proxyfournisseur=new QSortFilterProxyModel(this);
proxyfournisseur->setSourceModel(modFournisseur);
proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
proxyfournisseur->setFilterKeyColumn(0);


ui->tabfour->setModel(proxyfournisseur);



///
    QPixmap pix("C:/Users/eyaou/Desktop/copie lekhra/client/client/images/unnamed");

//ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

     ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
     ui->cinfour->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_paiement->setValidator(new QIntValidator(0,99999999,this));
      ui->prixpayer->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_achat->setValidator(new QIntValidator(0,99999999,this));




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_quitter_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"quitter","voulez vous vraiment quitter?",QMessageBox::Yes |QMessageBox::No);
    if(reply==QMessageBox::Yes )
    {
        close();

    }
    else
    {

    }


}



void MainWindow::on_terminer_clicked()
{
son->play();
     QString cin=ui->lineEdit_cin->text();
      QString nom=ui->lineEdit_nom->text();
       QString prenom=ui->lineEdit_prenom->text();
        QString date_naissance=ui->date_naissance->text();
         QString achat=ui->lineEdit_achat->text();
         QString model_choisi=ui->lineEdit_model->text();
       QString paiement=ui->lineEdit_paiement->text();
      Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
        bool test=C.ajouter();
        if(test)
        {
            ui->tabclient->setModel(tmpclient.afficher()); //refresh
           /*modClient= new QSqlRelationalTableModel(this);
            modClient->setTable("client");
            modClient->select();
            proxyclient=new QSortFilterProxyModel(this);
            proxyclient->setSourceModel(modClient);
            proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
            proxyclient->setFilterKeyColumn(0);

            ui->tabclient->setModel(proxyclient);*/






            //ui->tabclient->setModel(tmpclient.rechercherclient(ui->cin_chercher->text(),ui->cher_nom->text(),ui->cher_prenom->text()));
            QMessageBox::information(nullptr, QObject::tr("ajouter un client"),
                        QObject::tr("etudiant ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ajouter un client"),
                        QObject::tr("ajout échoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }
}


void MainWindow::on_modifier_clicked()
{
son->play();
QString CIN=ui->cin_chercher->text();
    QString cin=ui->lineEdit_cin->text();
     QString nom=ui->lineEdit_nom->text();
      QString prenom=ui->lineEdit_prenom->text();
       QString date_naissance=ui->date_naissance->text();
        QString achat=ui->lineEdit_achat->text();
        QString model_choisi=ui->lineEdit_model->text();
      QString paiement=ui->lineEdit_paiement->text();
     Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
       bool test=C.modifier(CIN);
       if(test)
       {
           ui->tabclient->setModel(tmpclient.afficher()); //refresh
           modClient= new QSqlRelationalTableModel(this);
           modClient->setTable("client");
           modClient->select();
           proxyclient=new QSortFilterProxyModel(this);
           proxyclient->setSourceModel(modClient);
           proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyclient->setFilterKeyColumn(0);

           ui->tabclient->setModel(proxyclient);
           QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("done.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                       QObject::tr("try again.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }
}



void MainWindow::on_afficher_clicked()
{
son->play();
    Dialog d;
    Client C;
    C.setCin(ui->lineEdit_cin->text());
    C.setnom(ui->lineEdit_nom->text());
    C.setPrenom(ui->lineEdit_prenom->text());
    C.setdate_naissance(ui->date_naissance->text());
    C.setpaiement(ui->lineEdit_paiement->text());
    C.setachat(ui->lineEdit_achat->text());
    C.setModelChoisi(ui->lineEdit_model->text());
    d.setClient(C);
    d.exec();


}

void MainWindow::on_afficher_fournisseur_clicked()
{
    son->play();
Dialog_fournisseur df;
fournisseur F;
F.setnom(ui->NomFournisseur_2->text());
F.setPrenom(ui->prenomfour->text());
F.setCin(ui->cinfour->text());
F.setdate_limite(ui->date_limite->text());
F.setpieces_demand(ui->piecedemand->text());
F.setprix_apyer(ui->prixpayer->text());
F.setnbre_pieces(ui->nbre->text());

//F.setnombre
//df.setfournisseur(F);
df.exec();

}


void MainWindow::on_supprimer_client_clicked()
{

son->play();
    QString CIN=ui->cin_chercher->text();
    bool test=tmpclient.supprimer(CIN);
    if(test)
    {
        ui->tabclient->setModel(tmpclient.afficher());
        ui->tabclient->setModel(tmpclient.afficher()); //refresh
        modClient= new QSqlRelationalTableModel(this);
        modClient->setTable("client");
        modClient->select();
        proxyclient=new QSortFilterProxyModel(this);
        proxyclient->setSourceModel(modClient);
        proxyclient->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyclient->setFilterKeyColumn(-1);




        ui->tabclient->setModel(proxyclient);
        QMessageBox::information(nullptr, QObject::tr("supprimer un client"),
                    QObject::tr("etudiant supprimer.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer un client"),
                    QObject::tr("suppression échouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }


}



void MainWindow::on_supprimer_fournisseur_clicked()
{
   /* Dialog_modifier dm;
    dm.exec();*/
son->play();
    QString CIN=ui->cincherf->text();
    bool test=tmpfournisseur.supprimerFour(CIN);
    if(test)
    {
        ui->tabfour->setModel(tmpfournisseur.afficherFour());
        ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh
        modFournisseur= new QSqlRelationalTableModel(this);
        modFournisseur->setTable("fournisseur");
        modFournisseur->select();
        proxyfournisseur=new QSortFilterProxyModel(this);
        proxyfournisseur->setSourceModel(modFournisseur);
        proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyfournisseur->setFilterKeyColumn(-1);


        ui->tabfour->setModel(proxyfournisseur);

        QMessageBox::information(nullptr, QObject::tr("supprimer fournisseur"),
                    QObject::tr("fournisseur supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer un fournisseur"),
                    QObject::tr("suppression échouée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }

}



void MainWindow::on_modifierFour_clicked()
{
    son->play();
   QString CIN=ui->cincherf->text();
    QString cin=ui->cinfour->text();



     QString nom=ui->NomFournisseur_2->text();
      QString prenom=ui->prenomfour->text();
       QString dateLimite=ui->date_limite->text();
        QString piece_demandee=ui->piecedemand->text();
        QString nbre_piece=ui->nbre->text();
      QString prix_apayer=ui->prixpayer->text();
     fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);


       bool test=F.modifierFour(CIN);
       if(test)
       {
           ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh
           modFournisseur= new QSqlRelationalTableModel(this);
           modFournisseur->setTable("fournisseur");
           modFournisseur->select();
           proxyfournisseur=new QSortFilterProxyModel(this);
           proxyfournisseur->setSourceModel(modFournisseur);
           proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyfournisseur->setFilterKeyColumn(-1);


           ui->tabfour->setModel(proxyfournisseur);


           QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                       QObject::tr("done.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                       QObject::tr("try again.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }

}




void MainWindow::on_ajouterFour_clicked()
{
    son->play();
    QString cin=ui->cinfour->text();
     QString nom=ui->NomFournisseur_2->text();
      QString prenom=ui->prenomfour->text();
       QString dateLimite=ui->date_limite->text();
        QString piece_demandee=ui->piecedemand->text();
        QString nbre_piece=ui->nbre->text();
      QString prix_apayer=ui->prixpayer->text();
     fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);
       bool test=F.ajouterFour();
       if(test)
       {
           ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh


           modFournisseur= new QSqlRelationalTableModel(this);
           modFournisseur->setTable("fournisseur");
           modFournisseur->select();
           proxyfournisseur=new QSortFilterProxyModel(this);
           proxyfournisseur->setSourceModel(modFournisseur);
           proxyfournisseur->setFilterCaseSensitivity(Qt::CaseInsensitive);
           proxyfournisseur->setFilterKeyColumn(-1);


           ui->tabfour->setModel(proxyfournisseur);

           QMessageBox::information(nullptr, QObject::tr("ajouter un fournisseur"),
                       QObject::tr("fournisseur ajouté.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ajouter un fournisseur"),
                       QObject::tr("ajout échoué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


       }
}



void MainWindow::on_trier_clicked()
{

    son->play();
    int test=0;


             if (ui->tri->currentText()=="CIN")
            {test=1;}
        else
                 if (ui->tri->currentText()=="NOM")
                {
                     test=2;
                 }
          else
                     if (ui->tri->currentText()=="PRENOM")
                     {
                         test=3;
                     }



                ui->tabfour->setModel(tmpc.trier(test)) ;



}

void MainWindow::on_cin_chercher_textChanged(const QString &arg1)
{


    proxyclient->setFilterFixedString(arg1);

}

void MainWindow::on_cincherf_textChanged(const QString &arg1)
{
    proxyfournisseur->setFilterFixedString(arg1);
}

void MainWindow::on_tabfour_activated(const QModelIndex &index)
{

  QString  val=ui->tabfour->model()->data(index).toString();

  QSqlQuery qry;
 qry.prepare("select * from fournisseur  where CIN='"+val+"'or nom='"+val+"'");

  if(qry.exec())
  {
     while(qry.next())
     {
         ui->cinfour->setText(qry.value(0).toString());
         ui->NomFournisseur_2->setText(qry.value(1).toString());
         ui->prenomfour->setText(qry.value(2).toString());
         ui->piecedemand->setText(qry.value(3).toString());
         ui->nbre->setText(qry.value(5).toString());
         ui->prixpayer->setText(qry.value(4).toString());
         ui->date_limite->setText(qry.value(6).toString());


     }
  }
  else
  {
      QMessageBox::critical(this,tr("error::"),qry.lastError().text());
  }

}

void MainWindow::on_tabclient_activated(const QModelIndex &index)
{

    QString  val=ui->tabclient->model()->data(index).toString();
    QSqlQuery qry;


    qry.prepare("select * from client  where CIN='"+val+"'or nom='"+val+"'");

    if(qry.exec())
    {
       while(qry.next())
       {
           ui->lineEdit_cin->setText(qry.value(0).toString());

           ui->lineEdit_prenom->setText(qry.value(1).toString());

           ui->lineEdit_nom->setText(qry.value(2).toString());

           ui->lineEdit_model->setText(qry.value(3).toString());

           ui->lineEdit_achat->setText(qry.value(4).toString());

           ui->lineEdit_paiement->setText(qry.value(5).toString());
ui->date_naissance->setText(qry.value(6).toString());



       }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void MainWindow::on_exportpdf_clicked( )
{
    son->play();
    /* Dialog d;
     d.exec();*/
/* QPrinter printer;
 printer.setPrinterName("cc");
 QPrintDialog dialog(&printer,this);
 if(dialog.exec()==QDialog::Rejected)return;
ui->textnom->print(&printer);*/



  /* Client c;
   c.exporterpdf();*/

    QPrintPreviewDialog dialog;
       connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
       dialog.exec();



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
        QVector<int> columnStretch = QVector<int>() << 15 << 15 << 15 << 15 <<15<<15<<15;
        if(!tablePrinter.printTable(ui->tabclient->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        painter.end();
}

void MainWindow::on_pushButton_clicked()
{
    son->play();
    ui->tabclient->setModel(tmpclient2.rechercherclient(ui->cin_chercher->text(),ui->cher_nom->text(),ui->cher_prenom->text()));
    //ui->tabclient->setModel(tmpclient.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    son->play();
         QString cin=ui->lineEdit_cin->text();
          QString nom=ui->lineEdit_nom->text();
           QString prenom=ui->lineEdit_prenom->text();
            QString date_naissance=ui->date_naissance->text();
             QString achat=ui->lineEdit_achat->text();
             QString model_choisi=ui->lineEdit_model->text();
           QString paiement=ui->lineEdit_paiement->text();
          Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
          ui->tabclient->setModel(tmpclient.afficher());
}



void MainWindow::on_chercherfour_clicked()
{
    son->play();
     ui->tabfour->setModel(tmpfournisseur2.rechercherfournisseur(ui->cincherf->text(),ui->cherf_nom->text(),ui->cherf_prenom->text()));
}

void MainWindow::on_afficherfour_clicked()
{
    son->play();
    ui->tabfour->setModel(tmpfournisseur.afficherFour());
}
