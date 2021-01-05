#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>




class Client
{
private:
    QString  cin, nom ,prenom,achat,paiement,model_choisi;
QDate  date_naissance;

public:
    Client();
    Client(QString,QString,QString,QString,QString,QString,QDate);
    void setCin(QString c){cin=c;}
    void setPrenom(QString pr){prenom=pr;}
    void setnom(QString nm){nom=nm;}
    void setdate_naissance(QDate dt){date_naissance=dt;}
    void setpaiement(QString pay){paiement=pay;}
    void setachat(QString ach){achat=ach;}
    void setModelChoisi(QString mdl){model_choisi=mdl;}



    QString getCin(){return cin;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QDate getdate_naissance(){return date_naissance;}
    QString getpaiement(){return paiement;}
    QString getachat(){return achat;}
    QString getModelChoisi(){return model_choisi;}
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString cin);
    bool modifier(QString cin,QString prenom,QString  nom ,QString model,QString achat,QString paiement , QDate date_n  );
    bool exporterpdf();
    QSqlRelationalTableModel *chercherclient();
    QSqlRelationalTableModel *modClient;
    QSortFilterProxyModel * proxyclient;
    QSqlQueryModel  *rechercherclient(QString CIN,QString NOM,QString PRENOM);



};

#endif // CLIENT_H
