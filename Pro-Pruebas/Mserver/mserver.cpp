//#include "ui_mserver.h"
#include "logger.h"
#include "mserver.h"
#include <iostream>
#include "memory.h"
#include <string>
using namespace std;

logger *l1 = new logger();

mserver::mserver(QObject* parent , quint16 port): QTcpServer(parent){
    firstTime = true;
    if(!servidor){
        servidor = this;
    }
  connect(this, SIGNAL(newConnection()),this, SLOT(acceptConnection()));

  if (!this->listen(QHostAddress::Any, port)){
          qDebug() << "ERROR";
  }
}

mserver::~mserver()
{
    delete client;
    close();
}


// Inicia la comunicación con algún cliente que la esté solicitando
void mserver::acceptConnection()
{
  client = nextPendingConnection();

  //connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
  connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));

  qDebug() << "Se ha conectado el cliente";
}


//Envía la información data, que contiene los resultados de la administración de memoria
void mserver::sendMessage(QString data){
    client->write(QString(data+"\n").toUtf8());
    client->waitForBytesWritten(1000);
}

//Notifica cuando el Cliente actual pierde la comunicación
void mserver::disconnected()
{
    qDebug() << "Se ha desconectado el cliente";
}
