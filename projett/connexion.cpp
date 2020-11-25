#include "connexion.h"

//test tutoriel git
connexion::connexion()
{
 db = QSqlDatabase::addDatabase("QODBC");
}

bool connexion::createconnect()
{bool test=false;
db.setDatabaseName("projet");
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
