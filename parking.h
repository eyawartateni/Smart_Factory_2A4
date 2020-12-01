#ifndef PARKING_H
#define PARKING_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Parking
{
    QString nom , place;
    int reference;
public:
    Parking(){}
    Parking(int,QString,QString);

    int getreference(){return reference;}
    QString getplace(){return place;}
    QString getnom(){return nom;}

    void setreference(int Reference){reference=Reference;}
    void setplace(QString Place){place=Place;}
    void setnom(QString Nom){nom=Nom;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int reference);
    QSqlQueryModel * trier(int test);

};

#endif // PARKING_H
