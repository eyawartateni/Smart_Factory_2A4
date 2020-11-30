     #include "voiture.h"

voiture::voiture()
{

}
voiture::voiture(QString m,int r,QString mo,int p,QString t,int po,QString c,QString o)
{
    this->marque=m;
    this->modele=mo;
    this->type=t;
    this->options=o;
    this->couleur=c;
    this->prix=p;
    this->prix_option=po;
  this->reference=r;

}
bool voiture::ajouter()
{
    QSqlQuery query;
   QString res = QString::number(reference);
    query.prepare("INSERT INTO voiture1(reference,marque,modele,prix,type,prix_option,couleur,options)"
                  "VALUES (:reference,:marque,:modele,:prix,:type,:prix_option,:couleur,:options)");
    query.bindValue(":marque",marque);
     query.bindValue(":reference",res);
    query.bindValue(":modele",modele);
     query.bindValue(":prix",prix);
    query.bindValue(":type",type);
      query.bindValue(":prix_option",prix_option);
    query.bindValue(":couleur",couleur);
         query.bindValue(":options",options);

         return query.exec();
}

 QSqlQueryModel *voiture::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select* from voiture1");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("marque"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("modele"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("type"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix_option"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("option"));
     return  model;

 }




bool voiture::supprimer(int reference)
 {
     QSqlQuery query;
     QString res = QString::number(reference);
     query.prepare("Delete from voiture1 where reference=:reference");
     query.bindValue(":reference",res);
     return query.exec();
 }


 QSqlQueryModel *voiture::load()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select* from voiture1");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
     return model;
 }

    QSqlQueryModel *voiture::recherche(QString REFERENCE,QString MARQUE,QString MODELE)
 {
        QSqlQuery query;
      QSqlQueryModel *model = new QSqlQueryModel();
      int count =0;
      query.prepare("SELECT *from VOITURE1 where REFERENCE=:REFERENCE or MODELE=:MODELE or MARQUE=:MARQUE");
      query.bindValue(":REFERENCE",REFERENCE);
      query.bindValue(":MODELE",MODELE);
      query.bindValue(":MARQUE",MARQUE);
      if(query.exec())
      {
        while(query.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox msgBox;
            msgBox.setText("found");
             msgBox.exec();
             model->setQuery(query);
        }
        else
        if(count<1)
        {
            QMessageBox msgBox;
            msgBox.setText("not found");
             msgBox.exec();
             model=0;
        }
      }
      return model;
  }

    /*bool voiture::modifier()
    {
         QSqlQuery query;
           query.prepare("update VOITURE1 SET  MARQUE=:marque, MODELE=:modele, PRIX=:prix ,TYPE=:type,PRIX_OPTION=:prix_option,COULEUR=:couleur, OPTIONS=:options where REFERENCE=:reference");

    }*/






