#include "parking.h"
#include <QMessageBox>


Parking::Parking(int Reference, int Place, QString Nom)
{
    reference=Reference;
    place=Place;
    this->nom=Nom;
}

bool Parking::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(reference);
        query.prepare("INSERT INTO PARKING (REFERENCE, PLACE, NOM) "
                      "VALUES (:reference, :place, :nom)");
        query.bindValue(":reference",reference);
        query.bindValue(":place",place);
        query.bindValue(":nom",nom);
        return query.exec();
}

QSqlQueryModel * Parking::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from parking");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("place"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));

    return model;
}

bool Parking::supprimer(int reference)
{
    QSqlQuery query;
    QString res = QString::number(reference);
    query.prepare("Delete from parking where reference=:reference");
    query.bindValue(":reference",res);
    return query.exec();
}


QSqlQueryModel * Parking::trier(int test)
{

QSqlQueryModel *model=new QSqlQueryModel() ;

             QSqlQuery query ;
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("PLACE "));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
             if(test==1)

             {
                 query.prepare("SELECT *  FROM parking ORDER BY REFERENCE ASC ") ;
             }
             else if(test==2)
             {
                 query.prepare("SELECT *  FROM parking ORDER BY NOM ASC ") ;

             }
             else if(test==3)
             {
                  query.prepare("SELECT *  FROM parking ORDER BY PLACE ASC ") ;
             }

             if (query.exec()&&query.next())

             {
                 model->setQuery(query) ;
             }


   return model;

}

QSqlQueryModel *Parking::recherche(QString nom,int place)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int c=0;
    query.prepare("SELECT *from parking where NOM=:nom or place=:place ");
    query.bindValue(":place",place);
    query.bindValue(":nom",nom);
if(query.exec())
{
    while(query.next())
        {
           c++;
        }
    if(c==1)
    {
        model->setQuery(query);
    }
        if(c<1)
        {
            model=0;
        }
}

    return model;
}
