#ifndef VOITURE_H
#define VOITURE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include<QMessageBox>


class voiture
{
    QString marque , modele,type,options,couleur;
    int prix,prix_option,reference;
public:
    voiture();
    voiture(QString,int,QString,int,QString,int,QString,QString);
     void setCouleur(QString c)
    {
       couleur=c;
    }
    QString getCouleur()
    {
        return couleur;
    }
    void setReference(int r)
    {
       reference=r;
    }
    int getReference()
    {
        return reference;
    }
    void setMarque(QString m)
    {
        marque=m;
    }
    void setModele(QString mo)
    {
        modele=mo;
    }
    void setType_carburant(QString t)
    {
      type=t;
    }
    void setOption(QString o)
    {
      options=o;
    }
    void setPrix_option(int Po)
    {
      prix_option=Po;
    }
    void setPrix(int P)
    {
      prix=P;
    }
    QString getMarque()
    {
        return marque;
    }
    QString getModele()
    {
        return modele;
    }
    QString getType_carburant()
    {
        return type;
    }
    QString getOption()
    {
        return options;
    }
    int getPrix()
    {
        return prix;
    }
    int getPrix_option()
    {
        return prix_option;
    }
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
   bool modifier();
    QSqlQueryModel *recherche(QString REFERENCE,QString modele,QString marque);
    QSqlQueryModel * load();



};

#endif // VOITURE_H
