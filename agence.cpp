#include "agence.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
agence::agence()
{

}
agence::agence(QString a,QString z,QString e,QDate r,int t,int y,int u) {
    id=a ;
    nom=z ;
    adresse=e ;
    date_creation=r ;
    nb_emp=t;
    cin_directeur=y ;
    nb_vente=u ;

   }

bool agence:: ajouter() {

    //bool employer::ajouter( )
    //{
    QSqlQuery query;
    QString res= getid();
    query.prepare("INSERT INTO AGENCE (ID, NOM,ADRESSE,D,EMPLOYER,DIRECTEUR,VENTE) "
                       "VALUES (:id, :nom, :adresse,:date,:nbr_emp,:cin_d,:nbr_v)");
    query.bindValue(":id",res );
    query.bindValue(":nom",getnom());
    query.bindValue(":adresse",getadresse());
    query.bindValue(":date", getdate_creation());
    query.bindValue(":nbr_emp",getnb_emp());
    query.bindValue(":cin_d",getcin_directeur());
    query.bindValue(":nbr_v",getnb_vente());
    //query.bindValue(":adresse",getadresse());
    //query.bindValue(":passe",getpasse());
  return    query.exec();
    }

QSqlQueryModel * agence:: afficher()
{

QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select * from AGENCE ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
return  model ;
}

bool agence::supprimer(QString idd)
{
QSqlQuery query,query2;
query.prepare("Delete from AGENCE where ID =:id ");
query.bindValue(":id",idd );
return  query.exec();
}
