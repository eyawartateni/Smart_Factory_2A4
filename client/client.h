#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>




class Client
{
private:
    QString  cin, nom ,prenom,achat,paiement,model_choisi;
QString  date_naissance;
public:
    Client();
    Client(QString,QString,QString,QString,QString,QString,QString);
    void setCin(QString c){cin=c;}
    void setPrenom(QString pr){prenom=pr;}
    void setnom(QString nm){nom=nm;}
    void setdate_naissance(QString dt){date_naissance=dt;}
    void setpaiement(QString pay){paiement=pay;}
    void setachat(QString ach){achat=ach;}
    void setModelChoisi(QString mdl){model_choisi=mdl;}



    QString getCin(){return cin;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getdate_naissance(){return date_naissance;}
    QString getpaiement(){return paiement;}
    QString getachat(){return achat;}
    QString getModelChoisi(){return model_choisi;}
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(QString cin);
    bool modifier(QString cin);
    bool exporterpdf();




};

#endif // CLIENT_H
