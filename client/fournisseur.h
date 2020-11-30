#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>




class fournisseur
{
private:
    QString  cin, nom ,prenom,prix_apayer,piece_demandee,nbre_piece;

QSqlQueryModel *tmpc;
    QString dateLimite;
public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,QString,QString,QString);
   // ~fournisseur();
    void setCin(QString c){cin=c;}
    void setPrenom(QString pr){prenom=pr;}
    void setnom(QString nm){nom=nm;}
    void setdate_limite(QString dt){dateLimite=dt;}
    void setnbre_pieces(QString nb ){nbre_piece=nb;}
    void setprix_apyer(QString pr){prix_apayer=pr;}
    void setpieces_demand(QString pc){piece_demandee=pc;}


    QString getCin(){return cin;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getdate_limite(){return dateLimite;}
    QString getnbre_pieces(){return nbre_piece;}
    QString getprix_apayer(){return prix_apayer;}
    QString getpieces_demand(){return piece_demandee;}

    bool ajouterFour();
    QSqlQueryModel *afficherFour();
    bool supprimerFour(QString cin);
    bool modifierFour(QString cin);


    QSqlQueryModel *trier(int test);



};

#endif // FOURNISSEUR_H
