#ifndef MESSENGER_SERVER_H
#define MESSENGER_SERVER_H
#include<QTcpServer>
namespace DurateCoporation {
class Messenger;
class Messenger_Server : public QTcpServer
{
     Q_OBJECT
public:
    Messenger_Server(QObject *parent= nullptr);
bool startServer( quint16 port);
protected:
   void incomingConnection(qintptr handle);
private:
    QList<Messenger *>mSockets;
};
}
#endif // MESSENGER_SERVER_H
