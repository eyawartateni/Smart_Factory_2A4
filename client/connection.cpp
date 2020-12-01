#include "connection.h"
//test tutoriel git
//testttttt
connection::connection()
{
db = QSqlDatabase::addDatabase("QODBC");  //initialisation du db qui établie la connexion
}

bool connection::createconnect()
{bool test=false;

db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void connection::closeconnection()
{
    db.close();

}
