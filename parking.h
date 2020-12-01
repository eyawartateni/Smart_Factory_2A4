#ifndef PARKING_H
#define PARKING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Parking
{
    QString nom ;
    int reference, place;
public:
    Parking(){}
    Parking(int,int,QString);

    int getreference(){return reference;}
    int getplace(){return place;}
    QString getnom(){return nom;}

    void setreference(int Reference){reference=Reference;}
    void setplace(int Place){place=Place;}
    void setnom(QString Nom){nom=Nom;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int reference);
    QSqlQueryModel * trier(int test);

};

#endif // PARKING_H
