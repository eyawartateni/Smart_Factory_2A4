#include "messenger.h"
namespace DurateCoporation {
Messenger::Messenger(qintptr handle,QObject *parent)
          :QTcpSocket(parent)
{
setSocketDescriptor(handle);
connect(this,&Messenger::readyRead,[&](){
    emit DuReadyRead(this);
});
connect(this,&Messenger::stateChanged,[&](int S){
  emit DuStateChanged(this,S);
});
}
}
