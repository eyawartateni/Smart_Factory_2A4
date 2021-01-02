#include "arduino1.h"
#include <QDebug>
#include <QObject>


arduino1::arduino1()
{
  data="";
  arduino_port_name="";
  arduino_is_available=false;
  serial =new QSerialPort;
}

QString arduino1::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino1::getserial()
{
   return serial;

}


int arduino1::connect_arduino()
{

  foreach (const QSerialPortInfo &serial_port_info,QSerialPortInfo::availablePorts())
  {


    if(serial_port_info.hasVendorIdentifier()&& serial_port_info.hasProductIdentifier())
    {
        qDebug()<<serial_port_info.productIdentifier() ;

        if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()== arduino_uno_producy_id)
           {

              arduino_is_available=true;

              arduino_port_name=serial_port_info.portName();
           }

    }

  }

 qDebug() << "arduino_port_name is :"<<arduino_port_name;

 if (arduino_is_available)
 {
     serial->setPortName(arduino_port_name);

     if(serial->open(QSerialPort::ReadWrite))
     {

         serial->setBaudRate(QSerialPort::Baud9600);
         serial->setDataBits(QSerialPort::Data8);
         serial->setParity(QSerialPort::NoParity);
         serial->setStopBits(QSerialPort::OneStop);
         serial->setFlowControl(QSerialPort::NoFlowControl);


         return 0;
     }
    return 1;
 }
 return -1 ;

 }



 int arduino1::close_arduino()
 {

     if(serial->isOpen())
     {
         serial->close();
         return 0;
     }

     return 1;

 }

 QByteArray arduino1::read_from_arduino()
 {
  if (serial->isReadable()) {
   data=serial->readAll() ;

   /*if(serial->waitForReadyRead()&&serial->isReadable())
     {
         data=serial->readAll() ;
         QString temp=QString::fromStdString(data.toStdString()) ;

         qDebug() <<temp ;
         return data;
     }
     else
     {
         qDebug() <<"Couldn't read to serial!";


     }

*/
  }
   return  data ;
 }


 int arduino1::write_to_arduino(QByteArray d)
 {

     if(serial->isWritable())
     {
         serial->write(d);

     }

     else
     {
         qDebug() <<"Couldn't write to serial!";


     }

     return  0;
 }
 QSqlQueryModel * arduino1:: afficher()
 {

 QSqlQueryModel * model= new QSqlQueryModel();


 model->setQuery("select * from POINTAGE ");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 return  model ;
 }
 QSqlQueryModel * arduino1:: afficher2()
 {

 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select p.CIN,p.NOM,p.PRENOM,p.D,p.TIME from POINTAGE p ,TABLE1 t where t.CIN=p.CIN AND t.cin=:cin  ");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 return  model ;
 }








