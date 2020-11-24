#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog_fournisseur.h"
#include "client.h"
#include "fournisseur.h"


#include <QMessageBox>
#include <QValidator>
#include <QPixmap>
#include <QPrinter>
#include <QFile>




#include "dialog_fournisseur.h"

#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    QPixmap pix("C:/qttt/xxx");
ui->label_pic->setPixmap(pix.scaled(120,120,Qt::KeepAspectRatio));
     ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
     ui->cinfour->setValidator(new QIntValidator(0,99999999,this));
      ui->lineEdit_paiement->setValidator(new QIntValidator(0,99999999,this));
      ui->prixpayer->setValidator(new QIntValidator(0,99999999,this));


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

     QString cin=ui->lineEdit_cin->text();
      QString nom=ui->lineEdit_nom->text();
       QString prenom=ui->lineEdit_prenom->text();
        QDate date_naissance=ui->dateEdit->date();
         QString achat=ui->lineEdit_achat->text();
         QString model_choisi=ui->lineEdit_model->text();
       QString paiement=ui->lineEdit_paiement->text();
      Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
        bool test=C.ajouter();
        if(test)
        {
            ui->tabclient->setModel(tmpclient.afficher()); //refresh
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

QString CIN=ui->cin_chercher->text();
    QString cin=ui->lineEdit_cin->text();
     QString nom=ui->lineEdit_nom->text();
      QString prenom=ui->lineEdit_prenom->text();
       QDate date_naissance=ui->dateEdit->date();
        QString achat=ui->lineEdit_achat->text();
        QString model_choisi=ui->lineEdit_model->text();
      QString paiement=ui->lineEdit_paiement->text();
     Client C(cin,nom,prenom,achat,paiement,model_choisi,date_naissance);
       bool test=C.modifier(CIN);
       if(test)
       {
           ui->tabclient->setModel(tmpclient.afficher()); //refresh
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

    Dialog d;
    Client C;
    C.setCin(ui->lineEdit_cin->text());
    C.setnom(ui->lineEdit_nom->text());
    C.setPrenom(ui->lineEdit_prenom->text());
    C.setdate_naissance(ui->dateEdit->date());
    C.setpaiement(ui->lineEdit_paiement->text());
    C.setachat(ui->lineEdit_achat->text());
    C.setModelChoisi(ui->lineEdit_model->text());
    d.setClient(C);
    d.exec();


}

void MainWindow::on_afficher_fournisseur_clicked()
{
Dialog_fournisseur df;
fournisseur F;
F.setnom(ui->NomFournisseur_2->text());
F.setPrenom(ui->prenomfour->text());
F.setCin(ui->cinfour->text());
F.setdate_limite(ui->datelim_2->date());
F.setpieces_demand(ui->piecedemand->text());
F.setprix_apyer(ui->prixpayer->text());
F.setnbre_pieces(ui->nbre->cleanText());

//F.setnombre
//df.setfournisseur(F);
df.exec();

}


void MainWindow::on_supprimer_client_clicked()
{


    QString CIN=ui->cin_chercher->text();
    bool test=tmpclient.supprimer(CIN);
    if(test)
    {
        ui->tabclient->setModel(tmpclient.afficher());
        ui->tabclient->setModel(tmpclient.afficher()); //refresh
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

    QString CIN=ui->cincherf->text();
    bool test=tmpfournisseur.supprimerFour(CIN);
    if(test)
    {
        ui->tabfour->setModel(tmpfournisseur.afficherFour());
        ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh
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
   QString CIN=ui->cincherf->text();
    QString cin=ui->cinfour->text();



     QString nom=ui->NomFournisseur_2->text();
      QString prenom=ui->prenomfour->text();
       QDate dateLimite=ui->datelim_2->date();
        QString piece_demandee=ui->piecedemand->text();
        QString nbre_piece=ui->nbre->cleanText();
      QString prix_apayer=ui->prixpayer->text();
     fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);


       bool test=F.modifierFour(CIN);
       if(test)
       {
           ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh
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
    QString cin=ui->cinfour->text();
     QString nom=ui->NomFournisseur_2->text();
      QString prenom=ui->prenomfour->text();
       QDate dateLimite=ui->datelim_2->date();
        QString piece_demandee=ui->piecedemand->text();
        QString nbre_piece=ui->nbre->cleanText();
      QString prix_apayer=ui->prixpayer->text();
     fournisseur F(cin,nom,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite);
       bool test=F.ajouterFour();
       if(test)
       {
           ui->tabfour->setModel(tmpfournisseur.afficherFour()); //refresh
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
         ui->prixpayer->setText(qry.value(5).toString());
         ui->prixpayer->setText(qry.value(4).toString());
       //  ui->datelim_2->setDate(qry.value(6).toDate());


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
           ui->lineEdit_achat->setText(qry.value(5).toString());
           ui->lineEdit_paiement->setText(qry.value(4).toString());
          ui->datelim_2->setDate(qry.value(6).toDate());


       }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void MainWindow::on_exportpdf_clicked()
{

}
