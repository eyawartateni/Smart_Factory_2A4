#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{
     QSqlDatabase db;
public:
    connexion();
    QSqlDatabase getDB(){return db;}
    void setDB(QSqlDatabase d){db=d;}
    bool createconnect();
    void closeconnect();
    ~connexion(){closeconnect();}

};

#endif // CONNEXION_H
