#ifndef MSERVER_H
#define MSERVER_H

#include <QtNetwork>
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>
#include "memoryblock.h"
#include "variables.h"

namespace Ui {
class mserver;
}

// para la administración de las variables y del manejo de la memoria
class mserver : public QTcpServer {
    Q_OBJECT

public:
    mserver(QObject * parent = 0 , quint16 port = 8888);
    virtual  ~mserver();
    void sendMessage(QString data);

private slots:
    void acceptConnection();
    void startRead();
    void disconnected();

public:

    //primera vez que se comunica el Cliente con el Servidor
    bool firstTime;

    //Punteros que referencian el Servidor y Cliente actual
    QTcpSocket * client;
    mserver *servidor;

    variables *vl;

};
#endif // MSERVER_H
