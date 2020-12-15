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

  QSqlQueryModel * chaine::trier(int test)

  {

               QSqlQueryModel *model=new QSqlQueryModel() ;

               QSqlQuery query ;



               model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));

               model->setHeaderData(1, Qt::Horizontal, QObject::tr("NB_MACHINE "));

               model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_PRODUIT"));



               if(test==1)

               {

                   query.prepare("SELECT *  FROM chaine ORDER BY REFERENCE ASC ") ;

               }

               else if(test==2)

               {

                   query.prepare("SELECT *  FROM chaine ORDER BY NB_MACHINE ASC ") ;

               }

               else if(test==3)

               {

                    query.prepare("SELECT *  FROM chaine ORDER BY TYPE_PRODUIT ASC ") ;

               }



               if (query.exec()&&query.next())

               {

                   model->setQuery(query) ;

               }
               return model;


}

  bool chaine::modifier()
  {
      QSqlQuery query;
       query.prepare("update CHAINE SET  NB_MACHINE=:NB_MACHINE , TYPE_PRODUIT=:TYPE_PRODUIT where REFERENCE=:REFERENCE");
       query.bindValue(":TYPE_PRODUIT",type_produit);
       query.bindValue(":REFERENCE",reference);
       query.bindValue(":NB_MACHINE",nb_machine);
       return query.exec();  }
