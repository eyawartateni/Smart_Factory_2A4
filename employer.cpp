#include "employer.h"
#include "QMessageBox"

employer::employer()
{

}
employer:: employer(int a ,QString z, QString e,QString r,QString t,QString y ,QString u ,float i, int o,QString b)  {
    cin=a ;
    nom=z;
    prenom=e;
    poste=r;
    etat=t;
    adresse=y;
    passe=u;
    salire=i;
    nombre=o ;
    rfid=b ;

}

bool employer::ajouter( )
{
QSqlQuery query;
QString res= QString::number(getcin());
query.prepare("INSERT INTO TABLE1 (CIN, NOM, PRENOM,SALAIRE,POSTE,ETAT,NOMBRE,ADRESSE,PASSE,RFID) "
                   "VALUES (:cin, :nom, :prenom,:salaire,:poste,:etat,:nombre,:adresse,:passe,:rfid)");
query.bindValue(":cin",res );
query.bindValue(":nom",getnom());
query.bindValue(":prenom",getprenom());
query.bindValue(":salaire", getsalaire());
query.bindValue(":poste",getposte());
query.bindValue(":etat",getetat());
query.bindValue(":nombre",getnombre());
query.bindValue(":adresse",getadresse());
query.bindValue(":passe",getpasse());
query.bindValue(":rfid",rfid);
return    query.exec();


}
QSqlQueryModel * employer::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select * from TABLE1 ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));


    /*
QSqlQuery *a= new QSqlQuery ()  ;
//a->setQuery("select * from TABLE1");

QString sQuery = QString("SELECT  Matricule FROM Projet.dbo.Produit WHERE CIN='%1' ") ;

          QSqlQuery query;

      query.exec( sQuery );

           QString name = query.value(0).toString();

           ui->aff_cin->setText(name);
    if (log!=0){
model->setQuery("select * from TABLE1 ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
//ui->lineEdit->setText(em.getF_name()) ;
//ui->lineEdit_2->setText(em.getL_name()) ;
//ui->lineEdit_3->setText(em.getADRESSE()) ;
//ui->dateEdit->setDate(em.getDATE()) ;*/
return  model ;
}

            /*

 query.prepare("SELECT NOM FROM TABLE1 ");

//query.bindValue(":nom", ui->comboBox->currentText());


    ui->aff_nom->setText(query.value(1).toString());

 else {
    QSqlQuery query;
    query.prepare("SELECT  NOM FROM TABLE1 WHERE AGE=:nom");
    query.bindValue(":nom", "15");
    if (query.exec() && query.next()) {
    ui->aff_nom->setText(query.value(0).toString() );
    //query.value(0).toString()=="5" ;
    }

}
    return  model;

}*/
bool employer::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from TABLE1 where CIN = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool employer::auth(QString logpass,QString  log_add)  {

    QSqlQuery query   ;
    query.prepare("SELECT *  FROM TABLE1 WHERE PASSE=:passe AND ADRESSE=:adresse");
    query.bindValue(":passe",logpass);
    query.bindValue(":adresse", log_add) ;
  //  query.exec() ;
   if (query.exec()&&query.next()) {

       printf("heeeeeey") ;
       //     processLabel->close() ;
     //   QSound *son=new QSound(":/image/res/Welcome - Male Voice Speaks (128 kbps) (mp3cut.net)(1).wav");
        //son->play() ;
//        if(query.value(4).toString()=="administrateur") {
  //        ui->tabWidget->insertTab(max,ui->adm_menu,"Home") ;

   //}
     // else {

        /*   processLabel->close() ;
     // ui->tabWidget->insertTab(max,ui->em_profil,"Profile") ;
      ui->aff_cin->setText(query.value(0).toString() );
      ui->aff_nom->setText(query.value(1).toString() );
      ui->aff_prenom->setText(query.value(2).toString() );
      ui->aff_sal->setText(query.value(3).toString() );
      ui->aff_poste->setText(query.value(4).toString() );
       if(query.value(5).toString()=="married"){
       ui->aff_combo_etat->setCurrentIndex(2) ;
          */
//}
       //else {
         //  ui->aff_combo_etat->setCurrentIndex(1) ;
       //}
         //  ui->aff_spinBox->setValue(query.value(6).toInt()) ;

   //   }
       return  true ;
   }
   else {
     //  processLabel->close() ;
   //    ui->tabWidget->addTab(ui->ag_stat,"Login") ;
       //ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->login)) ;





        if (log_add.isEmpty()&&logpass.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
            QObject::tr("Information incomplete .\n""Click Cancel to exit."), QMessageBox::Cancel);

        }
       else if (log_add.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
            QObject::tr("Adresse est vide.\n""Click Cancel to exit."), QMessageBox::Cancel);

        }
        else if (logpass.isEmpty()) {
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
             QObject::tr("Mot de passe est vide .\n""Click Cancel to exit."), QMessageBox::Cancel);

         }
        else {

            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
            QObject::tr("Mte de passe et/ou l adresse n existe pas  .\n""Click Cancel to exit."), QMessageBox::Cancel);
        }

 return  false;
   }





 }
