#include "client.h"
#include <QPrinter>
#include <QPainter>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
Client::Client()
{

}
 Client::Client(QString cn,QString nm,QString pr,QString ach,QString pm,QString md,QString dt)
 {
     cin=cn;
      nom=nm;
      prenom=pr;
      achat=ach;
      paiement=pm;
      model_choisi=md;
      date_naissance=dt;
 }

 bool Client::ajouter()
 {
     QSqlQuery query;
           query.prepare("INSERT INTO client (cin,prenom,nom,model,achat,paiement,date_naissance)"
                         "VALUES (:cin, :prenom, :nom, :model_choisi, :achat, :paiement, :date_naissance)");
           query.bindValue(":cin", cin);
           query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
            query.bindValue(":achat", achat);
            query.bindValue(":paiement", paiement);
             query.bindValue(":model_choisi", model_choisi);  
            query.bindValue(":date_naissance",date_naissance);
       return   query.exec();



 }

 QSqlQueryModel* Client::afficher()
 {
     QSqlQueryModel *model =new QSqlQueryModel();
     model->setQuery("select * from Client");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("model_choisi"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("achat"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("paiement"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date_naissance"));
    return model;

 }

 QSqlQueryModel *Client::rechercherclient(QString CIN,QString NOM,QString PRENOM)
 {
     QSqlQueryModel *model = new QSqlQueryModel();
         QSqlQuery query;

 int count =0;
         query.prepare("select * from client where CIN= :CIN or NOM = :NOM or PRENOM =:PRENOM ");
         query.bindValue(":CIN", CIN);
         query.bindValue(":NOM", NOM);
         query.bindValue(":PRENOM", PRENOM);


         if(query.exec())
         {

             while(query.next())
             {
                 count++;
             }
             if(count==1)
             {
                 QMessageBox msgBox;
                 msgBox.setText(" fOUND");
                 msgBox.exec();
                model->setQuery(query);
             }
             if(count<1 )
             {
                 QMessageBox msgBox;
                 msgBox.setText("NOT fOUND");
                 msgBox.exec();
                 model=0;
             }


         }

         return model;
 }
bool Client::supprimer(QString CIN)
{
    QSqlQuery query;

    query.prepare("delete from Client where CIN=:cin");
    query.bindValue(":cin",CIN);
    return query.exec();
}

bool Client::modifier(QString CIN)
{
    QSqlQuery query;

          query.prepare("update client set nom='"+nom+"',prenom='"+prenom+"',model='"+model_choisi+"',achat='"+achat+"',paiement='"+paiement+"',date_naissance='"+date_naissance+"' where CIN=:cin");
         query.bindValue(":cin", CIN);

      return   query.exec();


}


bool Client::exporterpdf()
{


    QPrinter printer;
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("C:/Users/eyaou/Desktop/Smart_Factory_2A4/fichier.pdf");
          QPainter painter;
          if (! painter.begin(&printer)) { // failed to open file
              qWarning("failed to open file, is it writable?");
              return 1;
          }
          painter.drawText(10, 10,"le montant de votre facture est :");
          if (! printer.newPage()) {
              qWarning("failed in flushing page to disk, disk full?");
              return 1;
          }
          painter.drawText(10, 10, "Test 2");
          painter.end();

}


