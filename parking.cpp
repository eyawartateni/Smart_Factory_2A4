#include "parking.h"

Parking::Parking(int Reference,int Place,QString Nom)
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
          query.bindValue(":place", place);
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
