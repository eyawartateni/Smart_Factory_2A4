#include <QCoreApplication>
#include"messenger_server.h"

using namespace DurateCoporation;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
Messenger_Server Server;
if(!Server.startServer(33333))
{
   qDebug()<<"Error:" << Server.errorString();
   return 1;
}
qDebug()<<"server started.... ";
    return a.exec();
}
