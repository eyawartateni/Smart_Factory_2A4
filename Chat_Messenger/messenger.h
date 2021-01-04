#ifndef MESSENGER_H
#define MESSENGER_H
#include <QTcpSocket>
namespace DurateCoporation {
class Messenger : public QTcpSocket
{
    Q_OBJECT
public:
    Messenger(qintptr handle,QObject *parent= nullptr);
signals:
    void DuReadyRead(Messenger *);
    void DuStateChanged(Messenger *,int);
};
}

#endif // MESSENGER_H
