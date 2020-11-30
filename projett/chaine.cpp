#include "chaine.h"


chaine::chaine()
{
    type_produit="";
    reference=0;
    nb_machine=0;
}

chaine::chaine(int r,int n,QString t)
{
       type_produit=t;
       reference=r;
       nb_machine=n;
}

bool chaine::ajouter()
 {
     QSqlQuery query;
     QString res = QString::number(reference);
     query.prepare("INSERT INTO chaine(reference,nb_machine,type_produit)"
                   "VALUES (:reference,:nb_machine,:type_produit)");
     query.bindValue(":type_produit",type_produit);
     query.bindValue(":reference",res);
     query.bindValue(":nb_machine",nb_machine);
     return query.exec();

 }



  QSqlQueryModel *chaine::afficher()
  {
      QSqlQueryModel * model=new QSqlQueryModel();
      model->setQuery("select* from chaine");

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nb_machine"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("type_produit"));
      return  model;
  }




  bool chaine::supprimer(int REFERENCE)
   {
       QSqlQuery query;
       QString res = QString::number(REFERENCE);
       query.prepare("Delete from CHAINE where REFERENCE=:REFERENCE");
       query.bindValue(":REFERENCE",res);
       return query.exec();
   }




  QSqlQueryModel *chaine::load_ch()
    {
        QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select* from chaine");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
        return model;
    }
