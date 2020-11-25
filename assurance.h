#ifndef ASSURANCE_H
#define ASSURANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Assurance
{
    QString compagnie,type;
    int prix,reference;
public:
    Assurance(){}
    Assurance(QString,int,QString,int);


    QString getcompagnie(){return compagnie;}
    int getprix(){return prix;}
    QString gettype(){return type;}
    int getreference(){return reference;}

    void setcompagnie(QString Compagnie){compagnie=Compagnie;}
    void settype(QString Type){type=Type;}
    void setreference(int Reference){reference=Reference;}
    void setprix(int Prix){prix=Prix;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int reference);
};

#endif // ASSURANCE_H
