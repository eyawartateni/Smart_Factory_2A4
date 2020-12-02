#include "connexion.h"



connexion::connexion()
{
 db = QSqlDatabase::addDatabase("QODBC");//attribus de la classe cnx
}

bool connexion::createconnect()
{bool test=false;
db.setDatabaseName("projet");//inserer le nom de la source de donnee
db.setUserName("mayssa");
db.setPassword("0000");

if (db.open())
test=true;

    return  test;
}

    void connexion::closeconnect()
    {
         db.close();
    }
