#ifndef AGENCE_H
#define AGENCE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class agence
{
public:
    agence();
private:
   QString nom,adresse,id   ;
   QDate date_creation ;
    int nb_emp ,nb_vente ,cin_directeur ;
public :
    void setnom(QString nv_nom) {nom=nv_nom;} ;
    void setadresse(QString nv_adresse) {adresse=nv_adresse;} ;
    void setid(QString nv_id) {id=nv_id;} ;
    QString getnom(){return nom ;  } ;
    QString getadresse(){return adresse  ;  } ;
    QString getid(){return id ;  } ;
    void setdate(QDate nv_date) {date_creation=nv_date;} ;
    void setnb_emp( int nv_nb_emp) {nb_emp=nv_nb_emp;} ;
    void setnb_vente(int nv_nb_vente) {nb_vente=nv_nb_vente;} ;
   QDate getdate_creation(){return date_creation ;  } ;
   int getnb_vente(){return nb_vente ;  } ;
   int getnb_emp(){return nb_emp ;  } ;
   void setnb_cin_directeur(int nv_cin_directeur) {cin_directeur=nv_cin_directeur;} ;
   int getcin_directeur(){return  cin_directeur;} ;
   agence(QString,QString,QString,QDate,int,int,int) ;
   bool ajouter();
  QSqlQueryModel * afficher();
    bool supprimer(QString);
};

#endif // AGENCE_H
