#ifndef CPARKING_H
#define CPARKING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Cparking
{
    QString nom;
    int reference,place;
public:
    Cparking();
    Cparking(int,int,QString);


    int getreference(){return reference;}
    int getplace(){return place;}
    QString getnom(){return nom;}

    void setreference(int Reference){reference=Reference;}
    void setplace(int Place){place=Place;}
    void setnom(QString Nom){nom=Nom;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int reference);
};

#endif // CPARKING_H
