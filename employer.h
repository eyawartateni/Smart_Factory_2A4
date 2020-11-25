#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employer
{
public:
    employer();
private:
    QString nom,prenom,poste,etat,adresse,passe ;
    QDate Mydate ;
   int cin ,nombre ;
   float salire;
public:

   void setnom(QString nv_nom) {nom=nv_nom;} ;
   void setprenom(QString nv_prenom) {prenom=nv_prenom;} ;
   void setposte(QString nv_poste) {poste=nv_poste;} ;
   QString getnom(){return nom ;  } ;
   QString getprenom(){return prenom ;  } ;
   QString getposte(){return poste ;  } ;
   void setetat(QString nv_etat) {etat=nv_etat;} ;
   void setadresse(QString nv_adresse) {adresse=nv_adresse;} ;
   void setpasse(QString nv_passe) {passe=nv_passe;} ;
   QString getetat(){return etat ;  } ;
   QString getadresse(){return adresse ;  } ;
   QString getpasse(){return passe ;  } ;
   int getcin(){return cin ;  } ;
   void setcin(int nv_etat) {cin=nv_etat;} ;
   int getsalaire(){return salire ;  } ;
   void setsalaire(int nv_salaire) {salire=nv_salaire;} ;
   int getnombre(){return nombre ;  } ;
   void setnombre(int nv_nombre) {nombre=nv_nombre;} ;
   employer(int,QString,QString,QString,QString,QString,QString,float,int)  ;
   bool ajouter();
   bool supprimer(int);
     QSqlQueryModel * afficher();
};



#endif // EMPLOYER_H
