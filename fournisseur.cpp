#include "fournisseur.h"
#include <QMessageBox>

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(QString cn,QString nm,QString prn,QString pdm,QString nbp,QString pr,QDate dl)
{
    nom=nm;
    cin=cn;
    prenom=prn;
    piece_demandee=pdm;
    nbre_piece=nbp;
    prix_apayer=pr;
    dateLimite=dl;

}


bool fournisseur::ajouterFour()
{
    QSqlQuery query;
          query.prepare("INSERT INTO fournisseur (cin, nom ,prenom,piece_demandee,nbre_piece,prix_apayer,dateLimite)"
                        "VALUES (:cin, :nom, :prenom,  :piece_demandee, :nbre_piece,  :prix_apayer, :dateLimite)");
          query.bindValue(":cin", cin);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
           query.bindValue(":prix_apayer", prix_apayer);
            query.bindValue(":piece_demandee",piece_demandee );
             query.bindValue(":nbre_piece", nbre_piece);
              query.bindValue(":dateLimite",dateLimite);
      return   query.exec();



}

QSqlQueryModel * fournisseur::afficherFour()
{
    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("select * from Fournisseur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("piece_demandee"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("nbre_piece"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix_apayer"));
   model->setHeaderData(6,Qt::Horizontal,QObject::tr("dateLimite"));
   return model;

}
bool fournisseur::supprimerFour(QString CIN)
{
   QSqlQuery query;

   query.prepare("delete from fournisseur where CIN=:cin");
   query.bindValue(":cin",CIN);
   return query.exec();
}

bool fournisseur::modifierFour(QString CIN)
{
   QSqlQuery query;
    query.prepare("update fournisseur set nom=:nom,prenom=:prenom,piece_demandee=:piece_demandee,nbre_piece=:nbre_piece,prix_apayer=:prix_apayer,datelimite=:dateLimite where CIN=:cin");
    query.bindValue(":cin",CIN);
    return query.exec();
}
QSqlQueryModel * fournisseur::trier(int test)
{

    QSqlQueryModel *model=new QSqlQueryModel() ;
     QSqlQuery query ;
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    if(test==1)
    {
        query.prepare("SELECT *  FROM FOURNISSEUR ORDER BY CIN ASC ") ;
    }
    else if(test==2)
    {
        query.prepare("SELECT *  FROM FOURNISSEUR ORDER BY NOM ASC ") ;

    }
    else if(test==3)
    {
        query.prepare("SELECT *  FROM FOURNISSEUR ORDER BY PRENOM ASC ") ;

    }
    if (query.exec()&&query.next()) {
        model->setQuery(query) ;}
    return model;
}

QSqlQueryModel *fournisseur::rechercherfournisseur(QString CIN,QString NOM,QString PRENOM)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;

int count =0;
        query.prepare("select * from fournisseur where CIN= :CIN or NOM = :NOM or PRENOM =:PRENOM ");
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
                msgBox.setText(" trouvé");
                msgBox.exec();
               model->setQuery(query);
            }
            if(count<1 )
            {
                QMessageBox msgBox;
                msgBox.setText("non trouvé");
                msgBox.exec();
                model=0;
            }


        }

        return model;
}
