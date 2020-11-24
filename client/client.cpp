#include "client.h"

Client::Client()
{

}
 Client::Client(QString cn,QString nm,QString pr,QString ach,QString pm,QString md,QDate dt)
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

          query.prepare("update client set nom='"+nom+"',prenom='"+prenom+"',model='"+model_choisi+"',achat='"+achat+"',paiement='"+paiement+"' where CIN=:cin");
         query.bindValue(":cin", CIN);

      return   query.exec();


}
