#ifndef MESSENGERCONNECTIONDIALOG_H
#define MESSENGERCONNECTIONDIALOG_H

#include <QDialog>



class MessengerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
     MessengerConnectionDialog();
    ~MessengerConnectionDialog();
QString hostname() const;
quint16 port() const;
private slots:


private:

    QString mHostname;
    quint16 mPort;
public:
QString hostname()
{
    return mHostname;
}

 quint16 port()
{
    return mPort;
}
} ;

#endif // MESSENGERCONNECTIONDIALOG_H
