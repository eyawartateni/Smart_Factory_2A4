#include "messenger_server.h"
#include"messenger.h"
#include<QDebug>
#include<QTextStream>
namespace DurateCoporation {
Messenger_Server::Messenger_Server(QObject *parent)
                 :QTcpServer(parent)
{

}

bool Messenger_Server::startServer(quint16 port)
{
  return listen(QHostAddress::Any,port);
}

void Messenger_Server::incomingConnection(qintptr handle)
{
    qDebug() << "client connected with handle:"<<handle;
    auto socket = new Messenger(handle,this);
    mSockets << socket;
    for(auto i:mSockets) {
        QTextStream T(i);
       // T<<"Server :Connected:"<<handle;
       i->flush();

    }
    connect(socket, &Messenger::DuReadyRead,[&](Messenger *S){

        qDebug()<<"ReadyRead";
        QTextStream T(S);
       auto text =T.readAll();
       for(auto i:mSockets)
       {
           QTextStream K(i);
           K<<text;
       }
    });
    connect(socket,&Messenger::DuStateChanged,[&](Messenger *S,int ST)
    {
      qDebug()<<"StateChanged with handle"
         <<S->socketDescriptor();
      if(ST ==QTcpSocket::UnconnectedState) {
       qDebug()<<"Unconnected state with handle:"
              <<S->socketDescriptor();
          mSockets.removeOne(S);
          for(auto i: mSockets)
       {
           QTextStream K(i);
         //  K << " Server: El Cliente"<< S->socketDescriptor() <<" Disconnected....." ;
           i->flush();
       }
      }
    });
}
}
