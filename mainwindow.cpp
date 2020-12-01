#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "agence.h"
#include <QSqlQuery >
#include "employer.h"
#include <QtCore>
#include<QPixmap>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QMovie>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include<QGraphicsScene>
#include<QTimer>
#include<QMessageBox>
#include<QPrinter>
#include<QPrintDialog>

#include "../../src/SmtpMime"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{





    ui->setupUi(this);

    ui->adm_id_supp->setValidator(new QIntValidator(0,99999999,this));
ui->ag_aj_cin_2->setValidator(new QIntValidator(0,99999999,this));
    ui->adm_aj_salaire_2->setValidator(new QIntValidator(0,99999999,this));
    ui->adm_aj_salaire->setValidator(new QIntValidator(0,99999999,this));
    ui->adm_aj_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;

     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_menu))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;

         QGraphicsScene scene;

         processLabel = new QLabel(this);

           QMovie *movie = new QMovie(":/image/res/car-loader-gif-1.gif");

        movie->start();

        processLabel->setWindowFlags(Qt::FramelessWindowHint);

        //processLabel->setMask((new QPixmap(":/image/res/car-loader-gif-1.gif"))->mask());

                 movie->setScaledSize(QSize(500,500));

                 processLabel->setMovie(movie);

                 processLabel->setAttribute(Qt::WA_NoSystemBackground);

                 processLabel->setAttribute(Qt::WA_TranslucentBackground,true);

                 processLabel->setGeometry(550,100,380,500);

                 processLabel->setScaledContents(true);
                 scene.addWidget(processLabel);






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_login_clicked()
{

    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->login))  ;
      QSqlQuery query   ;
      query.prepare("SELECT *  FROM TABLE1 WHERE PASSE=:passe AND ADRESSE=:adresse");
      query.bindValue(":passe",ui->logpass->text());
      query.bindValue(":adresse",ui->log_add->text() ) ;
    //  query.exec() ;
     if (query.exec()&&query.next()) {
          processLabel->close() ;
          QSound *son=new QSound(":/image/res/Welcome - Male Voice Speaks (128 kbps) (mp3cut.net)(1).wav");
          son->play() ;
          if(query.value(4).toString()=="administrateur") {
             ui->tabWidget->insertTab(max,ui->adm_menu,"Home") ;

     }
        else {

             processLabel->close() ;
        ui->tabWidget->insertTab(max,ui->em_profil,"Profile") ;
        ui->aff_cin->setText(query.value(0).toString() );
        ui->aff_nom->setText(query.value(1).toString() );
        ui->aff_prenom->setText(query.value(2).toString() );
        ui->aff_sal->setText(query.value(3).toString() );
        ui->aff_poste->setText(query.value(4).toString() );
         if(query.value(5).toString()=="married"){
        ui->aff_combo_etat->setCurrentIndex(2) ;
 }
         else {
             ui->aff_combo_etat->setCurrentIndex(1) ;
         }
             ui->aff_spinBox->setValue(query.value(6).toInt()) ;

        }

     }
     else {
       //  processLabel->close() ;
     //    ui->tabWidget->addTab(ui->ag_stat,"Login") ;
         //ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->login)) ;



          ui->tabWidget->insertTab(0,ui->login,"Login") ;

          if (ui->log_add->text().isEmpty()&&ui->logpass->text().isEmpty()) {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
              QObject::tr("Information incomplete .\n""Click Cancel to exit."), QMessageBox::Cancel);

          }
         else if (ui->log_add->text().isEmpty()) {
              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
              QObject::tr("Adresse est vide.\n""Click Cancel to exit."), QMessageBox::Cancel);

          }
          else if (ui->logpass->text().isEmpty()) {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
               QObject::tr("Mot de passe est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);

           }
          else {

              QMessageBox::critical(nullptr, QObject::tr("Erreur"),
              QObject::tr("Mte de passe et/ou l adresse n existe pas  .\n""Click Cancel to exit."), QMessageBox::Cancel);
          }

     }
        // ui->tabWidget->setCurrentIndex(0) ;
}

void MainWindow::on_m_agence_clicked()
{agence ag ;
    ui->ag_tab_aff->setModel(ag.afficher());
    max=0 ;
    ui->tabWidget->removeTab(max)  ;
    ui->tabWidget->insertTab(max,ui->menu_ag,"Agence") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->aj_ajout,"Ajouter");
    max++ ;
    ui->tabWidget->insertTab(max,ui->ag_aff,"Afficher") ;
    max++  ;
    ui->tabWidget->insertTab(max,ui->ag_mod,"Modifier") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->ag_supp,"Supprimer") ;
    max++ ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->menu_ag)) ;



}

void MainWindow::on_but_ag_ajou_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->aj_ajout))  ;
}

void MainWindow::on_but_ag_affi_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_aff)) ;
}

void MainWindow::on_but_ag_mod_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_mod)) ;
}

void MainWindow::on_but_adm_sup_2_clicked()
{
      ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_supp)) ;
}

void MainWindow::on_but_adm_home_7_clicked()
{
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;

    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;
    ui->tabWidget->addTab(ui->adm_menu,"Home") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_menu)) ;
}

void MainWindow::on_but_adm_ajou_7_clicked()
{
    ui->tabWidget->addTab(ui->ag_stat,"Statistique") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_stat)) ;
}

void MainWindow::on_menu_emp_clicked()
{
    employer e ;
    //agence ag ;
    //e.afficher() ;
     ui->adm_tab_aff->setModel(e.afficher());

    max=0 ;
    ui->tabWidget->removeTab(max)  ;
    ui->tabWidget->insertTab(max,ui->adm_emp,"Home") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_ajout,"Ajouter");
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_affi,"Afficher") ;
    max++  ;
    ui->tabWidget->insertTab(max,ui->adm_mod,"Modifier") ;
    max++ ;
    ui->tabWidget->insertTab(max,ui->adm_sup,"Supprimer") ;
    max++ ;
}

void MainWindow::on_but_adm_ajou_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_ajout)) ;
}

void MainWindow::on_but_adm_affi_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_affi)) ;
}

void MainWindow::on_but_adm_mod_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_mod)) ;
}

void MainWindow::on_but_adm_sup_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_sup)) ;
}

void MainWindow::on_but_adm_home_8_clicked()
{
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_profil))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_assurence))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->em_reclamation))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_ajout))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_affi))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_emp))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_mod))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_sup))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->adm_assur))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->menu_ag))  ;
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->aj_ajout))  ;

     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_aff))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_mod))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_supp))  ;
     ui->tabWidget->removeTab(ui->tabWidget->indexOf(ui->ag_stat))  ;
     ui->tabWidget->addTab(ui->adm_menu,"Home") ;
     ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_menu)) ;
}

void MainWindow::on_assurence_8_clicked()
{
    ui->tabWidget->addTab(ui->adm_assur,"Assurence") ;
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->adm_assur)) ;
}

void MainWindow::on_assurence_clicked()
{
    if (ass==true ) {
       ui->tabWidget->addTab(ui->em_assurence,"Assurence") ;
    ass=false ;
    }
       ui->tabWidget->setCurrentIndex( ui->tabWidget->indexOf(ui->em_assurence) )   ;
}

void MainWindow::on_reclamation_clicked()
{
    if (rec==true ) {
        ui->tabWidget->addTab(ui->em_reclamation,"Reclamation") ;
    rec=false ;
    }
    ui->tabWidget->setCurrentIndex( ui->tabWidget->indexOf(ui->em_reclamation) )   ;
}

void MainWindow::on_btn_ajouter_clicked()
{


    if(ui->adm_aj_cin->text().isEmpty()||ui->adm_aj_salaire->text().isEmpty()||ui->adm_aj_nom->text().isEmpty()|| ui->adm_aj_prenom->text().isEmpty() ||ui->adm_aj_poste->text().isEmpty() ) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
        QObject::tr("Information incomplete.\n""Click Cancel to exit."), QMessageBox::Cancel);
}


   else {

       int count=0 ;
        QSqlQuery query ;
        query.prepare("SELECT * FROM  TABLE1 where CIN = :cin ");

        query.bindValue(":cin", ui->adm_aj_cin->text().toInt() );

        if(query.exec())

        {


            while(query.next())

            {

                count++;

            }

            if(count!=0)

            {

                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr(" CIN existe deja !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }

            if(count==0 )

            {
                int cin=ui->adm_aj_cin->text().toInt() ;
                int salaire=ui->adm_aj_salaire->text().toInt() ;
                QString nom=ui->adm_aj_nom->text() ;
                QString prenom=ui->adm_aj_prenom->text() ;
                QString poste=ui->adm_aj_poste->text()  ;
                QString etat=ui->adm_aj_combo_etat->currentText() ;
                int nombre=ui->adm_aj_spin_nbrenfant->value() ;
                QDateTime time ;
                QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text()+ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
                QString adresse=nom+"."+prenom+".factory@gamil.com" ;





                employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;





                 if(e.ajouter()) {
                     QMessageBox::information(nullptr, QObject::tr("OK "),
                     QObject::tr(" Employer ajouter avec succes ok.\n""Click Cancel to exit."), QMessageBox::Cancel);
                     ui->adm_tab_aff->setModel(e.afficher());
                 }
                 else {
                     QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("Probleme de conixion.\n""Click Cancel to exit."), QMessageBox::Cancel);

                 }


            }



        }



    }
     // afficher() ;
     // ui->adm_tab_aff->setModel(afficher());

      /*if(test)
    {

          ui->tabetudiant->setModel(tmpetudiant.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                    QObject::tr("Etudiant ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
                                  */
}



void MainWindow::on_btn_adm_supp_clicked()
{
   if(ui->adm_id_supp->text().isEmpty()) {

       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                   QObject::tr("Information incomplete !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
   }

   else {



           QSqlQuery query;


       int count =0;

           query.prepare("SELECT * FROM  TABLE1 where CIN = :cin ");

           query.bindValue(":cin", ui->adm_id_supp->text().toInt());

           if(query.exec())

           {


               while(query.next())

               {

                   count++;

               }

               if(count!=0)

               {

                     employer e ;
                    int id=ui->adm_id_supp->text().toUInt() ;
                     if(e.supprimer(id))  {



                         QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("employe supprimer avec succes !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                     ui->adm_tab_aff->setModel(e.afficher());
                     }
                     else {
                         QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                         QObject::tr("Probleme de conixion !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);


                     }

               }

               if(count==0 )

               {

                   QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                   QObject::tr("CIN NOT FOUND !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }



           }



}
   }

void MainWindow::on_btn_adm_load_clicked()
{
    employer e ;
    QSqlQueryModel *modal=new QSqlQueryModel() ;
    QSqlQuery query ;
    query.prepare("SELECT CIN  FROM TABLE1") ;
    if (query.exec()&&query.next()) {
        modal->setQuery(query) ;
        ui->adm_list_view->setModel(modal) ;
        ui->adm_combobox_aff->setModel(modal) ;



    }
}

void MainWindow::on_adm_combobox_aff_currentIndexChanged(const QString &arg1)
{
  //arg1="ross" ;
    QSqlQuery query ;
    query.prepare("SELECT *  FROM TABLE1 WHERE CIN=:cin") ;
    query.bindValue(":cin",ui->adm_combobox_aff->currentText() ) ;
    if (query.exec()&&query.next()) {
    ui->adm_aj_cin_2->setText(query.value(0).toString() );
    ui->adm_aj_nom_2->setText(query.value(1).toString() );
    ui->adm_aj_prenom_2->setText(query.value(2).toString() );
    ui->adm_aj_salaire_2->setText(query.value(3).toString() );
    ui->adm_aj_poste_2->setText(query.value(4).toString() );
     if(query.value(5).toString()=="MARRIED"){
    ui->adm_mod_aff_combo_etat->setCurrentIndex(1) ;
    }
     else
      ui->adm_mod_aff_combo_etat->setCurrentIndex(0) ;
    ui->adm_aj_spin_nbrenfant_2->setValue(query.value(6).toInt()) ;
 }
}

void MainWindow::on_btn_ajouter_2_clicked()
{

if (ui->adm_aj_nom_2->text().isEmpty()||ui->adm_aj_prenom_2->text().isEmpty()||ui->adm_aj_salaire_2->text().isEmpty()||ui->adm_aj_poste_2->text().isEmpty()) {
    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("inforamation incomplete !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else {

    QSqlQuery query ;
    QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text()+ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+".factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

    query.prepare("UPDATE  TABLE1 SET  NOM=:nom, PRENOM=:prenom,SALAIRE=:salaire,POSTE=:poste,ETAT=:etat,NOMBRE=:nombre,ADRESSE=:adresse,PASSE=:passe WHERE CIN=:cin ");

    query.bindValue(":cin",ui->adm_aj_cin_2->text().toInt());
    query.bindValue(":nom", ui->adm_aj_nom_2->text());
    query.bindValue(":prenom",ui->adm_aj_prenom_2->text());
    query.bindValue(":salaire", ui->adm_aj_salaire_2->text().toInt());
    query.bindValue(":poste",ui->adm_aj_poste_2->text());
    query.bindValue(":etat",ui->adm_mod_aff_combo_etat->currentText());
    query.bindValue(":nombre",ui->adm_aj_spin_nbrenfant_2->value());
    query.bindValue(":adresse",adresse);
    query.bindValue(":passe",passe);

if(query.exec()) {

    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("SUCCES,OK  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
employer e ;
 ui->adm_tab_aff->setModel(e.afficher());
}
else {
    QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("Probleme de conixion ,  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
//query.next() ;
 }
}

void MainWindow::on_btn_ag_aj_clicked()
{

    if(ui->ag_aj_id->text().isEmpty()|| ui->ag_aj_nom->text().isEmpty()||  ui->ag_aj_adresse->text().isEmpty()|| ui->ag_aj_cin->text().isEmpty() ) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("information  incomplete,OK  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

    else {
        int count=0 ;
         QSqlQuery query ;
         query.prepare("SELECT * FROM  AGENCE where ID = :id ");

         query.bindValue(":id", ui->ag_aj_id->text()  );

         if(query.exec())

         {


             while(query.next())

             {

                 count++;

             }

             if(count!=0)

             {

                 QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                 QObject::tr(" ID existe deja !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }

             if(count==0 )

             {

                 QString id=ui->ag_aj_id->text() ;
                 QString nom=ui->ag_aj_nom->text();
                 QString adresse=ui->ag_aj_adresse->text();
                 QDate date=ui->ag_aj_dateEdit->date() ;
                 int nbr_emp=ui->aj_ag_spinBox_nbremp->value()  ;
                 int  cin_d=ui->ag_aj_cin->text().toInt() ;
                 int  nbr_v=ui->aj_ag_spinBox_nb_vente->text().toInt() ;
                 QDateTime time ;

                 //QString passe= ui->adm_aj_cin->text()+ui->adm_aj_spin_nbrenfant->text();
                 //QString adresse=nom+"."+prenom+"_factory@gamil.com" ;

                 //employer e(cin,nom,prenom,poste,etat,adresse,passe,salaire,nombre) ;
             agence ag(id,nom,adresse,date,nbr_emp,cin_d,nbr_v) ;

             if (ag.ajouter() ) {
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Agence ajouter avec succès ,OK  !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

              ui->ag_tab_aff->setModel(ag.afficher());
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr(" Erreur"),
                             QObject::tr("Probeleme de conixion ,OK  !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }




                  }



    }
    }
}

void MainWindow::on_btn_adm_supp_2_clicked()
{
    agence ag ;
    QString id=ui->ag_id_supp->text() ;
     ag.supprimer(id) ;

}

void MainWindow::on_btn_ag_supp__clicked()
{
   if(ui->ag_id_supp->text().isEmpty()) {
       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                   QObject::tr(" ID VIDE !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else {

       int count=0 ;
        QSqlQuery query ;
        query.prepare("SELECT * FROM  AGENCE where ID = :id ");

        query.bindValue(":id", ui->ag_id_supp->text() );

        if(query.exec())

        {


            while(query.next())

            {

                count++;

            }

            if(count!=0)

            {
                agence ag ;
             QString id=ui->ag_id_supp->text() ;
            if(  ag.supprimer(id))  {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Agence supprimer avec succes !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                           ui->ag_tab_aff->setModel(ag.afficher());
            }
            else {
                            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                            QObject::tr("probleme de conixion !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }

            }

            if(count==0 )

            {
                QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                QObject::tr("ID nexiste pas  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
            }


            }










   }


}

void MainWindow::on_btn_ag_load_clicked()
{


    agence ag ;
    QSqlQueryModel *modal=new QSqlQueryModel() ;
    QSqlQuery query ;
    query.prepare("SELECT ID  FROM AGENCE ") ;
    if (query.exec()&&query.next()) {
        modal->setQuery(query) ;
        ui->ag_list_view->setModel(modal) ;
        ui->ag_combobox_aff->setModel(modal) ;
}
}

void MainWindow::on_ag_combobox_aff_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query ;
    query.prepare("SELECT *  FROM AGENCE WHERE ID=:id") ;
    query.bindValue(":id",ui->ag_combobox_aff->currentText()  ) ;
    if (query.exec()&&query.next()) {
    ui->ag_aj_id_2->setText(query.value(0).toString() );
    ui->ag_aj_nom_2->setText(query.value(1).toString() );
    ui->ag_aj_adresse_2->setText(query.value(2).toString() );
    ui->ag_aj_dateEdit_2->setDate(query.value(3).toDate() );
    ui->aj_ag_spinBox_nbremp_2->setValue(query.value(4).toInt() );
    ui->aj_ag_spinBox_nb_vente_2->setValue(6) ;
    ui->ag_aj_cin_2->setText(query.value(5).toString()) ;

}
}

void MainWindow::on_pushButton_2_clicked()
{

    if (ui->ag_aj_nom_2->text().isEmpty()||ui->ag_aj_adresse_2->text().isEmpty()||ui->ag_aj_cin_2->text().isEmpty() ) {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr(" Inforamation incomplete !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {

    QSqlQuery query ;
    //QString passe= ui->adm_aj_cin_2->text()+ui->adm_aj_spin_nbrenfant_2->text();
    //QString adresse=ui->adm_aj_nom_2->text()+"."+ui->adm_aj_prenom_2->text()+"_factory@gamil.com" ;

    //query.prepare("UPDATE  TABLE1 SET CIN='" +  ui->adm_aj_cin_2->text() + "' ,NAME='"+ ui->adm_aj_nom_2->text()+"' ,PRENOM= '"+ui->adm_aj_prenom_2->text()+"' ,SALAIRE='"+ui->adm_aj_salaire_2->text().toInt()+"',POSTE'"+ui->adm_aj_poste_2->text()+"',ETAT='"+ui->adm_mod_aff_combo_etat->currentText()+"',NOMBRE='"+ ui->adm_aj_spin_nbrenfant_2->value()+"',PASSE= '"+passe+ "',ADRESSE='"+adresse+ "' WHERE ,CIN='"+ui->adm_aj_cin_2->text() +"'") ;

     query.prepare("UPDATE  AGENCE SET  ID=:id, NOM=:nom,ADRESSE=:adresse,D=:d,EMPLOYER=:employer,DIRECTEUR=:directeur,VENTE=:vente WHERE ID=:cin");
     query.bindValue(":cin",ui->ag_aj_id_2->text()) ;
    query.bindValue(":id", ui->ag_aj_id_2->text());
    query.bindValue(":nom", ui->ag_aj_nom_2->text());
    query.bindValue(":adresse",ui->ag_aj_adresse_2->text());
    query.bindValue(":d", ui->ag_aj_dateEdit_2->date());
    query.bindValue(":employer", ui->aj_ag_spinBox_nbremp_2->text().toInt());
    query.bindValue(":directeur",ui->ag_aj_cin_2->text().toInt());
    query.bindValue(":vente",ui->aj_ag_spinBox_nb_vente_2->text().toInt());


    if(query.exec()) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr(" Agence modifier avec succes !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        agence ag ;
        ui->ag_tab_aff->setModel(ag.afficher());
 }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Probleme de conixion !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    }
}

void MainWindow::on_btn_adm_tri_aff_clicked()
{    QSqlQueryModel *model=new QSqlQueryModel() ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    ui->adm_tab_aff->setModel(model) ;
    QSqlQuery query ;
     if (ui->comboBox->currentText()=="CIN")
     query.prepare("SELECT *  FROM TABLE1 ORDER BY CIN ASC ") ;
else
         if (ui->comboBox->currentText()=="NOM")
         query.prepare("SELECT *  FROM TABLE1 ORDER BY NOM ASC ") ;
  else
             if (ui->comboBox->currentText()=="SALAIRE")
             query.prepare("SELECT *  FROM TABLE1 ORDER BY SALAIRE ASC ") ;

    if (query.exec()&&query.next()) {
        model->setQuery(query) ;

        ui->adm_tab_aff->setModel(model) ;




}

}




void MainWindow::on_btn_em_rec_clicked()
{
//QString a ;

//qDebug()<<(ui->textEdit->document()->isEmpty()) ;

if(ui->textEdit->document()->isEmpty()) {

     QMessageBox::critical(nullptr, QObject::tr("MAIL Denied"),
     QObject::tr("Desole le mail est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);
 }
else {
    // This is a first demo application of the SmtpClient for Qt project


    // First we need to create an SmtpClient object
    // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // We need to set the username (your email address) and password
    // for smtp authentification.

    smtp.setUser(ui->log_add->text());
    smtp.setPassword(ui->logpass->text());

    // Now we create a MimeMessage object. This is the email.

    MimeMessage message;
    QString name =ui->adm_aj_nom->text() ;
    EmailAddress sender(ui->log_add->text(), name );
    message.setSender(&sender);

    EmailAddress to("ros.ch.factory@gmail.com", "Recipient's Name");
    message.addRecipient(&to);

    message.setSubject("RECLAMATION");

    // Now add some text to the email.
    // First we create a MimeText object.

    MimeText text;

    text.setText(ui->textEdit->toPlainText());

    // Now add it to the mail

    message.addPart(&text);

    // Now we can send the mail

    if (!smtp.connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;

    }

    if (!smtp.login()) {
        qDebug() << "Failed to login!" << endl;

    }

    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        QMessageBox::information(nullptr, QObject::tr("MAILING"),
        QObject::tr(" Erreur .\n""Click Cancel to exit."), QMessageBox::Cancel);


    }
    else {
        QMessageBox::information(nullptr, QObject::tr("OK"),
        QObject::tr("Mail envoye .\n""Click Cancel to exit."), QMessageBox::Cancel);

    }

    smtp.quit();

}

}

void MainWindow::on_but_adm_ajou_stat_clicked()
{
 int pos=0 ;
    QChart *chart = new QChart();

      QPieSeries *series = new QPieSeries();

      QSqlQuery query ;
     query.prepare("select * from AGENCE ") ;
     if(query.exec()) {
         while(query.next()){
     series->append(query.value(1).toString(), query.value(6).toInt());
     QPieSlice *slice = series->slices().at(pos);
     //slice->setExploded(true);
     slice->setLabelVisible(true);
     pos++ ;

         }
}




       chart->setTheme( QChart::ChartThemeDark);

       chart->setAnimationOptions(QChart::AllAnimations);

       chart->setAnimationDuration(2000);

       chart->setAnimationEasingCurve(QEasingCurve::InOutBounce);

                  chart->setTitle("nombre de produit");

                  QChartView *chartview = new QChartView(chart);

                  chartview->setParent(ui->horizontalFrame);

               //   chartview->setBaseSize(300,300);

                  chartview->setGeometry(-100,-180,981,821);


       chart->addSeries(series);
       chart->setTitle("NOMBRE DE VANETE");

       chartview->setParent(ui->horizontalFrame);




       ui->tabWidget->addTab(ui->ag_stat,"Statistique") ;
       ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->ag_stat)) ;




}



void MainWindow::on_btn_ag_export_3_clicked()
{

}

void MainWindow::on_btn_ag_export_clicked()
{
    QString strStream;

                 QTextStream out(&strStream);


                 const int rowCount = ui->ag_tab_aff->model()->rowCount();

                 const int columnCount = ui->ag_tab_aff->model()->columnCount();


                 out <<  "<html>\n"

                     "<head>\n"

                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                     <<  QString("<title>%1</title>\n").arg("strTitle")

                     <<  "</head>\n"

                     "<body bgcolor=#ffffff link=#5000A0>\n"


                    //     "<align='right'> " << datefich << "</align>"

                     "<center> <H1>Liste des Agences </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


                 // headers

                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                 for (int column = 0; column < columnCount; column++)

                     if (!ui->ag_tab_aff->isColumnHidden(column))

                         out << QString("<th>%1</th>").arg(ui->ag_tab_aff->model()->headerData(column, Qt::Horizontal).toString());

                 out << "</tr></thead>\n";


                 // data table

                 for (int row = 0; row < rowCount; row++) {

                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                     for (int column = 0; column < columnCount; column++) {

                         if (!ui->ag_tab_aff->isColumnHidden(column)) {

                             QString data = ui->ag_tab_aff->model()->data(ui->ag_tab_aff->model()->index(row, column)).toString().simplified();

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

void MainWindow::on_btn_ag_imprimer_clicked()
{
    QPrinter printer;


    printer.setPrinterName("desiered printer name");


  QPrintDialog dialog(&printer,this);


    if(dialog.exec()== QDialog::Rejected)


        return;
}
