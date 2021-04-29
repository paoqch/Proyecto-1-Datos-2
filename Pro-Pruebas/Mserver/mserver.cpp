//#include "ui_mserver.h"
#include "logger.h"
#include "mserver.h"
#include <iostream>
#include "node.h"
#include "memoryblock.h"
#include "variables.h"
#include <string>
using namespace std;

logger *l1 = new logger();

/**
 * @brief mserver::mserver
 * @param parent
 * @param port
 * Encargada de la administración de las variables y del manejo de la memoria. Se comunica con la clase Client.
 */
mserver::mserver(QObject* parent , quint16 port): QTcpServer(parent){
    vl = new variables();

    firstTime = true;
    if(!servidor){
        servidor = this;
    }
  connect(this, SIGNAL(newConnection()),this, SLOT(acceptConnection()));

  if (!this->listen(QHostAddress::Any, port)){
          qDebug() << "ERROR PORT IS IN USE";
  }
}

mserver::~mserver()
{
    delete client;
    close();
}


/**
 * @brief mserver::acceptConnection
 * Inicia la comunicación con algún cliente que la esté solicitando
 */
void mserver::acceptConnection()
{
  client = nextPendingConnection();

  connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
  connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));

  qDebug() << "Se ha conectado el cliente";
}

/**
 * @brief mserver::startRead
 * Lee la información en JSON enviada por el cliente.
 */
void mserver::startRead(){
    while(client->canReadLine()){
        QString line = QString::fromUtf8(client->readAll().trimmed());
        cout << "Client :\n" << line.toUtf8().constData() << endl;

        if (firstTime == true){
            sendMessage(QString("Conexion establecida con el servidor"));
            firstTime = false;
         }

        else{
            QJsonObject obj;
            QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8());
            obj = doc.object();

            QString finalValue = vl->preparation(obj);

            QString qstr;

            QJsonObject* jobj = new QJsonObject();
            QJsonValue* jstring1 = new QJsonValue(obj.value("Variable").toString());
            QJsonValue* jstring2 = new QJsonValue(finalValue);

            QJsonValue* jstring3 = new QJsonValue(qstr);
            jobj->insert("Label",jstring1->toString());
            jobj->insert("Value",jstring2->toString());
            jobj->insert("Address",jstring3->toString());
            QJsonDocument doc2(*jobj);
            QByteArray bytes = doc2.toJson();
            const char* charString = bytes.data();
            string json(charString);
            QString message = json.c_str();
            cout << jstring1;
            cout << jstring2;
            qDebug() << message;
            sendMessage(message);
            break;
        }
    }
}

/**
 * @brief mserver::sendMessage
 * @param data
 * Envía la información data, que contiene los resultados de la administración de memoria
 */
void mserver::sendMessage(QString data){
    client->write(QString(data+"\n").toUtf8());
    client->waitForBytesWritten(1000);
}

/**
 * @brief mserver::disconnected
 * Notifica cuando el Cliente actual pierde la comunicación
 */
void mserver::disconnected()
{
    qDebug() << "Se ha desconectado el cliente";
}
