#ifndef ARDUINO1_H
#define ARDUINO1_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>
#include<QSqlQueryModel>

class arduino1
{
public:
    arduino1();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort *getserial();
    QString getarduino_port_name();
    void Pointage() ;
    QSqlQueryModel * afficher() ;
    QSqlQueryModel * afficher2() ;


private:

QSerialPort * serial;

static const quint16 arduino_uno_vendor_id=6790;
static const quint16 arduino_uno_producy_id=29987;
QString arduino_port_name;
bool arduino_is_available;
QByteArray data;


};

#endif // ARDUINO1_H
