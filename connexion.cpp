#include "connexion.h"

connexion::connexion()
{}

bool connexion::ouvrirConnexion()
{

db=QSqlDatabase::addDatabase("QODBC");

//youssef
/*
db.setDatabaseName("base");
db.setUserName("youssef1");//inserer nom de l'utilisateur
db.setPassword("56330407");//inserer mot de passe de cet utilisateur
*/

//rostom

db.setDatabaseName("source_de_donnes");
db.setUserName("Rostom");//inserer nom de l'utilisateur
db.setPassword("liverpool");//inserer mot de passe de cet utilisateur



//Mayssa
/*db.setDatabaseName("projet");
db.setUserName("mayssa");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur*/
//EYA(PICHOU)
/*db.setDatabaseName("Source_Projet2A");
db.setUserName("eya");
db.setPassword("esprit18");*/
if (db.open())
return true;

return  false;

}
void connexion::fermerConnexion()
{db.close();}
