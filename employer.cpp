#include "employer.h"

employer::employer()
{

}
employer:: employer(int a ,QString z, QString e,QString r,QString t,QString y ,QString u ,float i, int o)  {
    cin=a ;
    nom=z;
    prenom=e;
    poste=r;
    etat=t;
    adresse=y;
    passe=u;
    salire=i;
    nombre=o ;

}

bool employer::ajouter( )
{
QSqlQuery query;
QString res= QString::number(getcin());
query.prepare("INSERT INTO TABLE1 (CIN, NOM, PRENOM,SALAIRE,POSTE,ETAT,NOMBRE,ADRESSE,PASSE) "
                   "VALUES (:cin, :nom, :prenom,:salaire,:poste,:etat,:nombre,:adresse,:passe)");
query.bindValue(":cin",res );
query.bindValue(":nom",getnom());
query.bindValue(":prenom",getprenom());
query.bindValue(":salaire", getsalaire());
query.bindValue(":poste",getposte());
query.bindValue(":etat",getetat());
query.bindValue(":nombre",getnombre());
query.bindValue(":adresse",getadresse());
query.bindValue(":passe",getpasse());
return    query.exec();
}
QSqlQueryModel * employer::afficher()
{
QSqlQueryModel * model= new QSqlQueryModel();


model->setQuery("select * from TABLE1 ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));


    /*
QSqlQuery *a= new QSqlQuery ()  ;
//a->setQuery("select * from TABLE1");

QString sQuery = QString("SELECT  Matricule FROM Projet.dbo.Produit WHERE CIN='%1' ") ;

          QSqlQuery query;

      query.exec( sQuery );

           QString name = query.value(0).toString();

           ui->aff_cin->setText(name);
    if (log!=0){
model->setQuery("select * from TABLE1 ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
//ui->lineEdit->setText(em.getF_name()) ;
//ui->lineEdit_2->setText(em.getL_name()) ;
//ui->lineEdit_3->setText(em.getADRESSE()) ;
//ui->dateEdit->setDate(em.getDATE()) ;*/
    return  model ;
}

            /*

 query.prepare("SELECT NOM FROM TABLE1 ");

//query.bindValue(":nom", ui->comboBox->currentText());


    ui->aff_nom->setText(query.value(1).toString());

 else {
    QSqlQuery query;
    query.prepare("SELECT  NOM FROM TABLE1 WHERE AGE=:nom");
    query.bindValue(":nom", "15");
    if (query.exec() && query.next()) {
    ui->aff_nom->setText(query.value(0).toString() );
    //query.value(0).toString()=="5" ;
    }

}
    return  model;

}*/
bool employer::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from TABLE1 where CIN = :id ");
query.bindValue(":id", res);
return    query.exec();
}
