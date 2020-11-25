#include "assurance.h"

Assurance::Assurance(QString compagnie,int Prix,QString type,int Reference)
{
    this->compagnie=compagnie;
    this->type=type;
    reference=Reference;
    prix=Prix;
}

bool Assurance::ajouter()
{

    QSqlQuery query;
    QString res = QString::number(reference);
          query.prepare("INSERT INTO ASSURANCE (COMPAGNIE, TYPE, PRIX, REFERENCE) "
                        "VALUES (:compagnie, :type, :prix, :reference)");
          query.bindValue(":compagnie",compagnie);
          query.bindValue(":type", type);
          query.bindValue(":prix",prix);
          query.bindValue(":reference", reference);
          return query.exec();
}

QSqlQueryModel * Assurance::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from assurance");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("compagnie"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));

    return model;
}

bool Assurance::supprimer(int reference)
{
    QSqlQuery query;
    QString res = QString::number(reference);
    query.prepare("Delete from assurance where reference=:reference");
    query.bindValue(":reference",res);
    return query.exec();


}
