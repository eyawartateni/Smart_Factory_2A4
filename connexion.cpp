#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("mayssa");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur
if (db.open())
return true;

return  false;

}
void connexion::fermerConnexion()
{db.close();}
